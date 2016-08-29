/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef QEELABEL_H
#define QEELABEL_H

#include <QLabel>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class QEELabel : public QLabel {
    Q_OBJECT
protected:
    virtual void mousePressEvent( QMouseEvent *ev );
public:
    QEELabel(QWidget * p) { QLabel::QLabel(p); }
};

struct maze_t;

class QMazeWidget : public QWidget
{
    Q_OBJECT
    maze_t* maze;
    int game;
    int lastscene;
    int timer;
    int direction;
public:
    QMazeWidget(QWidget *p) : maze(0), game(0), lastscene(0), direction(0) { QWidget::QWidget(p); setBackgroundRole(QPalette::Base); }
protected:
    virtual void timerEvent(QTimerEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent( QMouseEvent *ev );
    virtual void keyPressEvent( QKeyEvent *ev );
};

#endif