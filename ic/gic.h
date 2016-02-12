/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef GIC_H
#define GIC_H

#include <QtWidgets/QMainWindow>
#include <QTranslator>
#include "libic.h"
#include "ui_gic.h"

class gic : public QMainWindow
{
    Q_OBJECT

public:
    gic(QWidget *parent = 0);
    ~gic();

private:
    Ui::gicClass ui;
};

#endif // GIC_H
