/*
    职业模块示例 2016.4.4
*/

/*
    IreCore的层次结构
    IreCore2将界面与模拟器分开。
    完成模拟功能的组件是libic，作为静态链接库独立存在。
    界面部分ic提供了文本和图形界面，负责和用户交互。
    libic本身可以分成前端和后端。libic采用OpenCL计算标准，前端即主控端（Host），后端即设备端（Device）。
    前端和正常程序一样运行在CPU上，后端可以指派为多种硬件，CPU/GPU/MIC...
    前端负责把模拟参数转换成后端源码，将源码拼接完整后，交给OpenCL进行即时编译（JIT）编译出运行在指定设备上的后端程序，然后由指定设备执行程序进行模拟。
    开发职业模块就是要开发后端源码当中描述职业机制的片段。

    后端源码框架
    kernel.c和entry.c是所有职业共用的部分，kernel.c是后端代码的开头部分，entry.c是后端代码的结尾部分。
    前端在进行源码拼接时，会遵循以下顺序：

        // 预定义，这里将前端的选项设置通过宏的方式设置给后端
        #define CLASS_WARRIOR
        #define SPEC_ARMS
        #define TALENT_TIER1 3
        ...
        // 这里插入kernel.c

        // 这里插入职业模块
        // 这里插入专精模块

        // 这里插入entry.c

        // 这里插入APL
        void scan_apl( rtinfo_t* rti ) {
            ...
        }

    职业专精模块检查宏的定义与否或定义值就可以获得前端的选项，具此提供不同的代码。

    语言
    OpenCL C语言是基于C99标准，再添加额外限制得到的。
    C99与主流教育采用的ANSI C的几点主要区别：
        * 声明和语句可以混合（ANSI当中要求必须声明在前，语句在后）
            int abc; // 这是一个声明
            abc = 1; // 这是一个语句
            int def; // 在ANSI当中不允许在语句后出现声明，C99允许
        * 允许C++式的在for语句当中声明迭代器
            int i; for ( i = 0; i < 10; i++ ) {} // ANSI/C99
            for ( int i = 0; i < 10; i++ ) {}    // C99 only
        * 带签名的初始化列
            struct foo_t {
                int a;
                int b;
            } foo = { 10, 20 };           // ANSI/C99
            } foo = { .a = 10, .b = 20 }; // C99 only
        * 复合常量(compound literals)
            foo = (struct foo_t){ 10, 20 }; // C99能够这样直接写出结构体/数组类型的常量
            bar = (int [3]){ 1, 2, 3 };     // 一个数组常量的例子
        * 还有其他一些在我们这不让用的新特性。
    OpenCL C附加的限制主要有：
        * 没有库，没有标准头文件，没有动态分配的内存
            #include <stdio.h>     // 这里没有这种东西
            int* p = malloc(12);   // "malloc" 没有定义，所以无法使用动态分配的内存
            int  c = 4 * CHAR_BIT; // "CHAR_BIT" 没有定义
          OpenCL会提供一些自己的内建函数代替标准库，主要是数学函数，比如sin/cos什么的。
          具体参考OpenCL标准文档。
        * 禁止全局变量，只有附加__constant修饰符的常量能够存在于全局空间当中
            __constant int foo[] = { 1, 2, 3 }; // 允许。foo存放于常量内存里，不能修改。
            int foo[] = { 4, 5, 6 };            // 不允许任何形式的全局变量。
        * 禁止extern和static
            foo_t* singleton_foo() {    // 想用单例代替全局变量？
                static foo_t f;         // 没门。
                return &f;
            }
            extern __constant double coeff; // 想只给声明稍后再给初始值？没门。
        * 禁止变参函数/变参宏
            int my_printf( const char* fmt, ... ); // 参数数量必须确定
        * 禁止函数指针，禁止递归
          下面的代码会是C语言当中处理事件的绝妙方式，但是它必须基于函数指针来实现
          所以我们用不了这种方式
            struct event_t {
                int value;
                int( * callback )( int arg ); //声明函数指针？
            };
            int routine1( int arg ) { return arg + 1; }
            int routine2( int arg ) { return arg ? routine2( arg - 1 ) : arg; } // 递归？
            int process_event( event_t e ) {
                return ( *e.callback )( e.value ); // 调用函数指针？
            }
            void my_event_implement( void ) {
                event_t e1 = { 10, &routine1 }; // 取函数指针？
                event_t e2 = { 20, &routine2 };
                process_event( e1 );
                process_event( e2 );
            }
          因为OpenCL将会执行在多种设备上，不只是CPU，然而在许多其他设备当中根本就不存在栈、函数调用等等这些概念。
          实际上在这些设备当中，所有函数都将是内联（inline）的。比如
            int routine( int arg ) { return arg + 1; }
            __kernel void entry( void ) {
                int a = routine( 1 );
                int b = routine( a );
            }
          会被这些设备看作
            a = 1 + 1;
            b = a + 1;
          如果用到递归或函数指针，这些设备将根本无法实现。有递归就无法内联，有函数指针就无法在编译期确定如何内联。
        * 限制使用双精度浮点数double，通常用float代替。
          许多设备根本没有双精度浮点数运算部件，所以要启用double，需要添加额外的声明，以至于程序无法在这些设备上执行。
    为保持代码的移植能力，我们只使用OpenCL 1.0/1.1当中提供的特性。
    
    框架
    框架kernel.c提供了模拟的最基本的框架。
    首先是一致的编译环境。在框架的支持下，后端代码可以由普通编译器作为普通C语言程序编译，也可以由前端作为OpenCL程序编译。
    能够作为普通C语言程序编译很重要，在这种环境下我们可以检查语法错误，检查参数设置，检查内存使用情况，检查队列空间使用情况，以至于打印战斗日志检查机制是否如预期工作，等等。
    首先能通过C语言编译，参数正常，战斗日志符合预期，没有出现断言失败，这是职业模块Debug的第一步，能够过滤掉绝大多数Bug。
    test.c是用来进行C语言编译的测试程序。提供了main函数，并且模仿前端的代码拼接。测试时根据需要修改test.c的内容然后编译它。
    为使两种编译环境中代码含义保持一致，框架要求你将整数变量类型声明为统一后的类型名：
        k32u
        | ||
        | |--符号位，s为有符号，u为无符号
        | --该类型的比特数量
        --表示"kernel"，固定为k

    框架提供了一套Debug工具，其中最重要的是lprintf
        void lprintf( ( const char* fmt, ... ) )
    它的用法与C语言当中的printf相同，但注意要打两重括号。
    在OpenCL编译中lprintf会被忽略，在C编译中lprintf将会打印一条信息到战斗日志中
    输出格式为"时间戳+打印内容+换行"，例：
        lprintf( ( "deal damage %d", dmg ) ); // 05:36.420 deal damage 1635
        lprintf( ( "another log" ) );         // 05:36.420 another log
    
    由于不允许全局变量的存在，我们需要一个名为rti的参数，存储所有全局状态信息，作为参数在所有函数之间传递。rti在入口函数处建立并初始化为零。
    rti包含下面这些信息：
        rti->timestamp              -- 模拟的当前时间，time_t
        rti->seed                   -- RNG种子
        rti->eq                     -- 事件队列
        rti->damage_collected       -- 已统计到的伤害总量
        rti->player                 -- 角色状态信息
        rti->enemy[]                -- 目标状态信息（DoT/负面效果）
        rti->expected_combat_length -- 预期战斗时长，rti->timestamp达到这个值时，模拟将结束
    你的函数的调用者会给你提供一个rti。你调用的函数要求你提供rtinfo_t*类型的参数时，直接将rti传递给它既可。

    时间是模拟器当中最重要的一个点，我们对时间的处理方式是我们优越于SimC的主要原因。但是这一套时间处理方式需要开发者时刻保持谨慎，因为稍有疏忽就会导致预期外的情况发生。
    框架定义了时间戳time_t类型，它就是k32u的别名。目前，1000time_t为1秒，1time_t为1毫秒，但这个缩放尺度随时可能被修改，所以你不应该建立在这一假设上写代码。
    框架提供了处理时间的宏，这些宏会替你考虑符号、溢出、饱和处理、取整规则等等事情，使用它们处理时间是安全的。
        time_t FROM_SECONDS( float sec )       -- 将秒转型为time_t
        time_t FROM_MILLISECONDS( float msec ) -- 将毫秒转型为time_t
        float  TO_SECONDS( time_t time )       -- 将time_t转型为秒
        time_t TIME_OFFSET( time_t time )      -- 从当前时刻为起点，向未来移动time时间，得到该时刻的时间戳
                                                    只能向未来移动，任何尝试向过去移动的行为都是UB（未定义行为）
        time_t TIME_DISTANT( time_t time )     -- 从当前时刻为起点，到time时间戳表达的时刻，得到两时刻之间的间隔
                                                    如果time在过去，则返回0
        bool   UP( time_t time )               -- 判定time表达的时间（假想time是一个Buff结束的时刻）是否过期
                                                    当time与当前时刻相等时，返回否
        time_t REMAIN( time_t time )           -- 同TIME_DISTANT
    我们默许但不提倡直接对time_t进行运算。进行此类运算乃Bug之源，你必须保持十二分谨慎。
    例如A技能的冷却为60秒，但在B条件下会缩短10秒的冷却，但框架没有提供将时间戳向过去移动的工具，你必须使用运算实现。
        DECL_EVENT( cond_b_triggered ) {    
            spell_a_cd -= FROM_SECONDS( 10 );
        }
    停！这样就中招了！假如A技能在模拟的一开始就使用了，此时spell_a_cd为FROM_SECONDS(60)，冷却的期间连续触发了六次B条件，很可能直接将spell_a_cd减成负数，下溢……
    那意味着spell_a_cd的值会变成类似于4294966296这样大的数字，UP(spell_a_cd)将在这场战斗中永远为真，这个技能会被锁死直到战斗结束。
        DECL_EVENT( cond_b_triggered ) {
            time_t reduction = min( spell_a_cd, FROM_SECONDS( 10 ) );
            spell_a_cd -= reduction;
        }
    首先检查是否会导致下溢，才是明智的选择。

    框架提供了模拟核心算法，然后提供了少量的全职业都会用到的工具。提供得不多，许多机制需要你自己实现。
    核心算法是一个事件队列。你可以调用eq_enqueue来向事件队列当中插入一个事件。
        eq_enqueue( rtinfo_t* rti, time_t time, k32u routine_number, k32u target )
    这样在time时刻预约一个事件，事件处理程序的编号为routine_number，附带一个额外信息target。
    target一般用作指明动作的目标，但如果你还需传递其他额外信息的话，也得借助这个值来进行，因为事件队列不会再记录其他值了。
    插入的事件如果有问题会被丢弃。有问题一般都是时间问题，比如事件插入在了过去时刻。除此之外，插入在模拟结束之前的事件，一定会得到执行，这是无法阻止的。
    事件在插入后就丢失了索引，你无法再找到它，你只知道到时间后它一定会执行。
    （我把用来删除事件的函数阉割掉了，因为失去索引，你根本不知道删掉的是不是你想要删的那个事件。）
    这样带来了一点小麻烦。比如上一个例子当中，冷却缩减，而我想在冷却结束时刻引发一个事件的话：
        0秒时释放了技能A，在60秒处插入了一个冷却结束事件
        10秒时条件B触发了，技能A的冷却结束时刻变为50秒处，在50秒处插入了一个新的冷却结束事件
    糟了，插入的事件一定会得到执行，所以这次技能A将会有两个冷却结束事件与之对应……由于无法索引到事件进行删除，这种过期的空悬事件是无法避免的。
    所以你需要在事件的执行程序当中检查它是否已经失效成为空悬事件。例如检查spell_a_cd的值是否和rti->timestamp相等，这是一种开销很低但能检出大多数空悬的方法，
    不过如果你在同一时刻插入了多个相同的事件，它们都能够通过这一检查。如果空悬事件对你的模型有害，你要小心避免这种情况。
    在反复插入同一个事件的时候，特别注意一下空悬事件的问题，让空悬的事件能够在运行时自检并失效。
    事件队列的容量是有限的，如果待执行的事件过多，超过了事件队列的容量，会导致UB。过多的事件也会损失性能。所以如果能在插入时就减少空悬事件的话，就劳烦少插入几个吧。

    算法
    IreCore的模拟算法这样运行：
        1. 将当前时刻归零。在结束时刻插入一个END_OF_SIMULATION事件。
        2. 判段事件队列中下一个事件发生时刻。
            2a. 如果仍在当前时刻则什么也不做；
            2b. 如果在未来，则执行APL。（这可能会向事件队列中插入新的事件，所以“下一个事件”可能会因此变化。）
        3. 将当前时间跳转到下一个事件的发生时刻，执行下一个事件。
        4. 重复2~3，直到3执行的是END_OF_SIMULATION则结束模拟。
    用一个例子来演示算法，假设角色职业是布林顿，会一个技能叫做“打脸”。打脸有1秒冷却。
    APL是如果能打脸则打脸。战斗持续3秒。
        执行步骤          当前时刻       事件队列
        1.              | 0         |   3-EOS
          初始时事件队列里只有EOS（END_OF_SIMULATION简写），当前时刻为0。
        2.              | 0         |   3-EOS
          下一个事件是EOS，时刻是3，在未来。执行2b.
        2b.             | 0         |   0-STEX, 1-STCD, 3-EOS
          APL告诉我们能打脸则打脸，于是执行打脸，这个动作插入了新事件“释放打脸（STEX）”和“打脸冷却（STCD）”。
        3.              | 0         |   1-STCD, 3-EOS
          执行了下一个事件，即STEX。时间跳转到0。然后重复回到2.
        2.              | 0         |   1-STCD, 3-EOS
          下一个事件是STCD，时刻是1，在未来。执行2b.
        2b.             | 0         |   1-STCD, 3-EOS
          此时打脸已进入冷却，不能打脸，所以没有动作执行。没有新的事件插入进来。
        3.              | 1         |   3-EOS
          执行了下一个事件，即STCD。时间跳转到1。然后重复回到2.
        2.              | 1         |   3-EOS
          下一个事件是EOS，时刻是3，在未来。执行2b.
        2b.             | 1         |   1-STEX, 2-STCD, 3-EOS
          APL告诉我们能打脸则打脸，于是执行打脸，这个动作插入了新事件“释放打脸（STEX）”和“打脸冷却（STCD）”。
        3.              | 1         |   2-STCD, 3-EOS
          执行了下一个事件，即STEX。时间跳转到1。然后重复回到2.
        2.              | 1         |   2-STCD, 3-EOS
          下一个事件是STCD，时刻是1，在未来。执行2b.
        2b.             | 1         |   2-STCD, 3-EOS
          此时打脸已进入冷却，不能打脸，所以没有动作执行。没有新的事件插入进来。
        3.              | 2         |   3-EOS
          执行了下一个事件，即STCD。时间跳转到2。然后重复回到2.
        2.              | 2         |   3-EOS
          下一个事件是EOS，时刻是3，在未来。执行2b.
        2b.             | 2         |   2-STEX, 3-STCD, 3-EOS
          APL告诉我们能打脸则打脸，于是执行打脸，这个动作插入了新事件“释放打脸（STEX）”和“打脸冷却（STCD）”。
        3.              | 2         |   3-STCD, 3-EOS
          执行了下一个事件，即STEX。时间跳转到2。然后重复回到2.
        2.              | 2         |   3-STCD, 3-EOS
          下一个事件是STCD，时刻是3，在未来。执行2b.
        2b.             | 2         |   3-STCD, 3-EOS
          此时打脸已进入冷却，不能打脸，所以没有动作执行。没有新的事件插入进来。
        3.              | 3         |   3-EOS
          执行了下一个事件，即STCD。时间跳转到3。然后重复回到2.
        2.              | 3         |   3-EOS
          下一个事件是EOS，时刻是3，在当前时刻。执行2a.
        2a.             | 3         |   3-EOS
          2a.什么也不做
        3.              | 3         |   （空）
          执行了下一个事件，即EOS。执行到EOS，模拟就此结束。
    这个模拟算法非常高效，因为每次时间跳转都是精确地跳转到下一次需要处理的位置，不多也不少。
    也保证了每一个有事件发生的时刻，都反复执行APL，直到APL中没有动作可用，才开始处理下一个时刻。
    这个算法假设了你的模型当中所有状态量的变化都是由事件引起的。相邻两事件之间的时间段内，状态保持不变。
    不过也有些职业机制会有例外，最典型的如被动能量恢复，即使没有事件发生，能量也会增长，就会破坏掉算法的假设，带来一些问题。
    目前实验表明这些问题通常不会造成实际的影响，只会影响一些极端情况。如果有问题暴露出来，我们会有额外的处理方法，到时再加以修正。

    价值观
    IreCore是为提供高性能模拟而存在的，所以在完成机制后仍有余力的情况下，还要调整一下性能。
    * 减少事件。在保证机制准确的情况下，减少不必要的事件。
    * 用32位数，非有必要，尽量少用8位和16位。
      许多设备很难按字节寻址，它们需要移位、拼接之类的机制来拟合字节寻址，速度会很慢。
    * 减少内存的使用量！不必计较一个字节，但要计较每一个k32u。
      使用的内存越多，在GPU上的执行效率就越低。还是有许多用户需要执行在GPU上的，要做好权衡。
*/

/************************** 这里开始一个职业模块范例 ***********************************************/

#ifdef SPEC_LIL             // 前端给出的宏定义是 #define SPEC_XXX 这种形式
#undef SPEC_LIL             // 你可以undef它们，
#undef SPEC_ANOTHER_SPEC
#define SPEC_LIL 1          // 然后转换成你喜欢的形式，比如 #define SPEC_XXX 1
#define SPEC_ANOTHER_SPEC 0 // 这样你就可以直接在代码里写 if (SPEC_XXX)这样的东西了，显然更方便一些。
#else
#undef SPEC_LIL
#undef SPEC_ANOTHER_SPEC
#define SPEC_LIL 0
#define SPEC_ANOTHER_SPEC 1
#endif

#define TALENT_ROCKET  (SPEC_LIL && TALENT_TIER1 == 1)              // 将所有天赋是否启用的判别式都定义成宏
#define TALENT_PLATING (SPEC_ANOTHER_SPEC && TALENT_TIER1 == 1)     // 前端给出的宏定义是 #define TALENT_TIER1 2 这种形式，TIER后面的数字是层数，定义值是选择，0为留白，123分别为左中右 
#define TALENT_GIFT    (TALENT_TIER1 == 2)                          // 有些天赋会随专精切换而变化，有些则不会
#define TALENT_BSOD    (TALENT_TIER1 == 3)                          // 这些不变化的天赋的模型一般写在职业模块里，反之则写在专精模块里

struct class_state_t{   // struct class_state_t 是存储着职业相关状态信息的结构体类型。这个类型是框架要求你必须定义的。
    int placeholder;    // 第一个成员为ph，它有两个作用：确保你的结构体至少包含一个成员，确保你的结构体的第一个成员是整数类型（供entry初始化之便）。
                        // 如果你已经能够确保这两点，那么也可以省略掉ph。ph没有实际作用，我们也不允许在代码的其他位置引用ph。
    
    struct {            // 用结构体来定义模型中的状态量，可以更好地整理它们。
        time_t cd;      // 冷却一般叫做cd。它保存着冷却时间结束时刻的时间戳。
        time_t expire;  // 持续时间一般叫做expire。它保存着持续时间结束时刻的时间戳。
        k32u stack;     // 堆叠层数一般叫做stack。你应该确保当效果消失时，stack的值一直是0。
                        // 你还可以根据需要加入各种状态量：charge、maxcharge、tick_interval……
    } smackthat;        // 将这些状态量整理到一个技能的名下。
    #define smackthat_cd (rti->player.class->smackthat.cd) // 从rti一路索引到这些状态量，长度太长了，我们可以用宏使它们缩短一些。
    #define smackthat_expire (rti->player.class->smackthat.expire)  // 定义这些宏也能让APL的书写更简洁一些。
    #define smackthat_stack (rti->player.class->smackthat.stack)

#if (TALENT_BSOD)       // 天赋相关的状态量，只有当天赋启用的时候才加入到结构体中。这样节约内存，也节约编译时间。
    struct {
        time_t cd;
    } bsod;
    #define bsod_cd (rti->player.class->bsod.cd) 
#else
    #define bsod_cd (0) // 如果没有启用天赋，也允许通过这个宏来查询值，但总是得到0。
#endif

};

struct class_debuff_t { // struct class_debuff_t 也是框架要求必须定义的，它存储每个目标身上你职业相关状态信息。
    int placeholder;    // ph同理。

    struct {
        time_t expire;
    } inflation;
    #define inflation_expire(target) (rti->enemy[target].class->inflation.expire)  // 目标上的状态与目标有关，所以这里的简写宏都会留下一个target参数。

};

// 能量处理函数，每个职业都有自己的能量值。
// 框架并不要求必须有这些，但通常你需要有。
// 这里提供了最基本的模板，你的职业的能量可能还有特殊机制，则需要在此基础上另行实现。
void power_gain( rtinfo_t* rti, float power ) {     // 获取能量。
    rti->player.power = min( power_max, rti->player.power + power );
}
kbool power_check( rtinfo_t* rti, float cost ) {    // 检测能量是否达到cost。
    if ( cost <= rti->player.power ) return 1;
    return 0;
}
void power_consume( rtinfo_t* rti, float cost ) {   // 消耗能量。
    assert( power_check( rti, cost ) );
    rti->player.power -= cost;
}

// 属性处理函数。
// 框架并不要求必须有这些，但通常你需要有。
// rti->player.stat结构体当中既保存了装备属性（gear_xxx），又保存了Buff后面板属性（xxx）。
// 处理函数是根据装备属性计算面板属性的函数。在触发效果开始或结束改变了装备属性时，调用此函数更新面板属性。
void refresh_str( rtinfo_t* rti ) {
    float fstr = ( float )rti->player.stat.gear_str;
    k32u str;
    float coeff = 1.0f;
    if ( PLATE_SPECIALIZATION ) coeff *= 1.05f;
    #if (archmages_incandescence || archmages_greater_incandescence)
    if ( UP( incandescence_expire ) ) coeff *= archmages_greater_incandescence ? 1.15f : 1.1f;
    #endif
    str = convert_uint_rtz( fstr * coeff ); // 注意白色力量是向零取整。
    fstr = 1455; /* Base str @lvl 100. */   // 这个值可能随职业不同而变化！
    fstr += racial_base_str[RACE]; /* Racial str. */
    str += convert_uint_rtz( fstr * coeff ); // 绿色力量也向零取整。两部分分别取整后相加得到面板力量。
    rti->player.stat.str = str;
}

float spec_mastery_coefficient( rtinfo_t* rti ); // 有时不同专精对属性的处理会不太一致，比如精通的系数不同专精是不一样的。此时可以搞“多态”来处理。
float spec_mastery_increament( rtinfo_t* rti );  // C语言也能搞多态？非常简单，就这么搞。这两个函数在此声明，但在专精模块里给出实现。
                                                 // 加载不同的专精模块的时候，这两个函数的具体实现就不同了，实现了类似OOP当中虚函数的作用。
void refresh_mastery( rtinfo_t* rti ) {
    float mastery = ( float )rti->player.stat.gear_mastery;
    #if (bleedinghollow_mh)
    if ( UP( rti->player.class->enchant_mh.expire ) ) mastery += 500.0f;
    #endif
    #if (bleedinghollow_oh)
    if ( UP( rti->player.class->enchant_oh.expire ) ) mastery += 500.0f;
    #endif
    mastery = spec_mastery_coefficient( rti ) * ( 0.08f + mastery / 11000 ) + spec_mastery_increament( rti ); // 这样公式就会随专精不同而不同了。
    rti->player.stat.mastery = mastery;
}

// 武器伤害和AP伤害，只声明，具体实现抛给专精模块
float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ); 
float ap_dmg( rtinfo_t* rti, float ap_multiplier );
// 攻击类型和伤害类型的分类，具体需要如何分类看职业需要。
enum {
    ATYPE_WHITE_MELEE, // 近战肉搏
    ATYPE_YELLOW_MELEE, // 近战技能
    ATYPE_SPELL, // 法术
    DTYPE_DIRECT, // 直接伤害
    DTYPE_PHYSICAL, // 物理伤害
    DTYPE_SHADOW, // 暗影伤害
    DTYPE_FIRE,  // 火焰伤害
};
// 掷骰结果分类
// 现在偏斜、碾压、躲闪、招架等等通常都不会出现了，所以只处理这三种情况。
enum {
    DICE_MISS, // 未命中
    DICE_CRIT, // 爆击
    DICE_HIT, // 命中
};
void special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ); // 触发效果挂钩，这里只声明，稍后给出实现
k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ); // 圆桌掷骰，由专精模块给出实现
float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor ); // 造成伤害，由专精模块给出实现

/*
    这里开始要编写事件系统了！有些宏需要定义，帮我们减轻负担。
*/
/*
    DECL_EVENT： 声明一个事件。用例：
    DECL_EVENT( smackthat_cast ) {
        ...
    }
    展开后相当于：
    void event_smackthat_cast ( rtinfo_t* rti, k32u target_id ) {
        ...
    }
    这个函数处理编号为routnum_smackthat_cast的事件。当此事件发生时，模拟器调用该函数。
    还记得eq_enqueue时提供的target参数么？这个参数会被传递到target_id这里。
*/
#define DECL_EVENT( name ) void event_##name ( rtinfo_t* rti, k32u target_id )
/*
    HOOK_EVENT： 挂钩一个事件。
    将routnum_smackthat_cast和event_smackthat_cast联系起来。在后面的事件入口处使用，这里先放下不谈。
*/
#define HOOK_EVENT( name ) case routnum_##name: event_##name( rti, e.target_id ); break;
/*
    DECL_SPELL： 声明一个技能。用例：
    DECL_SPELL( smackthat ) {
        ...
    }
    展开后相当于：
    int spell_smackthat ( rtinfo_t* rti ) {
        ...
    }
    这个函数用于释放smackthat技能，当APL指明要执行smackthat时，会调用该函数。
    这个函数需要完成下面几个事情：
        * 检查技能释放的条件是否满足，不满足则返回值0。否则继续进行。
        * 触发冷却，触发公共冷却，消耗能量，消耗Buff……将释放技能需要拿走的东西全都拿走。
        * 插入事件。
        * 返回值1，表示这个技能成功执行了。
*/
#define DECL_SPELL( name ) int spell_##name ( rtinfo_t* rti )
/*
    SPELL： 用于APL当中，表示释放技能。
    IreCore的APL是非坠落性APL，即每一次扫描APL项，成功释放一个技能后，就立即返回。不再尝试寻找优先级更低的项是否能同时释放。
    这样配合核心算法可以达到更高的效率，核心算法会确保反复扫描APL直到没有动作，再让时刻向后移动。
*/
#define SPELL( name ) safemacro(if(spell_##name ( rti )) return;)

// 事件编号列表。每个事件需要一个对应的事件编号。
enum {
    routnum_gcd_expire,
    routnum_smackthat_cast,
    routnum_smackthat_cd,
    routnum_smackthat_expire,
#if (TALENT_BSOD)       // 一些编号如果不需要，则不要占坑了，用预处理消灭它们。
    routnum_bsod_cast,
    routnum_bsod_cd,
#endif
    START_OF_SPEC_ROUTNUM, // 这个START_OF_SPEC_ROUTNUM可以帮助专精模块确定它的enum起始编号是多少。
};

// === General Cooldown ======================================================= // 看这个分界线是不是非常帅！方便找技能的实现位置。用insert键写这种线很方便。
void gcd_start ( rtinfo_t* rti, time_t length ) {                       // 启动GCD，专门弄一个函数减少后面的代码量。
    rti->player.gcd = TIME_OFFSET( max( length, FROM_SECONDS( 1 ) ) );  // GCD下限1秒
    eq_enqueue( rti, rti->player.gcd, routnum_gcd_expire, 0 );          // 挂钩gcd_expire事件。
}
DECL_EVENT( gcd_expire ) {  // gcd_expire事件的处理程序
    /* Do nothing. */       // 什么都不做，因为GCD结束这个事件只是UP( rti->player.gcd )从真变为假，不会导致任何状态发生额外的变化，不需要编码。
}                           // 但这个事件的存在是必要的，它让模拟器在这个时刻停留一下，于是处理器离开这个时刻时就会触发APL扫描，让角色在这一时刻执行动作。没有这个事件，就不会在这个时刻执行动作。
                            // 许多事件都没有实际编码，它们的作用都是让模拟器在事件发生的时刻暂时驻足而已。

// === smackthat ==============================================================
DECL_EVENT( smackthat_expire ) { // 虽然smackthat_expire被定义成了一个宏，但按照C语言标准，这里会先执行DECL_EVENT的展开，展开成event_smackthat_expire，然后就和smackthat_expire这个宏没有关系了。
    if ( smackthat_expire == rti->timestamp ) { // 空悬事件过滤，前面讲到了。
        smackthat_stack = 0;    // 堆叠层数一定要随着Buff过期而归零。
        lprintf( ( "smackthat expire" ) );      
    }
}
DECL_EVENT( smackthat_cd ) {       
    lprintf( ( "smackthat cd" ) );     // 这个事件不需要空悬事件过滤，只打印日志即可。
}
DECL_EVENT( smackthat_cast ) {
    float d = ap_dmg( rti, 0.6f );    // 计算AP伤害：0.6AP
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );  // 掷骰
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );   // 造成伤害
    lprintf( ( "smackthat main hit" ) );               // 打印一条日志

    for ( int i = 0; i < num_enemies; i++ ) { // AOE就是对每一个目标分别结算一遍伤害。
        float d = weapon_dmg( rti, 0.9f, 1, 0 );    // 每个目标计算一次武器伤害：90%，标准化武器伤害，主手武器
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );  // 每个目标分别掷骰
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );   // 造成伤害
        lprintf( ( "smackthat aoe hit @tar%d", i ) );               // 打印一条日志
    }

    smackthat_expire = TIME_OFFSET( FROM_SECONDS( 6 ) ); // 触发Buff：将buff过期时刻设置为6秒后。
    eq_enqueue( rti, smackthat_expire, routnum_smackthat_expire, 0 ); // 在buff过期时刻挂钩事件。由于Buff可能会刷新，这个事件可能会空悬，所以上面的处理程序里做了简单的空悬过滤。
    smackthat_stack = min( smackthat_stack + 1, 3 ); // 增加一层堆叠，最大3层堆叠。
}

DECL_SPELL( smackthat ) {
    // * DECL_SPELL要做的事情之一：检查条件
    if ( UP( rti->player.gcd ) ) return 0; // 检查GCD   
    if ( UP( smackthat_cd ) ) return 0;   // 检查冷却
    if ( !power_check( rti, 20.0f ) ) return 0; // 检查能量
    // * DECL_SPELL要做的事情之二：破坏条件
    gcd_start( rti, 1.5f / ( 1.0f + rti->player.haste ) ); // 基础1.5秒，受急速影响的GCD。
    smackthat_cd = TIME_OFFSET( FROM_SECONDS( 3 ) ); // CD设置为3秒后。
    eq_enqueue( rti, smackthat_cd, routnum_smackthat_cd, 0 ); // 插入CD完成事件。
    power_consume( rti, 20.0f ); // 消耗能量
    // some_depend_buffs_expire = rti->timestamp; // 有时还需要消耗掉前置Buff
    // eq_enqueue( rti, some_depend_buffs_expire, routnum_some_depend_buffs_expire, 0 ); // 立刻触发该Buff结束的事件。这会导致原本的结束事件空悬，所以处理程序里需要过滤空悬。
    // * DECL_SPELL要做的事情之三：插入事件
    eq_enqueue( rti, rti->timestamp, routnum_smackthat_cast, 0 ); // 插入技能释放事件。
    lprintf( ( "cast smackthat" ) ); // 打印战斗日志
    // * DECL_SPELL要做的事情之四：返回成功释放的信号
    return 1; // 返回1表示释放成功。
}

// === bsod ===================================================================
#if (TALENT_BSOD)   // 天赋技能用预处理包含起来，在不选择天赋的时候减轻编译压力。
DECL_EVENT( bsod_cd ) {
    lprintf( ( "bsod cd" ) );
}
DECL_EVENT( bsod_cast ) {
    power_gain( rti, 10.0f * target_id );   // 释放bsod，消耗所有smackthat层数，每层得到10能量。target_id可以用来传递这个层数。
    // target_id transfers the stack of smackthat consumed.  // 你应该加以注释，表示你是如何使用target_id来传递信息的，让其他人能够读懂你的程序。
    // 实际上，这个效果也可以写在DECL_SPELL里面要做的事情之二那里，就可以避免这种传递。这里是为了展示target_id的非常规用法而这样写的。
    lprintf( ( "cast bsod" ) );
}
DECL_SPELL( bsod ) {
    // * DECL_SPELL要做的事情之一：检查条件
    if ( UP( rti->player.gcd ) ) return 0; // 检查GCD   
    if ( UP( bsod_cd ) ) return 0;   // 检查冷却
    if ( !UP( smackthat_expire ) ) return 0; // 检查前置Buff是否激活
    // * DECL_SPELL要做的事情之二：破坏条件
    gcd_start( rti, 1.5f / ( 1.0f + rti->player.haste ) ); // 基础1.5秒，受急速影响的GCD。
    bsod_cd = TIME_OFFSET( FROM_SECONDS( 6 ) ); // CD设置为6秒后。
    eq_enqueue( rti, bsod_cd, routnum_bsod_cd, 0 ); // 插入CD完成事件。
    smackthat_expire = rti->timestamp; // 消耗掉前置Buff
    eq_enqueue( rti, smackthat_expire, routnum_smackthat_expire, 0 ); // 立刻触发该Buff结束的事件。这会导致原本的结束事件空悬，所以处理程序里需要过滤空悬。
    // * DECL_SPELL要做的事情之三：插入事件
    eq_enqueue( rti, bsod_cast, routnum_bsod_cast, smackthat_stack );
    // target_id transfers the stack of smackthat consumed.  // 你应该加以注释，表示你是如何使用target_id来传递信息的，让其他人能够读懂你的程序。
    lprintf( "cast bsod" );
    // * DECL_SPELL要做的事情之四：返回成功释放的信号
    return 1;
}
#else
DECL_SPELL( bsod ) {    // 即使没有启用这个天赋，也要声明这个技能，否则用户在没有选择bsod天赋的时候APL里写SPELL( bsod )就会导致语法错误。
    return 0;           // 没有选择天赋，无论如何也是无法释放的，返回0就行了。
}
#endif

/*
    routine_entries：事件处理程序入口。这是框架要求你必须定义的。
    它的作用是分拣事件，根据事件编号选择相应的处理程序来调用。
*/
void spec_routine_entries( rtinfo_t* rti, _event_t e ); // 专精模块的事件处理程序入口，也接在这里。
void routine_entries( rtinfo_t* rti, _event_t e ) {     // 总的事件处理程序入口。
    if( e.routine >= START_OF_SPEC_ROUTNUM ) {          // 如果事件编号属于专精模块，那就交由专精模块的事件处理程序入口来处理。
        spec_routine_entries( rti, e );
    }
    else switch( e.routine ) {                          // 否则进行分拣。
        HOOK_EVENT( gcd_expire );                       // 每一个事件编号routnum对应一个处理程序DECL_EVENT，HOOK_EVENT可以将它们对应起来。
        HOOK_EVENT( smackthat_expire );                 // 每个事件都要在这里hook一下，才能被调用到。
        HOOK_EVENT( smackthat_cd );
        HOOK_EVENT( smackthat_cast );
#if (TALENT_BSOD)                                       // 天赋事件只在激活天赋后才有，所以预处理一下。
        HOOK_EVENT( bsod_cd );
        HOOK_EVENT( bsod_cast );
#endif
    default:
        lprintf( ( "wild class routine entry %d", e.routine ) ); // 如果事件编号没有相应的hook，一定是开发者遗漏了什么，报告这个问题
        assert( 0 );    // 在此报错。
    }
}

/*
    模块初始化。这是框架要求你必须定义的。
*/
void spec_module_init( rtinfo_t* rti ); // 专精模块的初始化。
void class_module_init( rtinfo_t* rti ) {
    spec_module_init( rti ); // 首先初始化专精部分。

    // 初始化面板属性。
    refresh_str( rti );
    refresh_mastery( rti );
    // ...
    
    // 在日志里打印初始属性。
    lprintf( ( "Raid buffed str %d", rti->player.stat.str ) );
    lprintf( ( "Raid buffed ap %d", rti->player.stat.ap ) );
    lprintf( ( "Raid buffed crit %f", rti->player.stat.crit ) );
    lprintf( ( "Raid buffed haste %f", rti->player.stat.haste ) );
    lprintf( ( "Raid buffed mastery %f", rti->player.stat.mastery ) );
    lprintf( ( "Raid buffed vers %f", rti->player.stat.vers ) );

    // 如果有模拟开始之前就要插入的事件，放在这里。
    // RPPM的触发率信息RPPM_t放在这里初始化。
}

/*
    触发效果
*/
void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ); // 专精模块的触发效果。
void special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    // 有触发效果的话，把触发写在这里。
    // special_procs会被round_table_dice调用。
}

/************************** 这里开始一个专精模块范例 ***********************************************/

struct spec_state_t {   // struct spec_state_t 也是框架要求你必须定义的。
    int placeholder;    // 和struct class_state_t完全相同，只不过包含的是与专精相关的状态信息。
                        // 引用class_state_t的路径是rti->player.class->
                        // 引用spec_state_t的路径是rti->player.spec->
    // ...              // 照着职业模块那样写即可。
};
struct spec_debuff_t{   // 相应的，也要有struct spec_debuff_t。
    int placeholder;
    // ...
};

float spec_mastery_coefficient( rtinfo_t* rti ){    // 所有职业模块搞多态留下的待实现的函数，你都需要在这里搞定。
    return 2.0f;
}
float spec_mastery_increament( rtinfo_t* rti ){
    return 0.0f;
}

// round_table_dice2是一个额外的掷骰函数。区别在于它不触发特效。
// 有时你也会希望用到round_table_dice2，直接用，没关系。声明到职业模块里去，在职业模块里也能用。
k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );   // uni_rng返回一个随机数。
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate; // 计算爆击率。0.03是爆击压制。
    if (ATYPE_WHITE_MELEE == attacktype){

    }
    if (ATYPE_YELLOW_MELEE == attacktype){
        if ( UP( smackthat_expire ) ) cr += 0.1f * smackthat_stack;   // 某些改变概率的技能效果在这里编写。例如这里，smackthat效果每层提供10%的近战技能额外爆击率。
    }
    if ( c < cr ){  // roll点结果和爆击率比较，决定是爆击还是命中。
        return DICE_CRIT;
    }
    return DICE_HIT;
}
// round_table_dice是能够触发特效的版本。
k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    k32u dice = round_table_dice2( rti, target_id, attacktype, extra_crit_rate );
    special_procs( rti, attacktype, dice, target_id );
    return dice;
}
// 造成伤害的函数。很重要。
float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor ) {
    if ( DICE_MISS == dice ) return .0f; // miss了就不再造成伤害了。
    if ( DTYPE_DIRECT == dmgtype ){ // 直接伤害如字面意思，就这么多，不受加成减免。
        lprintf( ( "damage %.0f", dmg ) ); 
        rti->damage_collected += dmg; // 直接处理就行。
        return dmg;
    }
    float cdb = ( 1.0f + extra_crit_bonus ) * 2.0f; // 爆击伤害倍数
    dmg *= 1.0f + rti->player.stat.vers;            // 全能加成
    // 各种技能特效能影响伤害计算的，都写在这里。
    if ( UP( smackthat_expire ) )                               dmg *= 1.2f;  // smackthat效果存在时，伤害提高20%
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f; // 矮人和牛头人爆击伤害提高2%
    if (DTYPE_PHYSICAL == dmgtype){
        if ( !ignore_armor )                                    dmg *= 0.650684f; // 0.680228f @110lvl // 护甲减免
    }
    if ( DICE_CRIT == dice )                                    dmg *= cdb;   // 爆击的伤害提高
    if ( DICE_CRIT == dice ){
        lprintf( ( "damage *%.0f*", dmg ) );
    } else {
        lprintf( ( "damage %.0f", dmg ) );
    }
    rti->damage_collected += dmg; // 统计伤害。
    return dmg; // 将最终实际造成的伤害量返回回去，技能可能会用到这个信息。
}

// 武器伤害
float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )MH_LOW; // 这里默认使用主手了，双持专精需要处理一下副手
    dmg += uni_rng( rti ) * ( MH_HIGH - MH_LOW ); // 武器伤害有个随机范围
    dmg += ( normalized ? normalized_weapon_speed[MH_TYPE] : MH_SPEED ) * rti->player.stat.ap / 3.5f; // 武器伤害公式
    dmg *= weapon_multiplier;
    if ( MH_TYPE == WEAPON_2H ) dmg *= 1.1f; // 装备双手武器时，伤害提高10%（武器战的被动“身经百战”，其他专精应该有类似机制）
    return dmg;
}
// AP伤害
float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap; // AP伤害就是系数乘以AP
    if ( MH_TYPE == WEAPON_2H ) dmg *= 1.1f;         // 装备双手武器时，伤害提高10%
    return dmg;
}

// 专精模块的事件编号列表
enum{
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1, // 根据职业模块留下的START_OF_SPEC_ROUTNUM，确定专精模块的事件编号从多少开始。
    routnum_auto_attack,                              // 这个编号会等于START_OF_SPEC_ROUTNUM，下面的编号会逐次递增。
    // ...
    START_OF_WILD_ROUTNUM,                            // 从这个编号起往后都是未定义的了
};

// 专精模块的事件和法术
// === auto-attack ============================================================
DECL_EVENT( auto_attack ) { // 肉搏由上一次肉搏触发下一次肉搏就可以了，不需要设计一个SPELL给它，只需要一个EVENT。
    float d = weapon_dmg( rti, 1.0f, 0, 0 ); // 100%非标准化主手武器伤害
    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 ); // 掷骰
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 ); // 造成伤害

    float aspeed = 1.0f + rti->player.stat.haste; // 攻击速度
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( MH_SPEED / aspeed ) ), routnum_auto_attack, rti->player.target ); // 确定下一次攻击的时刻
}

// 专精的事件处理程序入口
void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {           // 分拣事件
        HOOK_EVENT( auto_attack );  // 专精模块中定义的事件在这里hook。
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) ); // 如果事件编号没有hook，一定是开发者遗漏了什么
        assert( 0 );  // 报错
    }
}

// 专精模块初始化
void spec_module_init( rtinfo_t* rti ) {
    rti->player.power = 0.0f;
    power_gain( rti, 15.0f ); // 设置初始能量
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack, 0 ); // 启动肉搏。
}

// 专精的触发效果
void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    // 如果有的话，写在这里。
}