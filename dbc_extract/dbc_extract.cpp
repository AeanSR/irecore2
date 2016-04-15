/*
    IreCore dbc extractor.
    Aeandarian(a.k.a. fhsvengetta) 2016.3.24

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma pack(1)

#include "CascLib.h"
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <sstream>
#include <algorithm>

struct record_t {
    void inline_str_process( void* data, size_t length, size_t size_of_this ) {
        if (length >= size_of_this) {
            memcpy( this, data, size_of_this );
        }
    }
};

struct item_sparse_record_t : public record_t {
    INT32   dc0[3];
    float   dc1;
    float   dc2;
    UINT32  dc3;
    UINT32  dc4;
    INT32   dc5;
    INT32   dc6;
    UINT32  dc7;
    INT32   dc8;
    INT32   dc9;
    INT32   dc10[10];
    float   dc11[10];
    float   dc12; // 132 bytes
    std::string  name;
    std::string  desc; // variable length
    INT32   dc67;
    INT32   dc68;
    INT32   dc69;
    UINT32  dc18;
    float   dc19;
    UINT32  dc20;
    float   dc21;
    UINT16  dc22;
    UINT16  dc23;
    UINT16  dc24;
    UINT16  dc25;
    INT16   dc26[10];
    UINT16  dc27;
    UINT16  dc28;
    UINT16  dc29;
    UINT16  dc30;
    UINT16  dc31;
    UINT16  dc32;
    UINT16  dc33;
    UINT16  dc34;
    UINT16  dc35;
    UINT16  dc36;
    UINT16  gem_props;
    UINT16  dc37;
    // gem props was here.
    UINT16  dc39;
    UINT16  dc40;
    UINT16  dc41;
    UINT8   dc42;
    UINT8   dc43;
    UINT8   dc44;
    INT8    dc45;
    UINT8   dc46;
    UINT8   dc47;
    UINT8   dc48;
    UINT8   dc49;
    INT8    dc50[10];
    UINT8   dc51;
    UINT8   dc52;
    UINT8   dc53;
    UINT8   dc54;
    UINT8   dc55;
    UINT8   dc56;
    UINT8   dc57;
    UINT8   dc58[3];
    UINT8   dc59;
    UINT8   dc60;
    UINT8   dc61;
    UINT8   dc62;
    //UINT8   dc63;
    //UINT8   dc64;
    void inline_str_process( void* data, size_t length, size_t size_of_this ) {
        size_t invariant1 = 132;
        size_t invariant2 = sizeof( *this ) - invariant1 - 2 * sizeof( std::string );

        memcpy( this, data, invariant1 );
        memcpy( &dc67, ( char* ) data + length - invariant2, invariant2 );

        char* q = ( char* ) data + invariant1;
        while (*q) {
            name.push_back( *q++ );
        }
        q += 4;
        while (*q) {
            desc.push_back( *q++ );
        }
    }
};

struct item_record_t : public record_t {
    INT32 dc0;
    UINT8 item_class;
    UINT8 item_subclass;
    INT8  dc1;
    UINT8 dc2;
    UINT8 dc3;
    UINT8 dc4;
    UINT8 dc5;
    UINT8 dc6;
};

struct item_enchantment_record_t : public record_t {
    UINT32 id_property[3];
    UINT32 dc0;
    float  coeff[3];
    UINT32 dc1;
    UINT32 dc14;
    INT16  amount[3];
    UINT16 dc2;
    UINT16 dc3;
    UINT16 dc4;
    UINT16 dc5;
    UINT16 min_scaling_level;
    UINT8  dc6;
    UINT8  type[3];
    INT8   dc8;
    UINT8  dc9;
    INT8   max_scaling_level;
    INT8   scaling_type;
    INT8   dc10;
    INT8   dc11;
    INT8   dc12;
    UINT8  dc13;
};

struct gem_properties_record_t : public record_t {
    UINT32 dc0;
    UINT16 id_enchant;
    UINT16 dc1;
};

template <typename T>
int wdbc_reader( HANDLE file, std::vector<std::pair<UINT32, T> >& records, std::vector<char>& string_block ) {
    struct {
        UINT32 record_count;
        UINT32 field_count;
        UINT32 record_size;
        UINT32 string_block_size;
    } header;
    void* discard;
    DWORD read;
    if (!CascReadFile( file, &header, sizeof( header ), &read )) {
        printf( "failed to read dbc header\n" );
        return 0;
    }
    if (read != sizeof( header )) {
        printf( "dbc header broken\n" );
        return 0;
    }
    if (header.record_size < sizeof( T )) {
        printf( "record size is lesser than expect\n" );
        return 0;
    }
    if (header.record_size > sizeof( T )) {
        printf( "record size is greater than expect\n" );
        // this is a warning. resume.
        discard = alloca( header.record_size - sizeof( T ) );
    }
    for (UINT32 i = 0; i < header.record_count; i++) {
        T new_record;
        if (!CascReadFile( file, &new_record, sizeof( T ), &read )) {
            printf( "failed to read dbc record\n" );
            return 0;
        }
        if (read != sizeof( T )) {
            printf( "dbc record broken\n" );
            return 0;
        }
        records.push_back( std::make_pair( i, new_record ) );
        if (header.record_size > sizeof( T )) {
            if (!CascReadFile( file, discard, header.record_size - sizeof( T ), &read )) {
                printf( "failed to read dbc record (padding)\n" );
                return 0;
            }
            if (read != header.record_size - sizeof( T )) {
                printf( "dbc record (padding) broken\n" );
                return 0;
            }
        }
    }
    string_block.resize( header.string_block_size );
    if (!CascReadFile( file, &string_block[0], header.string_block_size, &read )) {
        printf( "failed to read dbc string block\n" );
        return 0;
    }
    if (read != header.string_block_size) {
        printf( "dbc string block broken\n" );
        return 0;
    }
    return 1;
}

template <typename T>
int wdb4_reader( HANDLE file, std::vector<std::pair<UINT32, T> >& records, std::vector<char>& string_block ) {
    struct {
        UINT32 record_count;
        UINT32 field_count;
        UINT32 record_size;
        UINT32 string_block_size;
        UINT32 table_hash;
        UINT32 build;
        UINT32 timestamp_last_written;
        UINT32 min_id;
        UINT32 max_id;
        UINT32 locale;
        UINT32 copy_table_size;
        UINT32 flags;
    } header;
    void* discard;
    DWORD read;
    if (!CascReadFile( file, &header, sizeof( header ), &read )) {
        printf( "failed to read dbc header\n" );
        return 0;
    }
    if (read != sizeof( header )) {
        printf( "dbc header broken\n" );
        return 0;
    }
    if (header.flags & 0x01) {
        struct offset_map_entry_t {
            UINT32 offset;
            UINT16 length;
        };
        std::vector<offset_map_entry_t> offset_map;
        CascSetFilePointer( file, header.string_block_size, 0, FILE_BEGIN );
        for (UINT32 i = header.min_id; i <= header.max_id; i++) {
            offset_map_entry_t o;
            if (!CascReadFile( file, &o, sizeof( offset_map_entry_t ), &read )) {
                printf( "failed to read dbc offset map\n" );
                return 0;
            }
            if (read != sizeof( offset_map_entry_t )) {
                printf( "dbc offset map broken\n" );
                return 0;
            }
            offset_map.push_back( o );
        }
        records.resize( header.record_count );
        if (header.flags & 0x04) {
            for (UINT32 i = 0; i < header.record_count; i++) {
                UINT32 id;
                if (!CascReadFile( file, &id, sizeof( UINT32 ), &read )) {
                    printf( "failed to read dbc explicit id\n" );
                    return 0;
                }
                if (read != sizeof( UINT32 )) {
                    printf( "dbc explicit id broken\n" );
                    return 0;
                }
                records[i].first = id;
            }
        }
        for (auto i = records.begin(); i != records.end(); i++) {
            T new_record;
            std::string buf;
            buf.resize( offset_map[i->first - header.min_id].length );
            CascSetFilePointer( file, offset_map[i->first - header.min_id].offset, 0, FILE_BEGIN );
            if (!CascReadFile( file, &buf[0], buf.size(), &read )) {
                printf( "failed to read dbc record\n" );
                return 0;
            }
            if (read != buf.size()) {
                printf( "dbc record broken\n" );
                return 0;
            }
            new_record.typename T::inline_str_process( &buf[0], buf.size(), sizeof( T ) );
            i->second = new_record;
        }
        CascSetFilePointer( file, header.string_block_size + offset_map.size() * sizeof( offset_map_entry_t ) + header.record_count * sizeof( UINT32 ), 0, FILE_BEGIN );
    } else {
        if (header.record_size < sizeof( T )) {
            printf( "record size is lesser than expect\n" );
            return 0;
        }
        if (header.record_size > sizeof( T )) {
            printf( "record size is greater than expect, %d %d\n", sizeof( T ), header.record_size );
            // this is a warning. resume.
            discard = alloca( header.record_size - sizeof( T ) );
        }
        for (UINT32 i = 0; i < header.record_count; i++) {
            T new_record;
            if (!CascReadFile( file, &new_record, sizeof( T ), &read )) {
                printf( "failed to read dbc record\n" );
                return 0;
            }
            if (read != sizeof( T )) {
                printf( "dbc record broken\n" );
                return 0;
            }
            records.push_back( std::make_pair( i, new_record ) );
            if (header.record_size > sizeof( T )) {
                if (!CascReadFile( file, discard, header.record_size - sizeof( T ), &read )) {
                    printf( "failed to read dbc record (padding)\n" );
                    return 0;
                }
                if (read != header.record_size - sizeof( T )) {
                    printf( "dbc record (padding) broken\n" );
                    return 0;
                }
            }
        }
        string_block.resize( header.string_block_size );
        if (!CascReadFile( file, string_block.data(), header.string_block_size, &read )) {
            printf( "failed to read dbc string block\n" );
            return 0;
        }
        if (read != header.string_block_size) {
            printf( "dbc string block broken %d %d\n", read, header.string_block_size );
            return 0;
        }
        if (header.flags & 0x04) {
            for (UINT32 i = 0; i < header.record_count; i++) {
                UINT32 id;
                if (!CascReadFile( file, &id, sizeof( UINT32 ), &read )) {
                    printf( "failed to read dbc explicit id\n" );
                    return 0;
                }
                if (read != sizeof( UINT32 )) {
                    printf( "dbc explicit id broken\n" );
                    return 0;
                }
                records[i].first = id;
            }
        }
    }
    if (header.copy_table_size > 0) {
        struct copy_table_entry_t {
            UINT32 id_of_new_row;
            UINT32 id_of_copied_row;
        };
        copy_table_entry_t* copy_table = ( copy_table_entry_t* ) alloca( header.copy_table_size );
        if (!CascReadFile( file, copy_table, header.copy_table_size, &read )) {
            printf( "failed to read dbc copy table\n" );
            return 0;
        }
        if (read != header.copy_table_size) {
            printf( "dbc copy table broken\n" );
            return 0;
        }
        for (UINT32 i = 0; i < header.copy_table_size / sizeof( copy_table_entry_t ); i++) {
            for (auto rec = records.begin(); rec != records.end(); rec++) {
                if (rec->first == copy_table[i].id_of_copied_row) {
                    T copied = rec->second;
                    records.push_back( std::make_pair( copy_table[i].id_of_new_row, copied ) );
                    break;
                }
            }
        }
    }
    return 1;
}
template <typename T>
int wdb5_reader( HANDLE file, std::vector<std::pair<UINT32, T> >& records, std::vector<char>& string_block ) {
    struct {
        UINT32 record_count;
        UINT32 field_count;
        UINT32 record_size;
        UINT32 string_block_size;
        UINT32 table_hash;
        UINT32 build;
        UINT32 min_id;
        UINT32 max_id;
        UINT32 locale;
        UINT32 copy_table_size;
        UINT32 flags;
    } header;
    void* discard;
    DWORD read;
    if (!CascReadFile( file, &header, sizeof( header ), &read )) {
        printf( "failed to read dbc header\n" );
        return 0;
    }
    if (read != sizeof( header )) {
        printf( "dbc header broken\n" );
        return 0;
    }
    for (int i = 0; i < header.field_count; i++) {
        struct field_info_t{
            UINT16 type;
            UINT16 pos;
        } field_info;
        if (!CascReadFile( file, &field_info, sizeof(field_info_t), &read )) {
            printf( "failed to read dbc field info\n" );
            return 0;
        }
        if (read != sizeof( field_info_t )) {
            printf( "dbc field info broken\n" );
            return 0;
        }
        printf("\tfield %d: type %d, pos %d\n", i+1, field_info.type, field_info.pos);
    }
    printf("%d, %d\n", sizeof(T), sizeof(std::string));
    if (header.flags & 0x01) {
        struct offset_map_entry_t {
            UINT32 offset;
            UINT16 length;
        };
        std::vector<offset_map_entry_t> offset_map;
        CascSetFilePointer( file, header.string_block_size, 0, FILE_BEGIN );
        for (UINT32 i = header.min_id; i <= header.max_id; i++) {
            offset_map_entry_t o;
            if (!CascReadFile( file, &o, sizeof( offset_map_entry_t ), &read )) {
                printf( "failed to read dbc offset map\n" );
                return 0;
            }
            if (read != sizeof( offset_map_entry_t )) {
                printf( "dbc offset map broken\n" );
                return 0;
            }
            offset_map.push_back( o );
        }
        records.resize( header.record_count );
        if (header.flags & 0x04) {
            for (UINT32 i = 0; i < header.record_count; i++) {
                UINT32 id;
                if (!CascReadFile( file, &id, sizeof( UINT32 ), &read )) {
                    printf( "failed to read dbc explicit id\n" );
                    return 0;
                }
                if (read != sizeof( UINT32 )) {
                    printf( "dbc explicit id broken\n" );
                    return 0;
                }
                records[i].first = id;
            }
        }
        for (auto i = records.begin(); i != records.end(); i++) {
            T new_record;
            std::string buf;
            buf.resize( offset_map[i->first - header.min_id].length );
            CascSetFilePointer( file, offset_map[i->first - header.min_id].offset, 0, FILE_BEGIN );
            if (!CascReadFile( file, &buf[0], buf.size(), &read )) {
                printf( "failed to read dbc record\n" );
                return 0;
            }
            if (read != buf.size()) {
                printf( "dbc record broken\n" );
                return 0;
            }
            new_record.typename T::inline_str_process( &buf[0], buf.size(), sizeof( T ) );
            i->second = new_record;
        }
        CascSetFilePointer( file, header.string_block_size + offset_map.size() * sizeof( offset_map_entry_t ) + header.record_count * sizeof( UINT32 ), 0, FILE_BEGIN );
    } else {
        if (header.record_size < sizeof( T )) {
            printf( "record size is lesser than expect\n" );
            return 0;
        }
        if (header.record_size > sizeof( T )) {
            printf( "record size is greater than expect, %d %d\n", sizeof( T ), header.record_size );
            // this is a warning. resume.
            discard = alloca( header.record_size - sizeof( T ) );
        }
        for (UINT32 i = 0; i < header.record_count; i++) {
            T new_record;
            if (!CascReadFile( file, &new_record, sizeof( T ), &read )) {
                printf( "failed to read dbc record\n" );
                return 0;
            }
            if (read != sizeof( T )) {
                printf( "dbc record broken\n" );
                return 0;
            }
            records.push_back( std::make_pair( i, new_record ) );
            if (header.record_size > sizeof( T )) {
                if (!CascReadFile( file, discard, header.record_size - sizeof( T ), &read )) {
                    printf( "failed to read dbc record (padding)\n" );
                    return 0;
                }
                if (read != header.record_size - sizeof( T )) {
                    printf( "dbc record (padding) broken\n" );
                    return 0;
                }
            }
        }
        string_block.resize( header.string_block_size );
        if (!CascReadFile( file, string_block.data(), header.string_block_size, &read )) {
            printf( "failed to read dbc string block\n" );
            return 0;
        }
        if (read != header.string_block_size) {
            printf( "dbc string block broken %d %d\n", read, header.string_block_size );
            return 0;
        }
        if (header.flags & 0x04) {
            for (UINT32 i = 0; i < header.record_count; i++) {
                UINT32 id;
                if (!CascReadFile( file, &id, sizeof( UINT32 ), &read )) {
                    printf( "failed to read dbc explicit id\n" );
                    return 0;
                }
                if (read != sizeof( UINT32 )) {
                    printf( "dbc explicit id broken\n" );
                    return 0;
                }
                records[i].first = id;
            }
        }
    }
    if (header.copy_table_size > 0) {
        struct copy_table_entry_t {
            UINT32 id_of_new_row;
            UINT32 id_of_copied_row;
        };
        copy_table_entry_t* copy_table = ( copy_table_entry_t* ) alloca( header.copy_table_size );
        if (!CascReadFile( file, copy_table, header.copy_table_size, &read )) {
            printf( "failed to read dbc copy table\n" );
            return 0;
        }
        if (read != header.copy_table_size) {
            printf( "dbc copy table broken\n" );
            return 0;
        }
        for (UINT32 i = 0; i < header.copy_table_size / sizeof( copy_table_entry_t ); i++) {
            for (auto rec = records.begin(); rec != records.end(); rec++) {
                if (rec->first == copy_table[i].id_of_copied_row) {
                    T copied = rec->second;
                    records.push_back( std::make_pair( copy_table[i].id_of_new_row, copied ) );
                    break;
                }
            }
        }
    }
    return 1;
}
template <typename T>
int dbc_reader( HANDLE storage, const char* dbc_name, std::vector<std::pair<UINT32, T> >& records, std::vector<char>& string_block ) {
    UINT32 magic;
    HANDLE file;
    DWORD read;
    int ok;
    printf( "%s\n", dbc_name );
    if (!CascOpenFile( storage, dbc_name, CASC_LOCALE_ALL, 0, &file )) {
        printf( "failed to open dbc %s, error %d\n", dbc_name, GetLastError() );
        return 0;
    }
    {
        DWORD size = CascGetFileSize( file, 0 );
        char* buf = (char*) malloc(size);
        CascReadFile( file, buf, size, &read );
        FILE* f = fopen(dbc_name, "wb");
        fwrite(buf, 1, read, f);
        fclose(f);
        CascSetFilePointer( file, 0, 0, FILE_BEGIN );
    }
    if (!CascReadFile( file, &magic, sizeof( magic ), &read )) {
        printf( "failed to read dbc magic %s\n", dbc_name );
        return 0;
    }
    if (read != sizeof( magic )) {
        printf( "dbc magic broken %s\n", dbc_name );
        return 0;
    }
    if (magic == ( ( ( UINT32 )'W' ) | ( ( UINT32 )'D' << 8 ) | ( ( UINT32 )'B' << 16 ) | ( ( UINT32 )'C' << 24 ) )) {
        ok = wdbc_reader( file, records, string_block );
    } else if (magic == ( ( ( UINT32 )'W' ) | ( ( UINT32 )'D' << 8 ) | ( ( UINT32 )'B' << 16 ) | ( ( UINT32 )'4' << 24 ) )) {
        ok = wdb4_reader( file, records, string_block );
    } else if (magic == ( ( ( UINT32 )'W' ) | ( ( UINT32 )'D' << 8 ) | ( ( UINT32 )'B' << 16 ) | ( ( UINT32 )'5' << 24 ) )) {
        ok = wdb5_reader( file, records, string_block );
    } else {
        printf( "wrong format specified, this file is %c%c%c%c, not WDBC, WDB4 or WDB5\n",
            ( char ) magic, ( char ) ( magic >> 8 ), ( char ) ( magic >> 16 ), ( char ) ( magic >> 24 ) );
        return 0;
    }
    CascCloseFile( file );
    if (ok) printf( "OK, %d records read\n", records.size() );
    return ok;
}

const char* dbfn_item = "DBFilesClient\\Item.db2";
const char* dbfn_itemsparse = "DBFilesClient\\Item-sparse.db2";
const char* dbfn_itemench = "DBFilesClient\\SpellItemEnchantment.db2";
const char* dbfn_gem = "DBFilesClient\\GemProperties.db2";
const char* dbfn_combatratingsmult = "GameTables\\CombatRatingsMultByILvl.txt";
const char* dbfn_spellscaling = "GameTables\\SpellScaling.txt";

enum {
    ITEMCLASS_WEAPON = 2,
    WEAPONSUBCLASS_AXE_1H = 0,
    WEAPONSUBCLASS_AXE_2H = 1,
    WEAPONSUBCLASS_BOW = 2,
    WEAPONSUBCLASS_GUN = 3,
    WEAPONSUBCLASS_MACE_1H = 4,
    WEAPONSUBCLASS_MACE_2H = 5,
    WEAPONSUBCLASS_POLEARM = 6,
    WEAPONSUBCLASS_SWORD_1H = 7,
    WEAPONSUBCLASS_SWORD_2H = 8,
    WEAPONSUBCLASS_WARGLAIVE = 9,
    WEAPONSUBCLASS_STAFF = 10,
    WEAPONSUBCLASS_BEAR_CLAW = 11,
    WEAPONSUBCLASS_CAT_CLAW = 12,
    WEAPONSUBCLASS_FIST_WEAPON = 13,
    WEAPONSUBCLASS_MISC = 14,
    WEAPONSUBCLASS_DAGGER = 15,

    ITEMCLASS_GEAR = 4,
    GEARSUBCLASS_MISC = 0,
    GEARSUBCLASS_CLOTH = 1,
    GEARSUBCLASS_LEATHER = 2,
    GEARSUBCLASS_MAIL = 3,
    GEARSUBCLASS_PLATE = 4,
};



int _tmain( int argc, TCHAR* argv[] ) {
    if (argc < 2) {
        printf( "need wow data directory.\n" );
        return 0;
    }
    HANDLE storage;
    if (!CascOpenStorage( argv[1], CASC_LOCALE_NONE, &storage )) {
        printf( "failed to open casc file system, error %d\n", GetLastError() );
        return 0;
    }
    std::vector<std::pair<UINT32, item_record_t> > item_records;
    std::vector<char> item_string_block;
    if (!dbc_reader( storage, dbfn_item, item_records, item_string_block )) {
        return 0;
    }
    std::vector<std::pair<UINT32, item_sparse_record_t> > item_sparse_records;
    std::vector<char> item_sparse_string_block;
    if (!dbc_reader( storage, dbfn_itemsparse, item_sparse_records, item_sparse_string_block )) {
        return 0;
    }
    std::vector<std::pair<UINT32, item_enchantment_record_t> > item_enchantment_records;
    std::vector<char> item_enchantment_string_block;
    if (!dbc_reader( storage, dbfn_itemench, item_enchantment_records, item_enchantment_string_block )) {
        return 0;
    }
    std::vector<std::pair<UINT32, gem_properties_record_t> > gem_properties_records;
    std::vector<char> gem_properties_string_block;
    if (!dbc_reader( storage, dbfn_gem, gem_properties_records, gem_properties_string_block )) {
        return 0;
    }

    const size_t spell_scaling_levels = 123;
    const size_t spell_scaling_classes = 18;
    float spell_scaling[spell_scaling_classes][spell_scaling_levels];
    HANDLE file; DWORD read;
    if (!CascOpenFile( storage, dbfn_spellscaling, CASC_LOCALE_ALL, 0, &file )) {
        printf( "failed to open dbc %s, error %d\n", dbfn_spellscaling, GetLastError() );
        return 0;
    }
    DWORD size = CascGetFileSize( file, 0 );
    std::string csv_buf;
    csv_buf.resize(size);
    CascReadFile( file, &csv_buf[0], size, &read );
    CascCloseFile( file );
    std::stringstream sss(csv_buf);
    std::string csv_line;
    std::getline(sss, csv_line);
    for(int i = 0; i < spell_scaling_levels; i++) {
        std::getline(sss, csv_line);
        std::stringstream ss2(csv_line);
        std::string csv_item;
        std::getline(ss2, csv_item, '\t');
        for(int j = 0; j < spell_scaling_classes; j++) {
            std::getline(ss2, csv_item, '\t');
            spell_scaling[j][i] = atoi(csv_item.c_str());
        }
    }

    const size_t combat_ratings_mult_maxilvl = 1300;
    float combat_ratings_mult[combat_ratings_mult_maxilvl];
    if (!CascOpenFile( storage, dbfn_combatratingsmult, CASC_LOCALE_ALL, 0, &file )) {
        printf( "failed to open dbc %s, error %d\n", dbfn_combatratingsmult, GetLastError() );
        return 0;
    }
    size = CascGetFileSize( file, 0 );
    csv_buf.resize(size);
    CascReadFile( file, &csv_buf[0], size, &read );
    CascCloseFile( file );
    std::stringstream ssc(csv_buf);
    std::getline(ssc, csv_line);
    for(int i = 0; i < combat_ratings_mult_maxilvl; i++) {
        std::getline(ssc, csv_line);
        std::stringstream ss2(csv_line);
        std::string csv_item;
        std::getline(ss2, csv_item, '\t');
        std::getline(ss2, csv_item, '\t');
        combat_ratings_mult[i] = atof(csv_item.c_str());
    }

    struct item_t {
        int id;
        int itemclass;
        int itemsubclass;
        int gem_enchant;
        std::string name;
        item_t() : id( 0 ), itemclass( 0 ), itemsubclass( 0 ), gem_enchant( 0 ) { }
        bool operator< ( const item_t& rhs ) { return id < rhs.id; }
    };
    std::vector<item_t> item_data;
    for (auto i = item_records.begin(); i != item_records.end(); i++) {
        item_t item;
        item.id = i->first;
        item.itemclass = i->second.item_class;
        item.itemsubclass = i->second.item_subclass;
        item.gem_enchant = 0;
        item_data.push_back( item );
    }
    for (auto i = item_sparse_records.begin(); i != item_sparse_records.end(); i++) {
        size_t id = i->first;
        size_t gem = i->second.gem_props;
        for (auto item = item_data.begin(); item != item_data.end(); item++) {
            if (item->id == id) {
                item->name = i->second.name;
                break;
            }
        }
        if (!gem) continue;
        auto pgem = gem_properties_records.end();
        for (auto g = gem_properties_records.begin(); g != gem_properties_records.end(); g++) {
            if (g->first == gem) {
                pgem = g;
                break;
            }
        }
        if (pgem == gem_properties_records.end()) {
            printf( "gem info not found for item%d gem%d\n", i->first, gem );
        } else {
            for (auto item = item_data.begin(); item != item_data.end(); item++) {
                if (item->id == id) {
                    item->gem_enchant = pgem->second.id_enchant;
                    break;
                }
            }
        }
    }

    struct enchant_t {
        int id;
        int prop[3];
        int value[3];
        enchant_t() : id( 0 ), prop(), value() { }
        bool operator< ( const enchant_t& rhs ) { return id < rhs.id; }
    };
    std::vector<enchant_t> enchant_data;
    for (auto i = item_enchantment_records.begin(); i != item_enchantment_records.end(); i++) {
        enchant_t enchant;
        enchant.id = i->first;
        for (int prop_idx = 0; prop_idx < 3; prop_idx++) {
            if (i->second.type[prop_idx] != 4 && i->second.type[prop_idx] != 5) continue; // magic number: 4 - type stat, 5 - type resistance
            enchant.prop[prop_idx] = i->second.id_property[prop_idx];
            if (i->second.scaling_type == 0) {
                enchant.value[prop_idx] = i->second.amount[prop_idx];
            } else {
                size_t class_id;
                size_t level = 100; // magic number 100: player level. update this when 110lvl goes live.
                level = min( ( int ) level, i->second.max_scaling_level );
                if (i->second.scaling_type < 0) {
                    class_id = 12 - i->second.scaling_type - 1; // magic number 12: count of player classes.
                } else {
                    class_id = i->second.scaling_type;
                }
                double budget = spell_scaling[class_id][level - 1];
                enchant.value[prop_idx] = ( int ) round( budget * i->second.coeff[prop_idx] );
            }
        }
        enchant_data.push_back( enchant );
    }

    std::sort( item_data.begin(), item_data.end() );
    std::sort( enchant_data.begin(), enchant_data.end() );

    FILE* f = fopen( "dbc.c", "wb" );
    fprintf( f, "\xEF\xBB\xBF" );
    fprintf( f, "/*\r\n\tIreCore Database %s\r\n*/\r\n\r\n#include \"dbc.h\"\r\n\r\n", __DATE__ );
    fprintf( f, "float _dbc_combat_ratings_mult[] = {\r\n" );
    for (size_t i = 0; i < combat_ratings_mult_maxilvl; i++) {
        fprintf( f, "\t%.6f,", combat_ratings_mult[i] );
        if (i % 5 == 4) fprintf( f, "\t// %d\r\n", i + 1 );
    }
    fprintf( f, "};\r\n" );

    fprintf( f, "_dbc_enchant_t _dbc_enchant_data[] = {\r\n" );
    enchant_data.push_back( enchant_t() );
    for (size_t i = 0; i < enchant_data.size(); i++) {
        fprintf( f,
            "\t{%6d, {%4d,%4d,%4d}, {%4d,%4d,%4d} },\r\n",
            enchant_data[i].id,
            enchant_data[i].prop[0],
            enchant_data[i].prop[1],
            enchant_data[i].prop[2],
            enchant_data[i].value[0],
            enchant_data[i].value[1],
            enchant_data[i].value[2]
            );
    }
    fprintf( f, "};\r\n" );
    fprintf( f, "_dbc_item_t _dbc_item_data[] = {\r\n" );
    for (size_t i = 0; i < item_data.size(); i++) {
        if (item_data[i].itemclass < 2 || item_data[i].itemclass > 4) continue;
        fprintf( f,
            "\t{%6d, %4d,%4d, %6d}, // %s\r\n",
            item_data[i].id,
            item_data[i].itemclass,
            item_data[i].itemsubclass,
            item_data[i].gem_enchant,
            item_data[i].name.c_str()
            );
    }
    fprintf( f, "\t{%6d, %4d,%4d, %6d},\r\n", 0, 0, 0, 0 );
    fprintf( f, "};\r\n" );
    fclose( f );
    printf( "dumped into \"dbc.c\"\n" );
    CascCloseStorage( storage );
    //system("pause");
    return 0;
}

