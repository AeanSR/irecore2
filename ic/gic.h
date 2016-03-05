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
#include <QSettings>
#include <QMessageBox>
#include <QDateTime>
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
    void gear_summary_calculate();
    void clear();
};

class gic : public QMainWindow
{
    Q_OBJECT

public:
    paperdoll_t paperdoll;
    gic(QWidget *parent = 0);
    ~gic();
    static int vgicprintf(const char* format, va_list vl);

public slots:
    void slot_switched();
    void gear_summary_calculate();
    void mh_dps_calculate();
    void oh_dps_calculate();
    void set_parameters();
    void usage_statistics();
    //void on_btnRun_clicked();
    void on_btnLoadFromFile_clicked();
    void on_btnImport_clicked();
    void on_btnResetBuild_clicked();
    void on_btnGenerateDefaultAPL_clicked();
    void on_listActions_itemDoubleClicked();
    void on_listConditions_itemDoubleClicked();
    void on_btnApplyPresetTask_clicked();
    //void on_btnSelectTrinkets_clicked();
    //void on_btnSelectTrinketsBtns_accepted();
    //void on_btnSelectTrinketsBtns_rejected();
    //void on_btnSelectAllTrinkets_clicked();
    //void on_btnSelectNoneTrinkets_clicked();
    void on_comboIncandescence_currentIndexChanged( int );
    void TxtBoxNotify( QString );
    void on_radioDefaultActions_toggled();
    void on_radioIreCoreActions_toggled();
    void on_radioSimCActions_toggled();

private:
    Ui::gicClass ui;
    QDialog* dlgTrinkets;
    static Ui::gicClass* static_ui;
};

#endif // GIC_H
