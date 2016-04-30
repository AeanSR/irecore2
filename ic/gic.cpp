/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "gic.h"
#include <QBitmap>
#include <QSplashScreen>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtConcurrent/QtConcurrent>
#include <ctime>

gic::gic( QWidget *parent )
    : QMainWindow( parent ), paperdoll( ui ) {
    // show splash.
    QPixmap pixmap( ":/gic/logo/splash.png" );
    QSplashScreen splash( pixmap );
    splash.setMask( pixmap.mask() );
    splash.show();
    ui.setupUi( this );

    // initialize libic kernel.
    ic_init();

    // qt interface setup.
    qRegisterMetaType<QString>( "QString" );
    ui.tabWidget->setCurrentIndex( 0 );
    dlgTrinkets = 0;
    dlgCharts = 0;
    static_this = this;
    ic_setprintcallback( &gic::vgicprintf );
    QSettings history;

    // show current version.
    QString ver_str( QApplication::translate( "gicClass", "  Current Version: ", 0 ) );
    ver_str.append( ic_getversion() );
    ui.lblVersion->setText( ver_str );

    // Add compute devices.
    int device_count = ic_devicecount();
    for (int i = 0; i < device_count; i++) {
        const char* dncstr;
        const char* pncstr;
        ic_deviceinfo( i, &pncstr, &dncstr );
        QString device_name( dncstr );
        device_name += " [";
        device_name += pncstr;
        device_name += "]";
        ui.comboDevices->addItem( device_name, i );
    }

    // Add RNG Engines.
    ui.comboRNG->addItem( "LCG32", 32 );
    ui.comboRNG->addItem( "MWC64X", 64 );
    ui.comboRNG->addItem( "MT127", 127 );

    // Add iterations.
    ui.comboIterations->addItem( "1", 1 );
    ui.comboIterations->addItem( "2,000", 2000 );
    ui.comboIterations->addItem( "10,000", 10000 );
    ui.comboIterations->addItem( "50,000", 50000 );
    ui.comboIterations->addItem( "100,000", 100000 );
    ui.comboIterations->addItem( "250,000", 250000 );
    ui.comboIterations->addItem( "1,000,000", 1000000 );
    ui.comboIterations->setCurrentIndex( 3 );

    // Combat length.
    ui.comboCombatLength->addItem( "30", 30 );
    ui.comboCombatLength->addItem( "120", 120 );
    ui.comboCombatLength->addItem( "180", 180 );
    ui.comboCombatLength->addItem( "210", 210 );
    ui.comboCombatLength->addItem( "240", 240 );
    ui.comboCombatLength->addItem( "270", 270 );
    ui.comboCombatLength->addItem( "300", 300 );
    ui.comboCombatLength->addItem( "330", 330 );
    ui.comboCombatLength->addItem( "450", 450 );
    ui.comboCombatLength->addItem( "600", 600 );
    ui.comboCombatLength->addItem( "720", 720 );
    ui.comboCombatLength->addItem( "900", 900 );
    ui.comboCombatLength->setCurrentIndex( 8 );

    // Vary combat length.
    ui.comboVaryCombatLength->addItem( "20", 20.0f );
    ui.comboVaryCombatLength->addItem( "10", 10.0f );
    ui.comboVaryCombatLength->addItem( "0", 0.0f );

    // Init health pct.
    ui.comboInitialHealthPercentage->addItem( "100", 100.0f );
    ui.comboInitialHealthPercentage->addItem( "19", 19.0f );

    // Death pct.
    ui.comboDeathPct->addItem( "0", 0.0f );
    ui.comboDeathPct->addItem( "10", 10.0f );
    ui.comboDeathPct->addItem( "21", 21.0f );

    // Num Enemies.
    for (int i = 1; i <= 20; i++) {
        ui.comboNumEnemies->addItem( QString::number( i ), i );
    }

    // Enemy Class.
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Aberration" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Beast" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Demon" ), 1 ); // 6.x: only demon matters.
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Dragonkin" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Elemental" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Giant" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Humanoid" ), 0 ); // default to this.
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Mechanical" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Undead" ), 0 );
    ui.comboEnemyClass->addItem( QApplication::translate( "gicClass", "Uncategorized" ), 0 );
    ui.comboEnemyClass->setCurrentIndex( 6 );

    ui.txtAPL->setPlainText( QString( std::string( ic_defaultapl() ).c_str() ) );

    // bn import region.
    ui.comboRegion->addItem( "cn" );
    ui.comboRegion->addItem( "us" );
    ui.comboRegion->addItem( "eu" );
    ui.comboRegion->addItem( "tw" );
    ui.comboRegion->addItem( "kr" );

    ui.comboImportActive->addItem( QApplication::translate( "gicClass", "Active Spec" ) );
    ui.comboImportActive->addItem( QApplication::translate( "gicClass", "Inactive Spec" ) );
    ui.comboImportActive->setCurrentIndex( 0 );

    std::vector<QString> spec_name;
    spec_name.resize( 3 );
    spec_name[SPEC_ARMS_WARRIOR] = QApplication::translate( "gicClass", "Arms Warrior" );
    spec_name[SPEC_FURY_WARRIOR] = QApplication::translate( "gicClass", "Fury Warrior" );
	spec_name[SPEC_RET_PALADIN] = QApplication::translate( "gicClass", "Retribution Paladin" );
	for (auto i = spec_name.begin(); i != spec_name.end(); i++) ui.comboSpec->addItem( *i );
    on_comboSpec_currentIndexChanged( 0 );

    // legendary rings.
    ui.comboIncandescence->addItem( QApplication::translate( "gicClass", "No Legendary Ring" ) );
    ui.comboIncandescence->addItem( QApplication::translate( "gicClass", "Incandescence(690)" ) );
    ui.comboIncandescence->addItem( QApplication::translate( "gicClass", "Greater Incandescence(715)" ) );
    ui.comboIncandescence->addItem( QApplication::translate( "gicClass", "Thorasus(735~795)" ) );
    ui.txtLegendaryRing->setEnabled( false );

    // weapon enchants.
    ui.comboMHEnchant->addItem( QApplication::translate( "gicClass", "No Enchantment." ) );
    ui.comboOHEnchant->addItem( QApplication::translate( "gicClass", "No Enchantment." ) );
    ui.comboMHEnchant->addItem( QApplication::translate( "gicClass", "Thunderlord" ) );
    ui.comboOHEnchant->addItem( QApplication::translate( "gicClass", "Thunderlord" ) );
    ui.comboMHEnchant->addItem( QApplication::translate( "gicClass", "Bleeding Hollow" ) );
    ui.comboOHEnchant->addItem( QApplication::translate( "gicClass", "Bleeding Hollow" ) );
    ui.comboMHEnchant->addItem( QApplication::translate( "gicClass", "Shattered Hand" ) );
    ui.comboOHEnchant->addItem( QApplication::translate( "gicClass", "Shattered Hand" ) );

    // trinket list.
    QStringList lists;
    lists <<
        QApplication::translate( "gicClass", "No Trinket Special." ) <<
        QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ) <<
        QApplication::translate( "gicClass", "Forgemaster's Insignia" ) <<
        QApplication::translate( "gicClass", "Horn of Screaming Spirits" ) <<
        QApplication::translate( "gicClass", "Scabbard of Kyanos" ) <<
        QApplication::translate( "gicClass", "Badge of Victory" ) <<
        QApplication::translate( "gicClass", "Insignia of Victory" ) <<
        QApplication::translate( "gicClass", "Tectus' Beating Heart" ) <<
        QApplication::translate( "gicClass", "Formidable Fang" ) <<
        QApplication::translate( "gicClass", "Draenic Stone" ) <<
        QApplication::translate( "gicClass", "Skull of War" ) <<
        QApplication::translate( "gicClass", "Mote of the Mountain" ) <<
        QApplication::translate( "gicClass", "Worldbreaker's Resolve" ) <<
        QApplication::translate( "gicClass", "Discordant Chorus" ) <<
        QApplication::translate( "gicClass", "Empty Drinking Horn" ) <<
        QApplication::translate( "gicClass", "Unending Hunger" ) <<
        QApplication::translate( "gicClass", "Spores of Alacrity" ) <<
        QApplication::translate( "gicClass", "Bonemaw's Big Toe" ) <<
        QApplication::translate( "gicClass", "Emberscale Talisman" ) <<
        QApplication::translate( "gicClass", "Gronntooth War Horn" ) <<
		QApplication::translate( "gicClass", "Libram of Vindication" );
    ui.comboTrinketSpecial1->addItems( lists );
    ui.comboTrinketSpecial2->addItems( lists );
    lists.clear();

    // race list.
    lists <<
        QApplication::translate( "gicClass", "Not set." ) <<
        QApplication::translate( "gicClass", "Human" ) <<
        QApplication::translate( "gicClass", "Dwarf" ) <<
        QApplication::translate( "gicClass", "Gnome" ) <<
        QApplication::translate( "gicClass", "Night Elf(day)" ) <<
        QApplication::translate( "gicClass", "Night Elf(night)" ) <<
        QApplication::translate( "gicClass", "Draenei" ) <<
        QApplication::translate( "gicClass", "Worgen" ) <<
        QApplication::translate( "gicClass", "Orc" ) <<
        QApplication::translate( "gicClass", "Troll" ) <<
        QApplication::translate( "gicClass", "Tauren" ) <<
        QApplication::translate( "gicClass", "Undead" ) <<
        QApplication::translate( "gicClass", "Blood Elf" ) <<
        QApplication::translate( "gicClass", "Goblin" ) <<
        QApplication::translate( "gicClass", "Pandaren" );
    ui.comboRace->addItems( lists );
    lists.clear();

    // gear summary
    ui.tableGearSummary->setItem( 1, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Strength" ) ) );
    ui.tableGearSummary->setItem( 2, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "AP" ) ) );
    ui.tableGearSummary->setItem( 3, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Crit" ) ) );
    ui.tableGearSummary->setItem( 4, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Haste" ) ) );
    ui.tableGearSummary->setItem( 5, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Mastery" ) ) );
    ui.tableGearSummary->setItem( 6, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Vers" ) ) );
    ui.tableGearSummary->setItem( 0, 1, new QTableWidgetItem( QApplication::translate( "gicClass", "Gear" ) ) );
    ui.tableGearSummary->setItem( 0, 2, new QTableWidgetItem( QApplication::translate( "gicClass", "Buffed" ) ) );

    // initialize paperdoll.
    ui.radioHelm->setChecked( true );
    paperdoll.clear();

    connect( ui.radioHelm, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioNeck, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioShoulder, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioBack, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioChest, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioWrist, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioMainhand, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioOffhand, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioHand, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioWaist, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioLeg, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioFeet, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioFinger1, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioFinger2, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioTrinket1, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );
    connect( ui.radioTrinket2, SIGNAL( toggled( bool ) ), this, SLOT( slot_switched() ) );

    connect( ui.txtItemStr, SIGNAL( textEdited( const QString& ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.txtItemCrit, SIGNAL( textEdited( const QString& ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.txtItemHaste, SIGNAL( textEdited( const QString& ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.txtItemMastery, SIGNAL( textEdited( const QString& ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.txtItemVers, SIGNAL( textEdited( const QString& ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.comboItemType, SIGNAL( activated( int ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.comboRace, SIGNAL( activated( int ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.checkRaidBuffFlask, SIGNAL( stateChanged( int ) ), this, SLOT( gear_summary_calculate() ) );
    connect( ui.checkRaidBuffFood, SIGNAL( stateChanged( int ) ), this, SLOT( gear_summary_calculate() ) );

    connect( ui.txtMHHigh, SIGNAL( textEdited( const QString& ) ), this, SLOT( mh_dps_calculate() ) );
    connect( ui.txtMHLow, SIGNAL( textEdited( const QString& ) ), this, SLOT( mh_dps_calculate() ) );
    connect( ui.txtMHSpeed, SIGNAL( textEdited( const QString& ) ), this, SLOT( mh_dps_calculate() ) );
    connect( ui.txtOHHigh, SIGNAL( textEdited( const QString& ) ), this, SLOT( oh_dps_calculate() ) );
    connect( ui.txtOHLow, SIGNAL( textEdited( const QString& ) ), this, SLOT( oh_dps_calculate() ) );
    connect( ui.txtOHSpeed, SIGNAL( textEdited( const QString& ) ), this, SLOT( oh_dps_calculate() ) );

    // setup policy tab
    on_radioIreCoreActions_toggled();
    on_radioSimCActions_toggled();
    on_radioDefaultActions_toggled();

    // setup task tab
    ui.tabPresetTask->setCurrentIndex( 0 );
    on_btnApplyPresetTask_clicked();

    // setup about tab.
    qulonglong startups = history.value( "statistics/startups", 0 ).toULongLong();
    history.setValue( "statistics/startups", ++startups );
    if (history.value( "statistics/first/version" ).isNull()) {
        history.setValue( "statistics/first/version", ic_getversion() );
        history.setValue( "statistics/first/date", QDateTime::currentDateTime() );
    }
    usage_statistics();

    // setup chart window.
    dlgCharts = new QChartDialog();
    uiCharts.setupUi( dlgCharts );
    dlgCharts->setQCP( uiCharts.customPlot );

    // show main window.
    splash.finish( this );
}

gic::~gic() {

}
void gic::usage_statistics() {
    QSettings history;
    int startups = history.value( "statistics/startups", 0 ).toInt();
    QDateTime first_date = history.value( "statistics/first/date" ).toDateTime();
    QString first_version = history.value( "statistics/first/version" ).toString();
    qlonglong days = first_date.daysTo( QDateTime::currentDateTime() );
    qulonglong tasks = history.value( "statistics/tasks", 0 ).toULongLong();
    qulonglong iterations = history.value( "statistics/iterations", 0 ).toULongLong();
    qulonglong cputime = history.value( "statistics/cputime", 0 ).toULongLong();
    qulonglong combatlength = history.value( "statistics/combatlength", 0 ).toULongLong();

    ui.lblStatisticFrom->setText( QApplication::translate( "gicClass", "Statistics From " ) + first_date.toString( Qt::DateFormat::SystemLocaleDate ) + " (ver. " + first_version + ")" );
    ui.lblStatisticDays->setText( QApplication::translate( "gicClass", "Days Elapsed: " ) + QString().setNum( days ) );
    ui.lblStatisticStartups->setText( QApplication::translate( "gicClass", "GUI Startups: " ) + QString().setNum( startups ) );
    ui.lblStatisticTasks->setText( QApplication::translate( "gicClass", "Total Tasks: " ) + QString().setNum( tasks ) );
    ui.lblStatisticIterations->setText( QApplication::translate( "gicClass", "Total Iterations: " ) + QString().setNum( iterations ) );

    QString text;
    const quint32 rates[] = { 1000, 60, 60, 24 };
    const QString units[] = { "ms", "s", "m", "h", "d" };
    if (cputime < 1000) {
        text = QString().setNum( cputime ) + "ms";
    } else {
        for (int i = 0; i < 4; i++) {
            text = units[i] + " " + text;
            text = QString().setNum( cputime % rates[i] ) + text;
            cputime = cputime / rates[i];
            if (cputime == 0) break;
        }
        if (cputime > 0) {
            text = units[4] + " " + text;
            text = QString().setNum( cputime ) + text;
        }
    }

    ui.lblStatisticCPUTime->setText( QApplication::translate( "gicClass", "Total Processor Time: " ) + text );

    text.clear();
    for (int i = 1; i < 4; i++) {
        text = units[i] + " " + text;
        text = QString().setNum( combatlength % rates[i] ) + text;
        combatlength = combatlength / rates[i];
        if (combatlength == 0) break;
    }
    if (combatlength > 0) {
        text = units[4] + " " + text;
        text = QString().setNum( combatlength ) + text;
    }

    ui.lblStatisticCombatLength->setText( QApplication::translate( "gicClass", "Total Combat Length: " ) + text );
}
void gic::mh_dps_calculate() {
    int mh_high = ui.txtMHHigh->text().toInt();
    int mh_low = ui.txtMHLow->text().toInt();
    float mh_speed = ui.txtMHSpeed->text().toFloat();
    if (mh_speed <= .0) mh_speed = 1.5;
    float mh_dps = ( mh_high + mh_low ) * 0.5 / mh_speed;
    char buf[32];
    sprintf( buf, "%.1f", mh_dps + 0.05 );
    ui.lblMHDPS->setText( buf );
}
void gic::oh_dps_calculate() {
    int oh_high = ui.txtOHHigh->text().toInt();
    int oh_low = ui.txtOHLow->text().toInt();
    float oh_speed = ui.txtOHSpeed->text().toFloat();
    if (oh_speed <= .0) oh_speed = 1.5;
    float oh_dps = ( oh_high + oh_low ) * 0.5 / oh_speed;
    char buf[32];
    sprintf( buf, "%.1f", oh_dps + 0.05 );
    ui.lblOHDPS->setText( buf );
}
void gic::gear_summary_calculate() {
    paperdoll.gear_summary_calculate();
}
void gic::slot_switched() {
    paperdoll.slot_switched();
}

void gic::set_parameters() {
    paperdoll.gear_summary_calculate();

    ic_setparam( "iterations", ui.comboIterations->currentData().toString().toLocal8Bit() );
    ic_setparam( "rng_engine", ui.comboRNG->currentText().toLower().toLocal8Bit() );
    ic_setparam( "deterministic_seed", ui.checkDeterministic->isChecked() ? "4262" : "0" );
    ic_setparam( "opencl_device_id", QString().setNum( ui.comboDevices->currentIndex() ).toLocal8Bit() );
    ic_setparam( "strict_gcd", ui.checkStrictGCD->isChecked() ? "1" : "0" );
    ic_setparam( "sync_melee", ui.checkSyncMelee->isChecked() ? "1" : "0" );
    ic_setparam( "wbr_never_expire", ui.checkWBRNeverExpire->isChecked() ? "1" : "0" );
    ic_setparam( "max_length", ui.comboCombatLength->currentData().toString().toLocal8Bit() );
    ic_setparam( "vary_combat_length", ui.comboVaryCombatLength->currentData().toString().toLocal8Bit() );
    ic_setparam( "initial_health_percentage", ui.comboInitialHealthPercentage->currentData().toString().toLocal8Bit() );
    ic_setparam( "death_pct", ui.comboDeathPct->currentData().toString().toLocal8Bit() );
    ic_setparam( "num_enemies", ui.comboNumEnemies->currentData().toString().toLocal8Bit() );
    ic_setparam( "raidbuff_bloodlust", ui.checkRaidBuffBloodlust->isChecked() ? "1" : "0" );
    ic_setparam( "raidbuff_flask", ui.checkRaidBuffFlask->isChecked() ? "1" : "0" );
    ic_setparam( "raidbuff_food", ui.checkRaidBuffFood->isChecked() ? "1" : "0" );
    ic_setparam( "raidbuff_potion", ui.checkRaidBuffPotion->isChecked() ? "1" : "0" );

    switch (ui.comboSpec->currentIndex()) {
    case SPEC_ARMS_WARRIOR:
        ic_setparam( "spec", "arms" );
		if (ui.comboRace->currentIndex() == 3)
			ic_setparam( "rage_max", "105" );
		else
			ic_setparam( "rage_max", "100" );
        break;
    case SPEC_FURY_WARRIOR:
        ic_setparam( "spec", "fury" );
		if (ui.comboRace->currentIndex() == 3)
			ic_setparam( "rage_max", "105" );
		else
			ic_setparam( "rage_max", "100" );
        break;
	case SPEC_RET_PALADIN:
		ic_setparam( "spec", "retribution" );
		ic_setparam( "rage_max", "5" );
		break;
    }

    QString talent;
    talent += QString().setNum( ui.comboTalent1->currentIndex() );
    talent += QString().setNum( ui.comboTalent2->currentIndex() );
    talent += QString().setNum( ui.comboTalent3->currentIndex() );
    talent += QString().setNum( ui.comboTalent4->currentIndex() );
    talent += QString().setNum( ui.comboTalent5->currentIndex() );
    talent += QString().setNum( ui.comboTalent6->currentIndex() );
    talent += QString().setNum( ui.comboTalent7->currentIndex() );
    ic_setparam( "talent", talent.toLocal8Bit() );

    ic_setparam( "race", race_str_param[ui.comboRace->currentIndex()] );
    ic_setparam( "trinket1", trinket_list[ui.comboTrinketSpecial1->currentIndex()] );
    ic_setparam( "trinket2", trinket_list[ui.comboTrinketSpecial2->currentIndex()] );
    ic_setparam( "trinket1_ilvl", ui.txtTrinketValue1->text().toLocal8Bit() );
    ic_setparam( "trinket2_ilvl", ui.txtTrinketValue2->text().toLocal8Bit() );
    ic_setparam( "enemy_is_demonic", ui.comboEnemyClass->currentData().toString().toLocal8Bit() );
    ic_setparam( "mh_high", ui.txtMHHigh->text().toLocal8Bit() );
    ic_setparam( "oh_high", ui.txtOHHigh->text().toLocal8Bit() );
    ic_setparam( "mh_low", ui.txtMHLow->text().toLocal8Bit() );
    ic_setparam( "oh_low", ui.txtOHLow->text().toLocal8Bit() );
    ic_setparam( "mh_speed", ui.txtMHSpeed->text().toLocal8Bit() );
    ic_setparam( "oh_speed", ui.txtOHSpeed->text().toLocal8Bit() );

    const char* weapon_type[] = {
        "1h", // WEAPONSUBCLASS_AXE_1H = 0,
        "2h", // WEAPONSUBCLASS_AXE_2H = 1,
        "2h", // WEAPONSUBCLASS_BOW = 2,
        "2h", // WEAPONSUBCLASS_GUN = 3,
        "1h", // WEAPONSUBCLASS_MACE_1H = 4,
        "2h", // WEAPONSUBCLASS_MACE_2H = 5,
        "2h", // WEAPONSUBCLASS_POLEARM = 6,
        "1h", // WEAPONSUBCLASS_SWORD_1H = 7,
        "2h", // WEAPONSUBCLASS_SWORD_2H = 8,
        "1h", // WEAPONSUBCLASS_WARGLAIVE = 9,
        "2h", // WEAPONSUBCLASS_STAFF = 10,
        "1h", // WEAPONSUBCLASS_BEAR_CLAW = 11,
        "1h", // WEAPONSUBCLASS_CAT_CLAW = 12,
        "1h", // WEAPONSUBCLASS_FIST_WEAPON = 13,
        "1h", // WEAPONSUBCLASS_MISC = 14,
        "dagger",// WEAPONSUBCLASS_DAGGER = 15,
    };
    ic_setparam( "mh_type", weapon_type[paperdoll.gear_list[6].type] );
    ic_setparam( "oh_type", weapon_type[paperdoll.gear_list[7].type] );

    ic_setparam( "t17_2pc", ui.checkT172P->isChecked() ? "1" : "0" );
    ic_setparam( "t17_4pc", ui.checkT174P->isChecked() ? "1" : "0" );
    ic_setparam( "t18_2pc", ui.checkT182P->isChecked() ? "1" : "0" );
    ic_setparam( "t18_4pc", ui.checkT184P->isChecked() ? "1" : "0" );
    ic_setparam( "archmages_incandescence", ( ui.comboIncandescence->currentIndex() == 1 ) ? "1" : "0" );
    ic_setparam( "archmages_greater_incandescence", ( ui.comboIncandescence->currentIndex() == 2 ) ? "1" : "0" );

    if (ui.comboIncandescence->currentIndex() == 3) {
        ic_setparam( "legendary_ring", ui.txtLegendaryRing->text().toLocal8Bit() );
    } else {
        ic_setparam( "legendary_ring", "0" );
    }
    if (ui.comboMHEnchant->currentIndex() == 0) ic_setparam( "mh_enchant", "none" );
    if (ui.comboMHEnchant->currentIndex() == 1) ic_setparam( "mh_enchant", "thunderlord" );
    if (ui.comboMHEnchant->currentIndex() == 2) ic_setparam( "mh_enchant", "bleedinghollow" );
    if (ui.comboMHEnchant->currentIndex() == 3) ic_setparam( "mh_enchant", "shatteredhand" );
    if (ui.comboOHEnchant->currentIndex() == 0) ic_setparam( "oh_enchant", "none" );
    if (ui.comboOHEnchant->currentIndex() == 1) ic_setparam( "oh_enchant", "thunderlord" );
    if (ui.comboOHEnchant->currentIndex() == 2) ic_setparam( "oh_enchant", "bleedinghollow" );
    if (ui.comboOHEnchant->currentIndex() == 3) ic_setparam( "oh_enchant", "shatteredhand" );
    ic_setparam( "actions", ui.txtAPL->toPlainText().toLocal8Bit() );
    ic_setparam( "default_actions", ui.radioDefaultActions->isChecked() ? "1" : "0" );

    if (ui.radioSimCActions->isChecked()) {
        ic_setparam( "simc_actions", ui.txtSimCAPL->toPlainText().toLocal8Bit() );
    } else {
        ic_setparam( "simc_actions", "" );
    }
}

void gic::on_listActions_itemDoubleClicked() {
    if (ui.listActions->currentItem())
        ui.txtAPL->textCursor().insertText( ui.listActions->currentItem()->text() );
}

void gic::on_listConditions_itemDoubleClicked() {
    if (ui.listConditions->currentItem())
        ui.txtAPL->textCursor().insertText( ui.listConditions->currentItem()->text() );
}

void gic::on_comboIncandescence_currentIndexChanged( int idx ) {
    ui.txtLegendaryRing->setEnabled( ui.comboIncandescence->currentIndex() == 3 );
}

void gic::on_comboSpec_currentIndexChanged( int idx ) {
    int t1 = ui.comboTalent1->currentIndex();
    int t2 = ui.comboTalent2->currentIndex();
    int t3 = ui.comboTalent3->currentIndex();
    int t4 = ui.comboTalent4->currentIndex();
    int t5 = ui.comboTalent5->currentIndex();
    int t6 = ui.comboTalent6->currentIndex();
    int t7 = ui.comboTalent7->currentIndex();
    ui.comboTalent1->clear();
    ui.comboTalent2->clear();
    ui.comboTalent3->clear();
    ui.comboTalent4->clear();
    ui.comboTalent5->clear();
    ui.comboTalent6->clear();
    ui.comboTalent7->clear();
    ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Not set." ) );
    if (idx == SPEC_ARMS_WARRIOR) {
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Dauntless" ) );
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Overpower" ) );
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Sweeping Strikes" ) );

        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Shockwave" ) );
        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Storm Bolt" ) );
        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Double Time" ) );

        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Fervor of Battle" ) );
        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Rend" ) );
        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Avatar" ) );

        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Second Wind" ) );
        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Bounding Stride" ) );
        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Die by the Sword" ) );

        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "In For The Kill" ) );
        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Mortal Combo" ) );
        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Bladestorm" ) );

        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Focused Rage" ) );
        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Trauma" ) );
        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Titanic Might" ) );

        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Anger Management" ) );
        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Opportunity Strikes" ) );
        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Ravager" ) );
    }
    if (idx == SPEC_FURY_WARRIOR) {
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "War Machine" ) );
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Endless Rage" ) );
        ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Fresh Meat" ) );

        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Shockwave" ) );
        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Storm Bolt" ) );
        ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Double Time" ) );

        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Wrecking Ball" ) );
        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Outburst" ) );
        ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Avatar" ) );

        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Furious Charge" ) );
        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Bounding Stride" ) );
        ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Warpaint" ) );

        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Massacre" ) );
        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Frothing Berserker" ) );
        ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Bladestorm" ) );

        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Meat Grinder" ) );
        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Frenzy" ) );
        ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Inner Rage" ) );

        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Carnage" ) );
        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Reckless Abandon" ) );
        ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Dragon Roar" ) );
    }
	if (idx == SPEC_RET_PALADIN) {
		ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Final Verdict" ) );
		ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Execution Sentence" ) );
		ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Consecration" ) );

		ui.comboTalent2->addItem( QApplication::translate( "gicClass", "The Fires of Justice" ) );
		ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Zeal" ) );
		ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Greater Judgment" ) );

		ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Fist of Judgment" ) );
		ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Repentance" ) );
		ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Blinding Light" ) );

		ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Virtue's Blade" ) );
		ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Blade of Wrath" ) );
		ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Divine Hammer" ) );

		ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Justicar's Vengeance" ) );
		ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Eye for an Eye" ) );
		ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Word of Glory" ) );

		ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Divine Intervention" ) );
		ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Divine Steed" ) );
		ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Seal of Light" ) );

		ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Divine Purpose" ) );
		ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Holy Wrath" ) );
		ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Equality" ) );
	}
    // Policy Action List.
    QStringList listWarrior, listArms, listFury;
    listWarrior << "SPELL(battle_cry);"
        << "SPELL(berserker_rage);"
        << "SPELL(heroic_leap)"
        << "SPELL(whirlwind);"
        << "SPELL(execute);"
        << "SPELL(potion);"
        << "SPELL(storm_bolt);"
        << "SPELL(shockwave);"
        << "SPELL(avatar);"
        << "SPELL(bladestorm);"
        << "SPELL(arcane_torrent);"
        << "SPELL(berserking);"
        << "SPELL(blood_fury);"
        << "SPELL(thorasus_the_stone_heart_of_draenor);"
        << "SPELL(vial_of_convulsive_shadows);"
        << "SPELL(scabbard_of_kyanos);"
        << "SPELL(badge_of_victory);"
        << "SPELL(bonemaws_big_toe);"
        << "SPELL(emberscale_talisman);";
    listFury << "SPELL(bloodthirst);"
        << "SPELL(raging_blow);"
        << "SPELL(furious_slash);"
        << "SPELL(rampage);"
        << "SPELL(dragon_roar);";
    listArms << "SPELL(cleave);"
        << "SPELL(colossus_smash);"
        << "SPELL(hamstring);"
        << "SPELL(mortal_strike);"
        << "SPELL(slam);"
        << "SPELL(overpower);"
        << "SPELL(rend);"
        << "SPELL(focused_rage);"
        << "SPELL(ravager);";
    ui.listActions->clear();
    if ( idx == SPEC_FURY_WARRIOR ) {
        ui.listActions->addItems( listFury );
		ui.listConditions->addItems( listWarrior );
    }
    if ( idx == SPEC_ARMS_WARRIOR ) {
        ui.listActions->addItems( listArms );
		ui.listConditions->addItems( listWarrior );
    }
    listWarrior.clear();
    listArms.clear();
    listFury.clear();
    listWarrior << "FROM_SECONDS()"
        << "rti->player.target"
        << "enemy_health_percent(rti)"
        << "rti->player.power"
        << "power_max"
        << "TIME_DISTANT(rti->expected_combat_length)"
        << "UP()"
        << "REMAIN()"
        << "battle_cry_expire"
        << "battle_cry_cd"
        << "berserker_rage_cd"
        << "heroic_leap_cd"
        << "potion_expire"
        << "potion_cd"
        << "shockwave_cd"
        << "storm_bolt_cd"
        << "avatar_expire"
        << "avatar_cd"
        << "bladestorm_expire"
        << "bladestorm_cd"
        << "incandescence_expire"
        << "thorasus_the_stone_heart_of_draenor_cd"
        << "thorasus_the_stone_heart_of_draenor_expire"
        << "arcane_torrent_cd"
        << "berserking_cd"
        << "berserking_expire"
        << "blood_fury_cd"
        << "blood_fury_expire";
    listArms << "cleave_cd"
        << "cleave_expire"
        << "cleave_stack"
        << "colossus_smash_cd"
        << "hamstring_cd"
        << "mortal_strike_cd"
        << "mortal_strike_charge"
        << "mortal_strike_maxcharge"
        << "overpower_expire"
        << "focused_rage_cd"
        << "focused_rage_stack"
        << "ravager_cd"
        << "ravager_expire"
        << "colossus_smash_expire(rti->player.target)"
        << "rend_expire(rti->player.target)";
    listFury << "bloodthirst_cd"
        << "enrage_expire"
        << "taste_for_blood_expire"
        << "taste_for_blood_stack"
        << "meat_cleaver_expire"
        << "wrecking_ball_expire"
        << "massacre_expire"
        << "frothing_berserker_expire"
        << "meat_grinder_expire"
        << "frenzy_expire"
        << "frenzy_stack"
        << "raging_blow_cd"
        << "dragon_roar_cd"
        << "dragon_roar_expire"
        << "rampage_expire"
        << "rampage_stack";
    ui.listConditions->clear();
    if ( idx == SPEC_FURY_WARRIOR ) {
		ui.listConditions->addItems( listWarrior );
		ui.listConditions->addItems( listFury );
    }
    if ( idx == SPEC_ARMS_WARRIOR ) {
		ui.listConditions->addItems( listWarrior );
        ui.listConditions->addItems( listArms );
    }
    ui.comboTalent1->setCurrentIndex( std::max( t1, 0 ) );
    ui.comboTalent2->setCurrentIndex( std::max( t2, 0 ) );
    ui.comboTalent3->setCurrentIndex( std::max( t3, 0 ) );
    ui.comboTalent4->setCurrentIndex( std::max( t4, 0 ) );
    ui.comboTalent5->setCurrentIndex( std::max( t5, 0 ) );
    ui.comboTalent6->setCurrentIndex( std::max( t6, 0 ) );
    ui.comboTalent7->setCurrentIndex( std::max( t7, 0 ) );
    gear_summary_calculate();
}

void gic::on_btnImport_clicked() {
    ui.btnImport->setDisabled( true );
    std::string region;
    std::string realm;
    std::string name;
    region = ui.comboRegion->currentText().toStdString();
    realm = ui.txtRealm->text().toStdString();
    name = ui.txtCharacter->text().toStdString();
    import_player( realm, name, region, ui.comboImportActive->currentIndex() == 0 );
    ui.btnImport->setDisabled( false );
}

void gic::on_btnGenerateDefaultAPL_clicked() {
    if (QMessageBox::question( this, QApplication::translate( "gicClass", "Generate Default APL" ),
        QApplication::translate( "gicClass", "This will overwrite texts of the editor. Are you sure?" ),
        QMessageBox::Ok | QMessageBox::Cancel ) == QMessageBox::Ok) {
        ui.radioIreCoreActions->setChecked( true );
        set_parameters();
        ui.txtAPL->setPlainText( QString( ic_defaultapl() ) );
    }
}

void gic::on_btnResetBuild_clicked() {
    ui.txtCharacter->clear();
    ui.txtRealm->clear();
    ui.txtItemCrit->clear();
    ui.txtItemHaste->clear();
    ui.txtItemMastery->clear();
    ui.txtItemStr->clear();
    ui.txtItemVers->clear();
    ui.txtLegendaryRing->clear();
    ui.txtMHHigh->clear();
    ui.txtMHLow->clear();
    ui.txtMHSpeed->clear();
    ui.txtOHHigh->clear();
    ui.txtOHLow->clear();
    ui.txtOHSpeed->clear();
    ui.txtTrinketValue1->clear();
    ui.txtTrinketValue2->clear();
    ui.comboIncandescence->setCurrentIndex( 0 );
    ui.comboItemType->setCurrentIndex( 0 );
    ui.comboMHEnchant->setCurrentIndex( 0 );
    ui.comboOHEnchant->setCurrentIndex( 0 );
    ui.comboRace->setCurrentIndex( 0 );
    ui.comboRegion->setCurrentIndex( 0 );
    ui.comboTalent1->setCurrentIndex( 0 );
    ui.comboTalent2->setCurrentIndex( 0 );
    ui.comboTalent3->setCurrentIndex( 0 );
    ui.comboTalent4->setCurrentIndex( 0 );
    ui.comboTalent5->setCurrentIndex( 0 );
    ui.comboTalent6->setCurrentIndex( 0 );
    ui.comboTalent7->setCurrentIndex( 0 );
    ui.comboTrinketSpecial1->setCurrentIndex( 0 );
    ui.comboTrinketSpecial2->setCurrentIndex( 0 );
    ui.checkT172P->setChecked( false );
    ui.checkT174P->setChecked( false );
    ui.checkT182P->setChecked( false );
    ui.checkT184P->setChecked( false );
    paperdoll.clear();
    ui.radioHelm->setChecked( true );
}

void gic::on_radioDefaultActions_toggled() {
    if (ui.radioDefaultActions->isChecked()) {

    }
}
void gic::on_radioIreCoreActions_toggled() {
    if (ui.radioIreCoreActions->isChecked()) {
        ui.txtAPL->show();
        ui.listActions->show();
        ui.listConditions->show();
        ui.btnGenerateDefaultAPL->setDisabled( false );
    } else {
        ui.txtAPL->hide();
        ui.listActions->hide();
        ui.listConditions->hide();
        ui.btnGenerateDefaultAPL->setDisabled( true );
    }
}
void gic::on_radioSimCActions_toggled() {
    if (ui.radioSimCActions->isChecked()) {
        ui.txtSimCAPL->show();
        ui.btnLoadFromFile->show();
    } else {
        ui.txtSimCAPL->hide();
        ui.btnLoadFromFile->hide();
    }
}
void gic::on_btnLoadFromFile_clicked() {
    QSettings history;
    QString filename = QFileDialog::getOpenFileName( this, tr( "Load From SimC Profile" ),
        history.value( "policy/loadfromsimc" ).toString(),
        tr( "SimC profile (*.simc);;All files (*.*)" ) );
    if (filename.isNull()) return;
    history.setValue( "policy/loadfromsimc", filename );
    QFile file( filename );

    file.open( QFile::ReadOnly | QFile::Text );

    QTextStream ReadFile( &file );
    ui.txtSimCAPL->setPlainText( ReadFile.readAll() );
}

void gic::on_btnApplyPresetTask_clicked() {
    if (!ui.txtScript->toPlainText().isEmpty())
        if (QMessageBox::question( this, QApplication::translate( "gicClass", "Apply Preset Task" ),
            QApplication::translate( "gicClass", "This will overwrite texts of the editor. Are you sure?" ),
            QMessageBox::Ok | QMessageBox::Cancel ) != QMessageBox::Ok) {
            return;
        }
    QString script;
    if (ui.tabPresetTask->currentIndex() == 0) {
        script = script_plain();
    }
    if (ui.tabPresetTask->currentIndex() == 1) {
        int stat_mask = 0;
        if (ui.checkScaleFactorStr->isChecked()) stat_mask |= 1;
        if (ui.checkScaleFactorCrit->isChecked()) stat_mask |= 2;
        if (ui.checkScaleFactorHaste->isChecked()) stat_mask |= 4;
        if (ui.checkScaleFactorMastery->isChecked()) stat_mask |= 8;
        if (ui.checkScaleFactorVers->isChecked()) stat_mask |= 16;
        script = script_scale_factor(
            ui.txtScaleFactorInverval->text().toInt(),
            ui.checkScaleFactorCentralDelta->isChecked(),
            stat_mask,
            ui.checkScaleFactorWDPS->isChecked(),
            ui.checkScaleFactorWOHDPS->isChecked()
            );
    }
    if (ui.tabPresetTask->currentIndex() == 2) {
        gear_summary_calculate();
        script = script_trinket_ladder(
            paperdoll.gear_list[14].str + paperdoll.gear_list[15].str,
            paperdoll.gear_list[14].crit + paperdoll.gear_list[15].crit,
            paperdoll.gear_list[14].haste + paperdoll.gear_list[15].haste,
            paperdoll.gear_list[14].mastery + paperdoll.gear_list[15].mastery,
            paperdoll.gear_list[14].vers + paperdoll.gear_list[15].vers
            );
    }
    if (ui.tabPresetTask->currentIndex() == 3) {
        double confidence = ui.txtDescentConfidenceLevel->text().toDouble() * 0.01;
        if (confidence >= 1.0 || confidence <= 0.5) {
            QMessageBox::information( this, QApplication::translate( "gicClass", "Apply Preset Task" ),
                QApplication::translate( "gicClass", "Confidence level should be in (50%, 100%). Set as 95%.\n" ),
                QMessageBox::Ok );
            confidence = 0.95;
        }
        script = script_stat_maxima(
            confidence,
            ui.txtDescentInitInterval->text().toInt(),
            ui.txtDescentMinInterval->text().toInt(),
            ui.txtDescentIterationLimit->text().toInt()
            );
    }
    if (ui.tabPresetTask->currentIndex() == 4) {
        int stat[5] = { 0 };
        int i = 0;
        if (ui.checkPlotCrit->isChecked()) stat[i++] = 0;
        if (ui.checkPlotHaste->isChecked()) stat[i++] = 1;
        if (ui.checkPlotMastery->isChecked()) stat[i++] = 2;
        if (ui.checkPlotVers->isChecked()) stat[i++] = 3;
        if (i != 3) {
            QMessageBox::information( this, QApplication::translate( "gicClass", "Apply Preset Task" ),
                QApplication::translate( "gicClass", "Contour Plot stats not set properly. Exact 3 stats should be checked.\nReset to Crit-Haste-Mastery.\n" ),
                QMessageBox::Ok );
            stat[0] = 0;
            stat[1] = 1;
            stat[2] = 2;
            ui.checkPlotCrit->setChecked( true );
            ui.checkPlotHaste->setChecked( true );
            ui.checkPlotMastery->setChecked( true );
            ui.checkPlotVers->setChecked( false );
        }
        script = script_contour_plot(
            ui.txtPlotInterval->text().toInt(),
            ui.txtPlotErrorTolerance->text().toDouble(),
            ui.txtPlotMaxIterationLimit->text().toInt(),
            stat[0], stat[1], stat[2]
            );
    }
    ui.txtScript->setPlainText( script );
}
void gic::on_btnSelectTrinkets_clicked() {
    if (!dlgTrinkets) {
        dlgTrinkets = new QDialog();
        uiTrinkets.setupUi( dlgTrinkets );
        connect( uiTrinkets.btnToggleAllTrinkets, SIGNAL( clicked( void ) ), this, SLOT( on_btnToggleAllTrinkets_clicked() ) );
        connect( uiTrinkets.btnToggleUpgradedTrinkets, SIGNAL( clicked( void ) ), this, SLOT( on_btnToggleUpgradedTrinkets_clicked() ) );
        connect( uiTrinkets.btnSelectTrinketsBtns, SIGNAL( accepted( void ) ), this, SLOT( on_btnSelectTrinketsBtns_accepted() ) );
        connect( uiTrinkets.btnSelectTrinketsBtns, SIGNAL( rejected( void ) ), this, SLOT( on_btnSelectTrinketsBtns_rejected() ) );
        uiTrinkets.btnSelectTrinketsBtns->button( QDialogButtonBox::Ok )->setText( tr( "Ok" ) );
        uiTrinkets.btnSelectTrinketsBtns->button( QDialogButtonBox::Cancel )->setText( tr( "Cancel" ) );
    }
    uiTrinkets.listTrinketList->clear();
    for (auto i = trinket_ladder().begin(); i != trinket_ladder().end(); i++) {
        QListWidgetItem* aitem = new QListWidgetItem( QString( "[" ) + QString::number( i->itemlvl ) + QString( "]" ) + i->name );
        aitem->setFlags( aitem->flags() | Qt::ItemIsUserCheckable );
        aitem->setCheckState( i->not_selected ? Qt::Unchecked : Qt::Checked );
        uiTrinkets.listTrinketList->addItem( aitem );
    }
    dlgTrinkets->show();
}

void gic::on_btnSelectTrinketsBtns_accepted() {
    for (int i = 0; i < trinket_ladder().size(); i++) {
        trinket_ladder()[i].not_selected = uiTrinkets.listTrinketList->item( i )->checkState() != Qt::Checked;
    }
    dlgTrinkets->hide();
}

void gic::on_btnSelectTrinketsBtns_rejected() {
    dlgTrinkets->hide();
}

void gic::on_btnToggleAllTrinkets_clicked() {
    static int toggle = 0;
    for (int i = 0; i < uiTrinkets.listTrinketList->count(); i++) {
        uiTrinkets.listTrinketList->item( i )->setCheckState( toggle ? Qt::Checked : Qt::Unchecked );
    }
    toggle = !toggle;
}

void gic::on_btnToggleUpgradedTrinkets_clicked() {
    static int toggle = 0;
    for (int i = 0; i < uiTrinkets.listTrinketList->count(); i++) {
        if (trinket_ladder()[i].upgrade)
            uiTrinkets.listTrinketList->item( i )->setCheckState( toggle ? Qt::Checked : Qt::Unchecked );
    }
    toggle = !toggle;
}
void gic::TxtBoxNotify( QString value ) {
    ui.txtResult->moveCursor( QTextCursor::End );
    ui.txtResult->insertPlainText( value );
}
gic* gic::static_this = 0;

int gic::vgicprintf( const char* format, va_list vl ) {
    QString text;
    text.vsprintf( format, vl );
    QMetaObject::invokeMethod( static_this, "TxtBoxNotify", Q_ARG( QString, text ) );
    return text.length();
}
int gic::printf( const char* format, ... ) {
    va_list vl;
    int ret;
    va_start( vl, format );
    ret = vgicprintf( format, vl );
    va_end( vl );
    return ret;
}
int gic::printq( QString text ) {
    QMetaObject::invokeMethod( static_this, "TxtBoxNotify", Q_ARG( QString, text ) );
    return text.length();
}

void gic::on_btnRun_clicked() {
    char header[80];
    time_t rawtime;
    time( &rawtime );
    struct tm* ts = localtime( &rawtime );
    strftime( header, 80, "============================== %H:%M:%S ==============================", ts );
    gic::printf( "%s\n", header );
    ui.tabWidget->setCurrentWidget( ui.tabResult );
    ui.btnRun->setDisabled( true );
    QtConcurrent::run( this, &gic::run_scripts );
    QSettings history;
    qulonglong tasks = history.value( "statistics/tasks", 0 ).toULongLong();
    tasks++;
    history.setValue( "statistics/tasks", tasks );
}