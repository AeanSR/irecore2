/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "qeelabel.h"
#include "gic.h"

int ee_clicked = 0;

void QEELabel::mousePressEvent( QMouseEvent * ev ) {
    ee_clicked++;
    if (ee_clicked == 6)
        QMetaObject::invokeMethod( gic::static_this, "show_maze_tab" );
}

void gic::show_maze_tab() {
    ui.tabWidget->addTab( ui.tabMaze, "Aean in Circuit!" );
}

enum {
    U = 1,
    D = 2,
    L = 4,
    R = 8,
    US = 16,
    DS = 32,
};
int con_reverse( int con ) {
    int rev = 0;
    if (con & U) rev |= D;
    if (con & D) rev |= U;
    if (con & L) rev |= R;
    if (con & R) rev |= L;
    if (con & US) rev |= DS;
    if (con & DS) rev |= US;
    return rev;
}

struct maze_node_t {
    maze_node_t* u;
    maze_node_t* d;
    maze_node_t* l;
    maze_node_t* r;
    maze_node_t* us;
    maze_node_t* ds;
    int con;
    maze_node_t* nbptr( int c ) {
        switch (c) {
        case U: return u;
        case D: return d;
        case L: return l;
        case R: return r;
        case US: return us;
        case DS: return ds;
        default: return 0;
        }
    }
    int choose_path() {
        std::vector<int> candidate;
        if (u) if (!( U & con )) if (!u->con) { for (int i = 0; i < 6; i++) candidate.push_back( U ); }
        if (d) if (!( D & con )) if (!d->con) { for (int i = 0; i < 6; i++) candidate.push_back( D ); }
        if (l) if (!( L & con )) if (!l->con) { for (int i = 0; i < 12; i++) candidate.push_back( L ); }
        if (r) if (!( R & con )) if (!r->con) { for (int i = 0; i < 12; i++) candidate.push_back( R ); }
        if (!( con & 48 )) {
            if (us) if (!( US & con )) if (!us->con) candidate.push_back( US );
            if (ds) if (!( DS & con )) if (!ds->con) candidate.push_back( DS );
        }
        if (candidate.empty()) return 0;
        return candidate.at( rand() % candidate.size() );
    }
    void visit( int parent ) {
        con |= con_reverse( parent );
        for (int i = 0; i < 2; i++) {
            int choose = choose_path();
            if (!choose) return;
            con |= choose;
            nbptr( choose )->visit( choose );
        }
    }
};

struct maze_t {
    std::vector<std::vector<std::vector<maze_node_t> > >nodes;
    int x;
    int y;
    int z;
    int cx;
    int cy;
    int cz;
    maze_t( int x, int y, int z ) : x( x ), y( y ), z( z ), cx( 0 ), cy( 0 ), cz( 0 ) {
        nodes.resize( x );
        for (auto i = nodes.begin(); i != nodes.end(); i++) {
            i->resize( y );
            for (auto j = i->begin(); j != i->end(); j++) {
                j->resize( z );
            }
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    try { nodes[i][j][k].u = &nodes.at( i ).at( j + 1 ).at( k ); } catch (std::out_of_range) { nodes[i][j][k].u = 0; }
                    try { nodes[i][j][k].d = &nodes.at( i ).at( j - 1 ).at( k ); } catch (std::out_of_range) { nodes[i][j][k].d = 0; }
                    try { nodes[i][j][k].l = &nodes.at( i - 1 ).at( j ).at( k ); } catch (std::out_of_range) { nodes[i][j][k].l = 0; }
                    try { nodes[i][j][k].r = &nodes.at( i + 1 ).at( j ).at( k ); } catch (std::out_of_range) { nodes[i][j][k].r = 0; }
                    try { nodes[i][j][k].us = &nodes.at( i ).at( j ).at( k + 1 ); } catch (std::out_of_range) { nodes[i][j][k].us = 0; }
                    try { nodes[i][j][k].ds = &nodes.at( i ).at( j ).at( k - 1 ); } catch (std::out_of_range) { nodes[i][j][k].ds = 0; }
                }
            }
        }
        nodes[x >> 1][y >> 1][z >> 1].visit( 0 );
    }
    maze_node_t& nchr() { return nodes[cx][cy][cz]; }
    void go( int c ) {
        if (nchr().nbptr( c )) if (nchr().con & c) {
            switch (c) {
            case U: cy++; break;
            case D: cy--; break;
            case L: cx--; break;
            case R: cx++; break;
            case US: cz++; break;
            case DS: cz--; break;
            }
        }
    }
};


void QMazeWidget::paintEvent( QPaintEvent * ev ) {
    const QColor cbg = QColor( 50, 50, 50 );
    const QColor cwire = QColor( 255, 200, 0 );
    const QBrush bwire = cwire;
    const QPen pwire = QPen(bwire, 6);
    const QColor ctext = QColor( 255, 255, 255 );
    const QBrush btext = ctext;
    const QPen ptext = QPen(btext, 1);
    QPainter painter( this );
    QWidget::paintEvent( ev );
    QStyleOption opt;
    opt.init( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &painter, this );
    if (!maze) {
        painter.setPen( ptext );
        if (!game) {
            painter.drawText( geometry(),
                Qt::AlignCenter,
                "Aean in Circuit!\n\n[Arrows] for move, [Space] for jump.\nClick to start..." );
        } else {
            QString str = R"(IreCore 2
is brought to you
by Aeandarian
the legendary warrior
who safeguards the grove

she traveled through time and space
dived into a circuit
to fight against bugs and stalls
...)";
            if (lastscene > str.length() + 20) {
                lastscene = 0;
                game = 0;
            } else { 
                str = str.left(lastscene++);
                str.append("_");
                painter.drawText( geometry(),
                    Qt::AlignCenter,
                    str);
            }
            
        }
    } else {
        QPoint base;
        const QPixmap pixchr[] = {
            QPixmap( ":/gic/logo/aean0.png" ),
            QPixmap( ":/gic/logo/aean1.png" ),
            QPixmap( ":/gic/logo/aean2.png" ),
            QPixmap( ":/gic/logo/aean3.png" ),
        };
        base.setX((geometry().width() - 32 * maze->x - 32) / 2);
        base.setY((geometry().height() - 32 * maze->y - 32) / 2);
        QRect rtitle = geometry();
        rtitle.setBottom(base.y());
        painter.setPen( ptext );
        painter.drawText( rtitle,
            Qt::AlignCenter,
            QString("Game ") + QString::number(game + 1) + QString(", Layer ") + QString::number(maze->cz + 1) );
        painter.save();
        painter.translate(base);
        painter.setPen(pwire);
        for(int x = 0; x < maze->x; x++) {
            for (int y = 0; y < maze->y; y++) {
                QPoint tc(x * 32 + 16, 32 * maze->y + 32 - y * 32 - 16);
                QPoint tu(x * 32 + 16, 32 * maze->y + 32 - y * 32 - 32);
                QPoint td(x * 32 + 16, 32 * maze->y + 32 - y * 32 -  0);
                QPoint tl(x * 32 +  0, 32 * maze->y + 32 - y * 32 - 16);
                QPoint tr(x * 32 + 32, 32 * maze->y + 32 - y * 32 - 16);
                QPoint tld(x * 32 + 0, 32 * maze->y + 32 - y * 32 - 0);
                QPoint tru(x * 32 + 32, 32 * maze->y + 32 - y * 32 - 32);
                QRect stair(x * 32 + 4, 32 * maze->y + 32 - y * 32 - 28, 24, 24);
                QRect end(x * 32 + 8, 32 * maze->y + 32 - y * 32 - 24, 16, 16);
                if (x == 0 && y == 0 && maze->cz == 0) painter.drawLine(tc, tld);
                if (x == maze->x - 1 && y == maze->y - 1 && maze->cz == maze->z - 1) painter.drawLine(tc, tru);
                if (maze->nodes[x][y][maze->cz].con & U) painter.drawLine(tc, tu);
                if (maze->nodes[x][y][maze->cz].con & D) painter.drawLine(tc, td);
                if (maze->nodes[x][y][maze->cz].con & L) painter.drawLine(tc, tl);
                if (maze->nodes[x][y][maze->cz].con & R) painter.drawLine(tc, tr);
                painter.setBrush(cbg);
                if (maze->nodes[x][y][maze->cz].con & US || maze->nodes[x][y][maze->cz].con & DS) painter.drawEllipse(stair);
                painter.setBrush(cwire);
                if (!(maze->nodes[x][y][maze->cz].con & maze->nodes[x][y][maze->cz].con - 1)) painter.drawEllipse(end);
                painter.setBrush(Qt::NoBrush);
            }
        }
        QRect recchr(maze->cx * 32 - 16, 32 * maze->y - 45 - maze->cy * 32, 64, 64);
        painter.drawPixmap(recchr, pixchr[direction]);
        painter.restore();
    }
}

const std::vector<int> game_x = { 3, 5, 6, 9, 12, 15, 18, 20, 20, 20 };
const std::vector<int> game_y = { 3, 5, 5, 6,  7,  8,  9, 10, 12, 15 };
const std::vector<int> game_z = { 1, 1, 2, 2,  3,  3,  4,  4,  5, 10 };

void QMazeWidget::mousePressEvent( QMouseEvent * ev ) {
    if (maze) return;
    if (game) return;
    maze = new maze_t(game_x[game], game_y[game], game_z[game]);
    grabKeyboard();
    update();
}

void QMazeWidget::keyPressEvent( QKeyEvent * ev ) {
    if (!maze) return;
    if (maze->cx == maze->x - 1 && maze->cy == maze->y - 1 && maze->cz == maze->z - 1) {
        delete maze;
        maze = NULL;
        direction = 0;
        game++;
        if (game < game_x.size()) {
            maze = new maze_t(game_x[game], game_y[game], game_z[game]);
        } else {
            timer = startTimer(300);
            releaseKeyboard();
        }
    } else {
        switch(ev->key()) {
        case Qt::Key_Space:
            direction = 0;
            if (maze->nchr().con & US) maze->go(US);
            else if (maze->nchr().con & DS) maze->go(DS);
            break;
        case Qt::Key_Up: maze->go(U); direction = 3; break;
        case Qt::Key_Down: maze->go(D); direction = 0; break;
        case Qt::Key_Left: maze->go(L); direction = 2; break;
        case Qt::Key_Right: maze->go(R); direction = 1; break;
        }
    }
    update();
}

void QMazeWidget::timerEvent(QTimerEvent *event) {
    if (!game) killTimer(timer);
    update();
}