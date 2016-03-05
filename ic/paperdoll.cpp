/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */

#include "gic.h"

QString gear_type_list_misc[] = {
    QString(),
};
QString gear_type_list_armor[] = {
    QString(),
    QString(),
    QString(),
};
QString gear_type_list_weapon[] = {
    QString(),
    QString(),
    QString(),
    QString(),
};
QString* gear_type_list[] = {
    gear_type_list_armor,
    gear_type_list_misc,
    gear_type_list_armor,
    gear_type_list_misc,
    gear_type_list_armor,
    gear_type_list_armor,
    gear_type_list_weapon,
    gear_type_list_weapon,
    gear_type_list_armor,
    gear_type_list_armor,
    gear_type_list_armor,
    gear_type_list_armor,
    gear_type_list_misc,
    gear_type_list_misc,
    gear_type_list_misc,
    gear_type_list_misc,
};

paperdoll_t::paperdoll_t(Ui::gicClass& ui) : selected_gear_slot(0), ui(&ui) {
    gear_type_list_armor[0] = QApplication::translate("gicClass", "Plate");
    gear_type_list_armor[1] = QApplication::translate("gicClass", "Mail/Leather/Cloth");
    gear_type_list_weapon[0] = QApplication::translate("gicClass", "2H Sword/Axe/Mace/Polearm");
    gear_type_list_weapon[1] = QApplication::translate("gicClass", "1H Sword/Axe/Mace/Fist");
    gear_type_list_weapon[2] = QApplication::translate("gicClass", "Dagger");
}

QString qsprint( int v ) {
    char buf[32];
    sprintf( buf, "%d", v );
    return buf;
}
QString qsprint( float v ) {
    char buf[32];
    sprintf( buf, "%.2f%%", v * 100.f );
    return buf;
}

void paperdoll_t::clear(){
    for (int i = 0; i < 16; i++) {
        gear_list[i] = item_t();
    }
    slot_switched();
    gear_summary_calculate();
}

void paperdoll_t::slot_switched(){
    if ( ui->radioHelm->isChecked() ) selected_gear_slot = 0;
    if ( ui->radioNeck->isChecked() ) selected_gear_slot = 1;
    if ( ui->radioShoulder->isChecked() ) selected_gear_slot = 2;
    if ( ui->radioBack->isChecked() ) selected_gear_slot = 3;
    if ( ui->radioChest->isChecked() ) selected_gear_slot = 4;
    if ( ui->radioWrist->isChecked() ) selected_gear_slot = 5;
    if ( ui->radioMainhand->isChecked() ) selected_gear_slot = 6;
    if ( ui->radioOffhand->isChecked() ) selected_gear_slot = 7;
    if ( ui->radioHand->isChecked() ) selected_gear_slot = 8;
    if ( ui->radioWaist->isChecked() ) selected_gear_slot = 9;
    if ( ui->radioLeg->isChecked() ) selected_gear_slot = 10;
    if ( ui->radioFeet->isChecked() ) selected_gear_slot = 11;
    if ( ui->radioFinger1->isChecked() ) selected_gear_slot = 12;
    if ( ui->radioFinger2->isChecked() ) selected_gear_slot = 13;
    if ( ui->radioTrinket1->isChecked() ) selected_gear_slot = 14;
    if ( ui->radioTrinket2->isChecked() ) selected_gear_slot = 15;
    ui->lblItemName->setText( QString( gear_list[selected_gear_slot].name.c_str() ) );
    ui->txtItemStr->setText( qsprint( gear_list[selected_gear_slot].str ) );
    ui->txtItemCrit->setText( qsprint( gear_list[selected_gear_slot].crit ) );
    ui->txtItemHaste->setText( qsprint( gear_list[selected_gear_slot].haste ) );
    ui->txtItemMastery->setText( qsprint( gear_list[selected_gear_slot].mastery ) );
    ui->txtItemMult->setText( qsprint( gear_list[selected_gear_slot].mult ) );
    ui->txtItemVers->setText( qsprint( gear_list[selected_gear_slot].vers ) );
    QString* p = gear_type_list[selected_gear_slot];
    ui->comboItemType->clear();
    while ( p->length() )
        ui->comboItemType->addItem( *p++ );
    ui->comboItemType->setCurrentIndex( gear_list[selected_gear_slot].type );
}

#define RACE_NONE 0
#define RACE_HUMAN 1
#define RACE_DWARF 2
#define RACE_GNOME 3
#define RACE_NIGHTELF_DAY 4
#define RACE_NIGHTELF_NIGHT 5
#define RACE_DRAENEI 6
#define RACE_WORGEN 7
#define RACE_ORC 8
#define RACE_TROLL 9
#define RACE_TAUREN 10
#define RACE_UNDEAD 11
#define RACE_BLOODELF 12
#define RACE_GOBLIN 13
#define RACE_PANDAREN 14

void paperdoll_t::gear_summary_calculate()
{
    char buf[32];
    int race = ui->comboRace->currentIndex();
    gear_list[selected_gear_slot].type = ui->comboItemType->currentIndex();
    gear_list[selected_gear_slot].str = ui->txtItemStr->text().toInt();
    gear_list[selected_gear_slot].crit = ui->txtItemCrit->text().toInt();
    gear_list[selected_gear_slot].haste = ui->txtItemHaste->text().toInt();
    gear_list[selected_gear_slot].mastery = ui->txtItemMastery->text().toInt();
    gear_list[selected_gear_slot].mult = ui->txtItemMult->text().toInt();
    gear_list[selected_gear_slot].vers = ui->txtItemVers->text().toInt();

    int plate_specialization = 1;
    int str = 0, crit = 0, haste = 0, mastery = 0, mult = 0, vers = 0, ap = 0;

    for ( int i = 0; i < 16; i++ ) {
        plate_specialization = plate_specialization && ( ( gear_type_list[i] != gear_type_list_armor ) || ( gear_list[i].type == 0 ) );
        str += gear_list[i].str;
        crit += gear_list[i].crit;
        haste += gear_list[i].haste;
        mastery += gear_list[i].mastery;
        mult += gear_list[i].mult;
        vers += gear_list[i].vers;
    }

    ui->tableGearSummary->setItem( 1, 1, new QTableWidgetItem( qsprint( str ) ) );
    ui->tableGearSummary->setItem( 3, 1, new QTableWidgetItem( qsprint( crit ) ) );
    ui->tableGearSummary->setItem( 4, 1, new QTableWidgetItem( qsprint( haste ) ) );
    ui->tableGearSummary->setItem( 5, 1, new QTableWidgetItem( qsprint( mastery ) ) );
    ui->tableGearSummary->setItem( 6, 1, new QTableWidgetItem( qsprint( mult ) ) );
    ui->tableGearSummary->setItem( 7, 1, new QTableWidgetItem( qsprint( vers ) ) );

    // set these parameters directly into libic kernel since they are costly to calculate.
    ic_setparam("gear_str", itoa(str, buf, 10));
    ic_setparam("gear_crit", itoa(crit, buf, 10));
    ic_setparam("gear_mastery", itoa(mastery, buf, 10));
    ic_setparam("gear_haste", itoa(haste, buf, 10));
    ic_setparam("gear_mult", itoa(mult, buf, 10));
    ic_setparam("gear_vers", itoa(vers, buf, 10));
    ic_setparam("plate_specialization", plate_specialization ? "1" : "0");

    if ( ui->checkRaidBuffFlask->isChecked() ) str += 250;
    if ( ui->checkRaidBuffFood->isChecked() ) crit += 125 * ( ui->comboRace->currentIndex() == 14 ? 2 : 1 );

    int racial_base_str[] = {
        0, 0, 5, -5, -4, -4, 66, 3, 3, 1, 5, -1, -3, -3, 0,
    };

    float fstr = str;
    float coeff = 1.0f;
    if ( plate_specialization ) coeff *= 1.05f;
    if ( ui->checkRaidBuffStr->isChecked() ) coeff *= 1.05f;
    str = ( int )( fstr * coeff );
    fstr = 1455; /* Base str @lvl 100. */
    fstr += racial_base_str[race]; /* Racial str. */
    str += ( int )( fstr * coeff );

    ap = str;
    if ( ui->checkRaidBuffAP->isChecked() ) ap = ( int )( ap * 1.1f + 0.5f );

    float fmastery = ( float )mastery;
    if ( ui->checkRaidBuffMastery->isChecked() ) fmastery += 550;
    fmastery = 1.4f * ( 0.08f + fmastery / 11000 );

    float fcrit = ( float )crit;
    fcrit *= 1.05f;
    fcrit = 0.05f + fcrit / 11000;
    if ( ui->checkRaidBuffCrit->isChecked() ) fcrit += 0.05f;
    if ( ( race == RACE_NIGHTELF_DAY ) || ( race == RACE_BLOODELF ) || ( race == RACE_WORGEN ) )
        fcrit += 0.01f;

    float fhaste = ( float )haste;
    fhaste = 1.0f + fhaste / 9000;
    if ( ui->checkRaidBuffHaste->isChecked() ) fhaste *= 1.05f;
    if ( ( race == RACE_NIGHTELF_NIGHT ) || ( race == RACE_GOBLIN ) || ( race == RACE_GNOME ) )
        fhaste *= 1.01f;
    fhaste = fhaste - 1.0f;

    float fmult = ( float )mult;
    fmult = fmult / 6600;
    if ( ui->checkRaidBuffMult->isChecked() ) fmult += 0.05f;

    float fvers = ( float )vers;
    if ( race == RACE_HUMAN ) fvers += 100;
    fvers = fvers / 13000;
    if ( ui->checkRaidBuffVers->isChecked() ) fvers += 0.03f;

    ui->tableGearSummary->setItem( 1, 2, new QTableWidgetItem( qsprint( str ) ) );
    ui->tableGearSummary->setItem( 2, 2, new QTableWidgetItem( qsprint( ap ) ) );
    ui->tableGearSummary->setItem( 3, 2, new QTableWidgetItem( qsprint( fcrit ) ) );
    ui->tableGearSummary->setItem( 4, 2, new QTableWidgetItem( qsprint( fhaste ) ) );
    ui->tableGearSummary->setItem( 5, 2, new QTableWidgetItem( qsprint( fmastery ) ) );
    ui->tableGearSummary->setItem( 6, 2, new QTableWidgetItem( qsprint( fmult ) ) );
    ui->tableGearSummary->setItem( 7, 2, new QTableWidgetItem( qsprint( fvers ) ) );
}