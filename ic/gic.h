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
    static int printf(const char* format, ...);
    static int printq(QString text);
    void run_scripts();

public slots:
    void slot_switched();
    void gear_summary_calculate();
    void mh_dps_calculate();
    void oh_dps_calculate();
    void set_parameters();
    void usage_statistics();
    void on_btnRun_clicked();
    void on_btnLoadFromFile_clicked();
    void on_btnImport_clicked();
    void on_btnResetBuild_clicked();
    void on_btnGenerateDefaultAPL_clicked();
    void on_listActions_itemDoubleClicked();
    void on_listConditions_itemDoubleClicked();
    void on_btnApplyPresetTask_clicked();
    void on_btnSelectTrinkets_clicked();
    void on_btnSelectTrinketsBtns_accepted();
    void on_btnSelectTrinketsBtns_rejected();
    void on_btnToggleAllTrinkets_clicked();
    void on_btnToggleUpgradedTrinkets_clicked();
    void on_comboIncandescence_currentIndexChanged( int );
    void TxtBoxNotify( QString );
    void on_radioDefaultActions_toggled();
    void on_radioIreCoreActions_toggled();
    void on_radioSimCActions_toggled();

private:
    Ui::gicClass ui;
    Ui::dlgTrinkets uiTrinkets;
    QDialog* dlgTrinkets;
    static gic* static_this;
};

struct trinket_profile_t {
    QString name;
    int itemid;
    int itemlvl;
    int str;
    int crit;
    int haste;
    int mastery;
    int mult;
    int vers;
    int demonic;
    int upgrade;
    int not_selected;
    trinket_profile_t( QString name, int itemid, int itemlvl, int str, int crit, int haste, int mastery, int mult, int vers, int upgrade = 0, int demonic = -1 ) :
        name( name ), itemid( itemid ), itemlvl( itemlvl ), str( str ), crit( crit ), haste( haste ), mastery( mastery ), mult( mult ), vers( vers ), upgrade(upgrade), demonic( demonic ), not_selected( 0 )
    {};
};
struct trinket_ladder_t {
    std::vector<trinket_profile_t> list;
    trinket_ladder_t();
};
std::vector<trinket_profile_t>& trinket_ladder();

QString script_plain();
QString script_scale_factor(
    int scale_delta,
    bool center_scale_delta,
    int scale_stat_mask,
    bool scale_mh,
    bool scale_oh
);
QString script_trinket_ladder(
    int trinket_slot_str,
    int trinket_slot_crit,
    int trinket_slot_haste,
    int trinket_slot_mastery,
    int trinket_slot_mult,
    int trinket_slot_vers
);
#endif // GIC_H
