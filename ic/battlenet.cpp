/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "gic.h"
#include "document.h"
#include "stringbuffer.h"
#include "prettywriter.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QUrl>

#define API_KEY "nyv354w3rnf3jf95ryn5ddmyar933pzw"

class getjson {

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply* reply;
    gic* pg;
public:
    void set_url( QString& surl ) {
        url.setUrl( surl, QUrl::ParsingMode::TolerantMode );
    }
    void set_parent( gic* _pg ) {
        pg = _pg;
    }
    rapidjson::Document get();
};

rapidjson::Document getjson::get() {
    reply = qnam.get( QNetworkRequest( url ) );

    QEventLoop loop;
    QApplication::connect( reply, SIGNAL( finished() ), &loop, SLOT( quit() ) );
    loop.exec();

    QString doc( reply->readAll() );
    rapidjson::Document j;

    if (reply->error()) {
        QMessageBox::information( pg, QApplication::translate( "gicClass", "Import Fail" ), QApplication::translate( "gicClass", "Cannot connect Battle.Net:\n" ) + url.toString(), QMessageBox::Ok );
        return j;
    }

    j.Parse( doc.toStdString().c_str() );

    return j;
}

QString qsprint( int v );

/*int gic::retrive_item_subclass(int id, std::string& region){
    getjson bn;
    QString url;
    char buf[32];
    bn.set_parent(this);
    if (region.compare("cn")){
        url = "https://us.api.battle.net/wow/item/";
    }
    else{
        url = "https://api.battlenet.com.cn/wow/item/";
    }
    url.append(itoa(id, buf, 10));
    url.append("?locale=en_US&apikey=");
    url.append(API_KEY);
    bn.set_url(url);
    rapidjson::Document j = bn.get();

    if (j["availableContexts"][0].GetStringLength()){
        if (region.compare("cn")){
            url = "https://us.api.battle.net/wow/item/";
        }
        else{
            url = "https://api.battlenet.com.cn/wow/item/";
        }
        url.append(itoa(id, buf, 10));
        url.append("/");
        url.append(j["availableContexts"][0].GetString());
        url.append("?locale=en_US&apikey=");
        url.append(API_KEY);
        bn.set_url(url);
        j = bn.get();
    }


    int itemClass = j["itemClass"].GetInt();
    qDebug() << url << " " << itemClass << " " << j["itemSubClass"].GetInt();

    if (itemClass == 4){
        return (j["itemSubClass"].GetInt() == 4) ? 0 : 1;
    }
    else if (itemClass == 2){
        switch (j["itemSubClass"].GetInt()){
        case 0: case 4: case 7: case 13:
            return 1;
        case 1: case 5: case 6: case 8: case 10:
            return 0;
        case 15: default:
            return 2;
        }
    }
    else{
        return 0;
    }
}*/

// stat 4,71,72,74 -> strength
//      32 -> crit
//      36 -> haste
//      49 -> mastery
//      59 -> multistrike
//      40 -> versatility
int gic::import_player( std::string& realm, std::string& name, std::string& region, int active, int silence ) {
    PRINTB( "func call: %s, %s, %s, %d.", realm.c_str(), name.c_str(), region.c_str(), active );
    getjson bn;
    QString url;
    int talent;
    int race;
    int spec;
    int archmages_incandescence;
    int archmages_greater_incandescence;
    int legendary_ring;
    int t17_2pc;
    int t17_4pc;
    int t18_2pc;
    int t18_4pc;
    int mh_low;
    int mh_high;
    int oh_low;
    int oh_high;
    float mh_speed;
    float oh_speed;

    bn.set_parent( this );
    if (region.compare( "cn" )) {
        url = "https://";
        url.append( region.c_str() );
        url.append( ".api.battle.net/wow/character/" );
        url.append( realm.c_str() );
        url.append( "/" );
        url.append( name.c_str() );
        url.append( "?fields=talents,items&locale=en_US&apikey=" );
        url.append( API_KEY );
    } else {
        url = "https://api.battlenet.com.cn/wow/character/";
        url.append( realm.c_str() );
        url.append( "/" );
        url.append( name.c_str() );
        url.append( "?fields=talents,items&apikey=" );
        url.append( API_KEY );
    }
    bn.set_url( url );
    rapidjson::Document j = bn.get();
    int class_id = j["class"].GetInt();
    if (class_id != 1 && class_id != 2) {
        if (!silence)
            QMessageBox::information( this, QApplication::translate( "gicClass", "Import Fail" ), QApplication::translate( "gicClass", "This character's class is not supported by IreCore." ), QMessageBox::Ok );
        return -1;
    }
    if (j["level"].GetInt() != 100) {
        if (!silence)
            QMessageBox::information( this, QApplication::translate( "gicClass", "Import Fail" ), QApplication::translate( "gicClass", "This character is not 100 lvl." ), QMessageBox::Ok );
        return -1;
    }
    rapidjson::Value& jtalentlist = j["talents"];
    talent = -1;
    for (int i = 0; i < jtalentlist.Size(); i++) {
        if (( jtalentlist[i]["selected"].GetBool() == !!active )) {
            if (class_id == 1 && 0 == std::string( "Z" ).compare( jtalentlist[i]["calcSpec"].GetString() )) {
                spec = SPEC_FURY_WARRIOR;
            } else if (class_id == 1 && 0 == std::string( "a" ).compare( jtalentlist[i]["calcSpec"].GetString() )) {
                spec = SPEC_ARMS_WARRIOR;
            } else if (class_id == 2 && 0 == std::string( "b" ).compare( jtalentlist[i]["calcSpec"].GetString() )) {
                spec = SPEC_RET_PALADIN;
            } else {
                if (!silence)
                    QMessageBox::information( this, QApplication::translate( "gicClass", "Import Fail" ), QApplication::translate( "gicClass", "Selected specialization is not a valid DPS spec. Try toggle the \"active\" option?" ), QMessageBox::Ok );
                return -1;
            }
            std::string calcTalent = jtalentlist[i]["calcTalent"].GetString();
            talent = 0;
            for (int k = 0; k < 7; k++) {
                talent *= 10;
                switch (calcTalent.length() > k ? calcTalent[k] : '.') {
                case '0': talent += 1; break;
                case '1': talent += 2; break;
                case '2': talent += 3; break;
                default: break;
                }
            }
            // glyph_ur = !!strchr( jtalentlist[i]["calcGlyph"].GetString(), 'c' );
            // glyph_of_ragingwind = !!strchr( jtalentlist[i]["calcGlyph"].GetString(), 'Q' );
        }
    }
    if (talent < 0) {
        if (!silence)
            QMessageBox::information( this, QApplication::translate( "gicClass", "Import Fail" ), QApplication::translate( "gicClass", "Selected specialization does not exist. Try toggle the \"active\" option?" ), QMessageBox::Ok );
        return -1;
    }
    switch (j["race"].GetInt()) {
    case 1: race = 1; break;
    case 3: race = 2; break;
    case 7: race = 3; break;
    case 4: race = 4; break;
    case 11: race = 6; break;
    case 22: race = 7; break;
    case 2: race = 8; break;
    case 8: race = 9; break;
    case 6: race = 10; break;
    case 5: race = 11; break;
    case 10: race = 12; break;
    case 9: race = 13; break;
    case 24: case 25: case 26: race = 14; break;
    default: race = 0;
    }
    rapidjson::Value& items = j["items"];
    static const char* slotname[] = {
        "head", "neck", "shoulder", "back", "chest", "wrist", "mainHand", "offHand",
        "hands", "waist", "legs", "feet", "finger1", "finger2", "trinket1", "trinket2",
    };
    static const int plate_slot[] = {
        1, 0, 1, 0, 1, 1, 0, 0,
        1, 1, 1, 1, 0, 0, 0, 0,
    };
    int t17_count = 0;
    int t18_count = 0;
    archmages_greater_incandescence = 0;
    archmages_incandescence = 0;
    legendary_ring = 0;
    mh_low = 0;
    mh_high = 0;
    oh_low = 0;
    oh_high = 0;
    mh_speed = 0;
    oh_speed = 0;
    ui.comboTrinketSpecial1->setCurrentIndex( 0 );
    ui.comboTrinketSpecial2->setCurrentIndex( 0 );
    ui.txtTrinketValue1->clear();
    ui.txtTrinketValue2->clear();

    for (int i = 0; i < 16; i++) {
        paperdoll.gear_list[i] = item_t();
        rapidjson::Value& item = items[slotname[i]];
        int itemid = item["id"].GetInt();
        if (itemid == 0) continue;
        int itemlvl = item["itemLevel"].GetInt();
        paperdoll.gear_list[i].name = item["name"].GetString();
        if (itemid >= 115580 && itemid <= 115584) t17_count++;
        if (itemid >= 115565 && itemid <= 115569) t17_count++;
        if (itemid == 124319 || itemid == 124329 || itemid == 124334 || itemid == 124340 || itemid == 124346) t18_count++;
        if (itemid == 124318 || itemid == 124328 || itemid == 124333 || itemid == 124339 || itemid == 124345) t18_count++;
        if (itemid == 118305) archmages_greater_incandescence = 1;
        if (itemid == 118300) archmages_incandescence = 1;
        if (itemid == 124634) {
            legendary_ring = itemlvl;
        }
        if (i == 14 || i == 15) { /* Trinket setup */
            QComboBox* combo = ( i == 14 ) ? ui.comboTrinketSpecial1 : ui.comboTrinketSpecial2;
            QLineEdit* input = ( i == 14 ) ? ui.txtTrinketValue1 : ui.txtTrinketValue2;
            combo->setCurrentIndex( trinket_from_id( itemid ) );
            input->setText( qsprint( itemlvl ) );
        }
        rapidjson::Value& piecestat = item["stats"];
        for (int k = 0; k < piecestat.Size(); k++) {
            switch (piecestat[k]["stat"].GetInt()) {
            case 5: if (itemid != 124545) break; /* Chipped Soul Prism uses 5 for Str/Agi/Int, which is only for Int on other items. */
            case 71:
            case 4: case 72: case 74: paperdoll.gear_list[i].str += piecestat[k]["amount"].GetInt(); break;
            case 32: paperdoll.gear_list[i].crit += piecestat[k]["amount"].GetInt(); break;
            case 36: paperdoll.gear_list[i].haste += piecestat[k]["amount"].GetInt(); break;
            case 49: paperdoll.gear_list[i].mastery += piecestat[k]["amount"].GetInt(); break;
                // case 59: paperdoll.gear_list[i].mult += piecestat[k]["amount"].GetInt(); break;
            case 40: paperdoll.gear_list[i].vers += piecestat[k]["amount"].GetInt(); break;
            default: break;
            }
        }
        rapidjson::Value& pieceench = item["tooltipParams"];
        int gemid = pieceench["gem0"].GetInt();
        if (gemid) {
            for (int prop_idx = 0; prop_idx < 3; prop_idx++) {
                int ench_stat = dbc_query_gem_prop( gemid, prop_idx );
                int ench_value = dbc_query_gem_value( gemid, prop_idx );
                switch (ench_stat) {
                case 71:
                case 4: case 72: case 74: paperdoll.gear_list[i].str += ench_value; break;
                case 32: paperdoll.gear_list[i].crit += ench_value; break;
                case 36: paperdoll.gear_list[i].haste += ench_value; break;
                case 49: paperdoll.gear_list[i].mastery += ench_value; break;
                    // case 59: paperdoll.gear_list[i].mult += ench_value; break;
                case 40: paperdoll.gear_list[i].vers += ench_value; break;
                default: break;
                }
            }
        }
        int enchid = pieceench["enchant"].GetInt();
        if (i == 6) {
            if (enchid == 5330) ui.comboMHEnchant->setCurrentIndex( 1 );
            else if (enchid == 5384) ui.comboMHEnchant->setCurrentIndex( 2 );
            else if (enchid == 5331) ui.comboMHEnchant->setCurrentIndex( 3 );
            else ui.comboMHEnchant->setCurrentIndex( 0 );
            mh_low = item["weaponInfo"]["damage"]["min"].GetInt();
            mh_high = item["weaponInfo"]["damage"]["max"].GetInt();
            mh_speed = item["weaponInfo"]["weaponSpeed"].GetDouble();
            paperdoll.gear_list[i].type = dbc_query_weapon_type( itemid );
        }
        if (i == 7) {
            if (enchid == 5330) ui.comboOHEnchant->setCurrentIndex( 1 );
            else if (enchid == 5384) ui.comboOHEnchant->setCurrentIndex( 2 );
            else if (enchid == 5331) ui.comboOHEnchant->setCurrentIndex( 3 );
            else ui.comboOHEnchant->setCurrentIndex( 0 );
            oh_low = item["weaponInfo"]["damage"]["min"].GetInt();
            oh_high = item["weaponInfo"]["damage"]["max"].GetInt();
            oh_speed = item["weaponInfo"]["weaponSpeed"].GetDouble();
            paperdoll.gear_list[i].type = dbc_query_weapon_type( itemid );
        }
        if (enchid) {
            for (int prop_idx = 0; prop_idx < 3; prop_idx++) {
                int ench_stat = dbc_query_enchantment_prop( enchid, prop_idx );
                int ench_value = dbc_query_enchantment_value( enchid, prop_idx );
                switch (ench_stat) {
                case 4: case 71: case 72: case 74: paperdoll.gear_list[i].str += ench_value; break;
                case 32: paperdoll.gear_list[i].crit += ench_value; break;
                case 36: paperdoll.gear_list[i].haste += ench_value; break;
                case 49: paperdoll.gear_list[i].mastery += ench_value; break;
                    // case 59: paperdoll.gear_list[i].mult += ench_value; break;
                case 40: paperdoll.gear_list[i].vers += ench_value; break;
                default: break;
                }
            }
        }
        if (plate_slot[i]) {
            paperdoll.gear_list[i].type = dbc_query_armor_type( itemid );
        }
    }

    ui.comboRace->setCurrentIndex( race );
    slot_switched();
    gear_summary_calculate();
    if (legendary_ring) {
        ui.comboIncandescence->setCurrentIndex( 3 );
        ui.txtLegendaryRing->setText( qsprint( legendary_ring ) );
    } else if (archmages_greater_incandescence) ui.comboIncandescence->setCurrentIndex( 2 );
    else if (archmages_incandescence) ui.comboIncandescence->setCurrentIndex( 1 );
    else ui.comboIncandescence->setCurrentIndex( 0 );
    ui.checkT172P->setChecked( t17_count >= 2 );
    ui.checkT174P->setChecked( t17_count >= 4 );
    ui.checkT182P->setChecked( t18_count >= 2 );
    ui.checkT184P->setChecked( t18_count >= 4 );
    ui.txtMHHigh->setText( qsprint( mh_high ) );
    ui.txtMHLow->setText( qsprint( mh_low ) );
    char buf[32];
    sprintf( buf, "%.2f", mh_speed );
    ui.txtMHSpeed->setText( buf );
    ui.txtOHHigh->setText( qsprint( oh_high ) );
    ui.txtOHLow->setText( qsprint( oh_low ) );
    sprintf( buf, "%.2f", oh_speed );
    ui.txtOHSpeed->setText( buf );

    ui.comboSpec->setCurrentIndex( spec );

    ui.comboTalent7->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent6->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent5->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent4->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent3->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent2->setCurrentIndex( talent % 10 );
    talent /= 10;
    ui.comboTalent1->setCurrentIndex( talent % 10 );
    talent /= 10;
    return 0;
}
