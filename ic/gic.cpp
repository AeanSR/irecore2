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

gic::gic(QWidget *parent)
    : QMainWindow(parent), paperdoll(ui)
{
    // show splash.
    QPixmap pixmap(":/gic/splash.png");
    QSplashScreen splash(pixmap);
    splash.setMask(pixmap.mask());
    splash.show();
    ui.setupUi(this);

    // initialize libic kernel.
    ic_init();

    // qt interface setup.
    qRegisterMetaType<QString>("QString");
    ui.tabWidget->setCurrentIndex(0);
    dlgTrinkets = 0;

    // show current version.
    QString ver_str(QApplication::translate("gicClass", "  Current Version: ", 0));
    ver_str.append(STRFILEVER);
    ver_str.append(" ");
    ver_str.append(__DATE__);
    ui.lblVersion->setText(ver_str);

    // Add compute devices.
    int device_count = ic_devicecount();
    for(int i = 0; i < device_count; i++){
        const char* dncstr;
        const char* pncstr;
        ic_deviceinfo(i, &pncstr, &dncstr);
        QString device_name(dncstr);
        device_name += " [";
        device_name += pncstr;
        device_name += "]";
        ui.comboDevices->addItem( device_name, i );
    }

    // Add RNG Engines.
    ui.comboRNG->addItem("LCG32", 32);
    ui.comboRNG->addItem("MWC64X", 64);
    ui.comboRNG->addItem("MT127", 127);

    // Add iterations.
    ui.comboIterations->addItem("1", 1);
    ui.comboIterations->addItem("2,000", 2000);
    ui.comboIterations->addItem("10,000", 10000);
    ui.comboIterations->addItem("50,000", 50000);
    ui.comboIterations->addItem("100,000", 100000);
    ui.comboIterations->addItem("250,000", 250000);
    ui.comboIterations->addItem("1,000,000", 1000000);
    ui.comboIterations->setCurrentIndex(3);

    // Combat length.
    ui.comboCombatLength->addItem("30", 30);
    ui.comboCombatLength->addItem("120", 120);
    ui.comboCombatLength->addItem("180", 180);
    ui.comboCombatLength->addItem("210", 210);
    ui.comboCombatLength->addItem("240", 240);
    ui.comboCombatLength->addItem("270", 270);
    ui.comboCombatLength->addItem("300", 300);
    ui.comboCombatLength->addItem("330", 330);
    ui.comboCombatLength->addItem("450", 450);
    ui.comboCombatLength->addItem("600", 600);
    ui.comboCombatLength->addItem("720", 720);
    ui.comboCombatLength->addItem("900", 900);
    ui.comboCombatLength->setCurrentIndex(8);

    // Vary combat length.
    ui.comboVaryCombatLength->addItem("20", 20.0f);
    ui.comboVaryCombatLength->addItem("10", 10.0f);
    ui.comboVaryCombatLength->addItem("0", 0.0f);

    // Init health pct.
    ui.comboInitialHealthPercentage->addItem("100", 100.0f);
    ui.comboInitialHealthPercentage->addItem("19", 19.0f);

    // Death pct.
    ui.comboDeathPct->addItem("0", 0.0f);
    ui.comboDeathPct->addItem("10", 10.0f);
    ui.comboDeathPct->addItem("21", 21.0f);

    // Num Enemies.
    for (int i = 1; i <= 20; i++) {
        ui.comboNumEnemies->addItem(QString::number(i), i);
    }

    // Policy Action List.
    QStringList lists;
    lists << "SPELL(bloodthirst);"
        << "SPELL(ragingblow);"
        << "SPELL(wildstrike);"
        << "SPELL(whirlwind);"
        << "SPELL(execute);"
        << "SPELL(potion);"
        << "SPELL(berserkerrage);"
        << "SPELL(recklessness);"
        << "SPELL(stormbolt);"
        << "SPELL(shockwave);"
        << "SPELL(dragonroar);"
        << "SPELL(ravager);"
        << "SPELL(siegebreaker);"
        << "SPELL(bladestorm);"
        << "SPELL(avatar);"
        << "SPELL(bloodbath);"
        << "SPELL(arcanetorrent);"
        << "SPELL(berserking);"
        << "SPELL(bloodfury);"
        << "SPELL(thorasus_the_stone_heart_of_draenor);"
        << "SPELL(vial_of_convulsive_shadows);"
        << "SPELL(scabbard_of_kyanos);"
        << "SPELL(badge_of_victory);"
        << "SPELL(bonemaws_big_toe);"
        << "SPELL(emberscale_talisman);";
    ui.listActions->addItems(lists);
    lists.clear();
    lists << "FROM_SECONDS()"
        << "rti->player.target"
        << "enemy_health_percent(rti)"
        << "rti->player.power"
        << "power_max"
        << "TIME_DISTANT(rti->expected_combat_length)"
        << "UP(bloodthirst.cd)"
        << "REMAIN(bloodthirst.cd)"
        << "rti->player.ragingblow.stack"
        << "REMAIN(ragingblow.expire)"
        << "rti->player.meatcleaver.stack"
        << "REMAIN(meatcleaver.expire)"
        << "REMAIN(enrage.expire)"
        << "rti->player.bloodsurge.stack"
        << "REMAIN(bloodsurge.expire)"
        << "UP(suddendeath.expire)"
        << "REMAIN(suddendeath.expire)"
        << "REMAIN(berserkerrage.cd)"
        << "UP(recklessness.expire)"
        << "REMAIN(recklessness.expire)"
        << "REMAIN(recklessness.cd)"
        << "REMAIN(stormbolt.cd)"
        << "REMAIN(shockwave.cd)"
        << "REMAIN(dragonroar.cd)"
        << "UP(avatar.expire)"
        << "REMAIN(avatar.expire)"
        << "REMAIN(avatar.cd)"
        << "UP(bloodbath.expire)"
        << "REMAIN(bloodbath.expire)"
        << "REMAIN(bloodbath.cd)"
        << "UP(bladestorm.expire)"
        << "REMAIN(bladestorm.expire)"
        << "REMAIN(bladestorm.cd)"
        << "UP(ravager.expire)"
        << "REMAIN(ravager.expire)"
        << "REMAIN(ravager.cd)"
        << "REMAIN(siegebreaker.cd)"
        << "UP(potion.expire)"
        << "REMAIN(potion.expire)"
        << "REMAIN(potion.cd)"
        << "UP(thorasus_the_stone_heart_of_draenor.expire)"
        << "REMAIN(thorasus_the_stone_heart_of_draenor.expire)"
        << "REMAIN(thorasus_the_stone_heart_of_draenor.cd)";
    ui.listConditions->addItems(lists);
    lists.clear();
    ui.txtAPL->setPlainText(QString(std::string(ic_defaultapl()).c_str()));

    // bn import region.
    ui.comboRegion->addItem("cn");
    ui.comboRegion->addItem("us");
    ui.comboRegion->addItem("eu");
    ui.comboRegion->addItem("tw");
    ui.comboRegion->addItem("kr");

    // legendary rings.
    ui.comboIncandescence->addItem(QApplication::translate("gicClass", "No Legendary Ring"));
    ui.comboIncandescence->addItem(QApplication::translate("gicClass", "Incandescence(690)"));
    ui.comboIncandescence->addItem(QApplication::translate("gicClass", "Greater Incandescence(715)"));
    ui.comboIncandescence->addItem(QApplication::translate("gicClass", "Thorasus(735~795)"));
    ui.txtLegendaryRing->setEnabled(false);

    // weapon enchants.
    ui.comboMHEnchant->addItem(QApplication::translate("gicClass", "No Enchantment."));
    ui.comboOHEnchant->addItem(QApplication::translate("gicClass", "No Enchantment."));
    ui.comboMHEnchant->addItem(QApplication::translate("gicClass", "Thunderlord"));
    ui.comboOHEnchant->addItem(QApplication::translate("gicClass", "Thunderlord"));
    ui.comboMHEnchant->addItem(QApplication::translate("gicClass", "Bleeding Hollow"));
    ui.comboOHEnchant->addItem(QApplication::translate("gicClass", "Bleeding Hollow"));
    ui.comboMHEnchant->addItem(QApplication::translate("gicClass", "Shattered Hand"));
    ui.comboOHEnchant->addItem(QApplication::translate("gicClass", "Shattered Hand"));

    // trinket list.
    lists <<
        QApplication::translate("gicClass", "No Trinket Special.") <<
        QApplication::translate("gicClass", "Vial of Convulsive Shadows") <<
        QApplication::translate("gicClass", "Forgemaster's Insignia") <<
        QApplication::translate("gicClass", "Horn of Screaming Spirits") <<
        QApplication::translate("gicClass", "Scabbard of Kyanos") <<
        QApplication::translate("gicClass", "Badge of Victory") <<
        QApplication::translate("gicClass", "Insignia of Victory") <<
        QApplication::translate("gicClass", "Tectus' Beating Heart") <<
        QApplication::translate("gicClass", "Formidable Fang") <<
        QApplication::translate("gicClass", "Draenic Stone") <<
        QApplication::translate("gicClass", "Skull of War") <<
        QApplication::translate("gicClass", "Mote of the Mountain") <<
        QApplication::translate("gicClass", "Worldbreaker's Resolve") <<
        QApplication::translate("gicClass", "Discordant Chorus") <<
        QApplication::translate("gicClass", "Empty Drinking Horn") <<
        QApplication::translate("gicClass", "Unending Hunger") <<
        QApplication::translate("gicClass", "Spores of Alacrity") <<
        QApplication::translate("gicClass", "Bonemaw's Big Toe") <<
        QApplication::translate("gicClass", "Emberscale Talisman") <<
        QApplication::translate("gicClass", "Gronntooth War Horn");
    ui.comboTrinketSpecial1->addItems(lists);
    ui.comboTrinketSpecial2->addItems(lists);
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

    // talents.
    ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Juggernaut" ) );
    ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Double Time" ) );
    ui.comboTalent1->addItem( QApplication::translate( "gicClass", "Warbringer" ) );

    ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Enraged Regeneration" ) );
    ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Second Wind" ) );
    ui.comboTalent2->addItem( QApplication::translate( "gicClass", "Impending Victory" ) );

    ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Furious Strike" ) );
    ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Sudden Death" ) );
    ui.comboTalent3->addItem( QApplication::translate( "gicClass", "Unquenchable Thirst" ) );

    ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Storm Bolt" ) );
    ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Shockwave" ) );
    ui.comboTalent4->addItem( QApplication::translate( "gicClass", "Dragon Roar" ) );

    ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Mass Spell Reflection" ) );
    ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Safeguard" ) );
    ui.comboTalent5->addItem( QApplication::translate( "gicClass", "Vigilance" ) );

    ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Avatar" ) );
    ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Bloodbath" ) );
    ui.comboTalent6->addItem( QApplication::translate( "gicClass", "Bladestorm" ) );

    ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Not set." ) );
    ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Anger Management" ) );
    ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Ravager" ) );
    ui.comboTalent7->addItem( QApplication::translate( "gicClass", "Siegebreaker" ) );

    // gear summary
    ui.tableGearSummary->setItem( 1, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Strength" ) ) );
    ui.tableGearSummary->setItem( 2, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "AP" ) ) );
    ui.tableGearSummary->setItem( 3, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Crit" ) ) );
    ui.tableGearSummary->setItem( 4, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Haste" ) ) );
    ui.tableGearSummary->setItem( 5, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Mastery" ) ) );
    ui.tableGearSummary->setItem( 6, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Mult" ) ) );
    ui.tableGearSummary->setItem( 7, 0, new QTableWidgetItem( QApplication::translate( "gicClass", "Vers" ) ) );
    ui.tableGearSummary->setItem( 0, 1, new QTableWidgetItem( QApplication::translate( "gicClass", "Gear" ) ) );
    ui.tableGearSummary->setItem( 0, 2, new QTableWidgetItem( QApplication::translate( "gicClass", "Buffed" ) ) );

    // initialize paperdoll.
    paperdoll.slot_switched();

    // show main window.
    splash.finish(this);
}

gic::~gic()
{

}
