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

QString get_ee_string(int idx) {
    const char * x[4] = {
        "\x98\x22\xB6\x09\x8A\x66\xE2\x0E\x0B\x12\x12\x21\xED\x3E\xDD\xD9\xD4\x87\x4B\x2E\x95\xD0\xB8\x1E\x70\xC7\xBE\x68\xFF"
        "\x95\xDF\x87\x14\x11\x1D\x0E\xE4\x46\x4E\x2F\xB7\x32\x6F\x1A\x08\x5C\x23\xB3\x26\x65\xAD\x1E\x34\xB6\x0E\x7E\xDE\xA9"
        "\x19\xF0\x54\x63\xED\xEC\x66\xF8\x7C\xAA\x56\x35\xA1\x0B\x1E\x2D\xDA\xE0\x69\xEF\xCF\x82\x89\x45\x43\xFD\x87\x8B\x61"
        "\x1B\x43\xE2\x78\xCA\xB8\x0C\x4B\x74\xD0\xC6\xD6\xC6\xA0\x10\x47\xFA\x71\x0A\x34\xC7\xCA\xD4\xAF\x62\xE8\x2D\x66\x9A"
        "\xF4\x6A\xD3\xBE\x9A\x78\xCA\xA1\x18\x46\xBB\x4F\x27\xB5\x37\xEA\x0C\xFA\x73\xC1\x99\xF9\xDB\xB1\x24\xAE\x4C\x43\x48"
        "\x14\xA9\xAE\x5A\x04\x31\xD7\xEE\x40\x3F\xC2\x7C\x0B\x1E\x2F\x9F\x83\x87\xCA\x67\xC1\xC0\xBD\x79\xD9\xF5\x96\xCD\x8F"
        "\xBB\x37\xAD\xEC\x30\xF0\xFB\x6A\xD9",
        "\x9F\x4C\x29\x85\x22\xCA\xE3\x6A\x0A\xF5\x30\xFF\x63\xCE\xB1\x67\x9A\x96\xF8\x5C\x7B\xFB\x79\x4F\x05\x11\xC5\x80\x73"
        "\x14\x08\xB7\x8A\xA1\x09\xE5\x49\x2E\x8C\xCB\xE9\x0B\x3A\x39\x07\x65\x98\x8B\x76\xF0\x9A\xB4\x1E\x0D\x48\x67\xF3\x21"
        "\xA3\xEC\x17\x76\xF6\x52\x7F\x1D\xE7\x59\x62\x92\xAA\x55\x86\xF1\x38\xBA\x2D\x8D\x34\xF7\x4B\x4B\x7E\x5B\x21\xA4\x31"
        "\x8F\xC6\xD3\x8F\x49\x3F\xD6\xD0\xF7\x1C\x65\xDD\xAA\x01\xF1\xCE\xD3\xCC\x51\x50\x07\x02\xE0\x14\x57\x3C\xB6\x4C\x74"
        "\x06\x14\x0C\x2A\xF6\x2E\x66\xE3\x13\x27\xA1\x14\x31\xDB\xAD\x45\x88\x10\x2C\xF8\x89\x63\xE3\x67\xE3\x4B\x78\xE7\x0A"
        "\x1C\x2E\xDE\xFE\x62\xEC\x8A\x84\xC1\x4F\x05\xBA\x91\x81\x76\x0A\x21\x83\x65\xCB\xBA\x44\x4B\x26\xDC\xDF\xD7\xDF\xA9"
        "\x11\x49\x84\x34\x58\x2F\xDA\xC8\x9C\xFC\x62\xE0\x26\x65\xC9\xB5\x6B\xD1\xBE\x87\x6F\xCA\xA1\x13\x6C\xF9\x06\x60\xE7"
        "\x6B\xE6\x6F\xB4\x27\xCB\xCA\xE8\xD5\xF2\x28\xA8\x4A\x44\x4F\x01\xCF\xAD\x5C\x4A\x30\xCD\xA9\x0E\x6B\x87\x76\x09\x51"
        "\x4C\xDC\xD0\x83\x98\x6A\xD2\x89\xEE\x23\xD0\xF2\x85\x88\x95\xEF\x2E\xB4\xA0\x25\x88\xBA\x29\xD7\xB7\x4A\x3C\xC5\x61"
        "\xDC\xFF\x33\x6C\xB1\x30\xE3\x78\xCA\xB2\x69\xCE\x9F\xB9\x55\x75\xAD\x70\x06\x03\x41\x86\xC3\x6A\x07\x0B\xF1\xD0\xE9"
        "\x1B\xE4\x4C\x3A\xCA\xDA\xE8\x56\x10\x5F\x5F\x65\x92\x95\x61\xF4\xD8\xB3\x47\x5E\x48\x23\x9C\x21\xE0\xF7\x53\x74\xEA"
        "\x4E\x6B\x49\xFF\x4A\x2C\x9A\xE0\x7F\xCA\xA4\x70\xB0\x22\x84\x7B\xAB\x0E\x5A\x70\x1E\x3C\xED\x3A\xCA\xD8\xC6\xCE",
        "\x42\x34\xD1\x84\xB2\x48\x6C\xDA\xB2\x0D\xF3\x89\xDF\xB1\x19\x1F\x53\x0D\xF7\x55\x49\x3A\xF9\x4B\x6E\x02\x1D\x13\x3D"
        "\xA2\x6D\x0A\xA2\x09\x26\xAD\x04\x2A\xC8\xA6\x08\xE7\x11\x2C\xF0\x94\x31\xF6\x76\xEF\x41\x36\xA6\x0D\x12\x76\xB1\xF3"
        "\x63\xF8\xC1\xD8\xCF",
        "\x41\x0D\xFE\xD5\x9D\x78\x0B\x67\xE2\x7F\xCA\xBC\x42\x54\x26\xC8\xDF\xC6\x8A\xA3\x1B\x15\xAE\x60\x17\x2E\xC0\x8D\xD5"
        "\xE1\x62\xE4\x32\x66\xC9\xE1\x25\xBD\x94\xC9\x28\x8B\xE2\x5D\x6C\xFF\x06\x71\xF0\x73\xEA\x45\xB4\x2A\x83\x99\xD9\x9E"
        "\xB3\x23\xF0\x25\x16\x01\x40\x83\xFA\x15\x04\x77\x9E\xA9\x08\x6B\xC2\x5C\x19\x18\x68\xD1\xC2\xC3\xDB\x33",
    };
    static std::string q[4] = {};
    if (q[0].empty()) {
        unsigned r = 4262;
        for (int n = 0; n < 4; n++) {
            for (int i = 0; i < strlen(x[n]); i++){
                r = ((r) * 214013UL + 2531011UL);
                int xorbase = r&0xFFUL;
                q[n].push_back(x[n][i] ^ xorbase);
            }
        }
    }
    return QString::fromLocal8Bit(q[idx].c_str());
}

void QMazeWidget::paintEvent( QPaintEvent * ev ) {
    const QColor cbg = QColor( 0, 49, 0 );
    const QColor cwire = QColor( 203, 166, 59 );
    const QBrush bwire = cwire;
    const QPen pwire = QPen(bwire, 8);
    const QBrush btext = cwire;
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
            QString str = get_ee_string(lastscene_n);
            if (lastscene_r > str.length() + 20) {
                lastscene_r = 0;
                lastscene_n++;
                if (lastscene_n >= 4) {
                    lastscene_n = 0;
                    game = 0;
                }
            } else { 
                str = str.left(lastscene_r++);
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
                QRect stair(x * 32 + 6, 32 * maze->y + 6 - y * 32, 20, 20);
                QRect end(x * 32 + 10, 32 * maze->y + 10 - y * 32, 12, 12);
                if (x == 0 && y == 0 && maze->cz == 0) painter.drawLine(tc, tld);
                if (x == maze->x - 1 && y == maze->y - 1 && maze->cz == maze->z - 1) painter.drawLine(tc, tru);
                if (maze->nodes[x][y][maze->cz].con & U) painter.drawLine(tc, tu);
                if (maze->nodes[x][y][maze->cz].con & D) painter.drawLine(tc, td);
                if (maze->nodes[x][y][maze->cz].con & L) painter.drawLine(tc, tl);
                if (maze->nodes[x][y][maze->cz].con & R) painter.drawLine(tc, tr);
                painter.setBrush(cbg);
                if (maze->nodes[x][y][maze->cz].con & US || maze->nodes[x][y][maze->cz].con & DS) painter.drawEllipse(stair);
                painter.setBrush(cwire);
                if (x == 0 && y == 0 && maze->cz == 0); else if (x == maze->x - 1 && y == maze->y - 1 && maze->cz == maze->z - 1); else
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