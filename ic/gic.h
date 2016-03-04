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
#include "util.h"
#include "ui_gic.h"
#include "ui_select_trinkets.h"

struct item_t {
    std::string name;
    int type;
    int str;
    int crit;
    int haste;
    int mastery;
    int mult;
    int vers;
    item_t() : type( 0 ), str( 0 ), crit( 0 ), haste( 0 ), mastery( 0 ), mult( 0 ), vers( 0 ), name( "" ) {}
};

struct paperdoll_t{
    item_t gear_list[16];
    int selected_gear_slot;
    Ui::gicClass* ui;
    paperdoll_t(Ui::gicClass& ui);
    void slot_switched();
};

class gic : public QMainWindow
{
    Q_OBJECT

public:
    paperdoll_t paperdoll;
    gic(QWidget *parent = 0);
    ~gic();

private:
    Ui::gicClass ui;
    QDialog* dlgTrinkets;
};

#endif // GIC_H
