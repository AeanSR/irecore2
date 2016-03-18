/**
    IreCore kernel - Warrior Class Abstraction

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* class-spec state infos. */
struct class_state_t{
    struct spec_state_t* spec;
#if (BUFF_POTION == 1)
    struct {
        time_t expire;
        time_t cd;
    } potion;
    #define potion_expire (rti->player.class->potion.expire)
    #define potion_cd     (rti->player.class->potion.cd)
#else
    #define potion_expire (0)
    #define potion_cd     (0)
#endif
#if (TALENT_TIER6 == 3) // TODO: where is bladestrom?
    struct{
        time_t cd;
        time_t expire;
    } bladestorm;
    #define bladestorm_expire (rti->player.class->bladestorm.expire)
    #define bladestorm_cd     (rti->player.class->bladestorm.cd)
#else
    #define bladestorm_expire (0)
    #define bladestorm_cd     (0)
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    struct {
        time_t expire;
        RPPM_t proc;
    } incandescence;
    #define incandescence_expire (rti->player.class->expire)
#else
    #define incandescence_expire (0)
#endif
#if defined(legendary_ring)
    struct {
        time_t expire;
        time_t cd;
        float dmg_snapshot;
    } thorasus_the_stone_heart_of_draenor;
    #define thorasus_the_stone_heart_of_draenor_cd     (rti->player.class->thorasus_the_stone_heart_of_draenor.cd)
    #define thorasus_the_stone_heart_of_draenor_expire (rti->player.class->thorasus_the_stone_heart_of_draenor.expire)
#else
    #define thorasus_the_stone_heart_of_draenor_cd     (0)
    #define thorasus_the_stone_heart_of_draenor_expire (0)
#endif
#if (thunderlord_mh)
    struct {
        time_t expire;
        k32u extend;
        RPPM_t proc;
    } enchant_mh;
#endif
#if (thunderlord_oh)
    struct {
        time_t expire;
        k32u extend;
        RPPM_t proc;
    } enchant_oh;
#endif
#if (bleedinghollow_mh)
    struct {
        time_t expire;
        RPPM_t proc;
    } enchant_mh;
#endif
#if (bleedinghollow_oh)
    struct {
        time_t expire;
        RPPM_t proc;
    } enchant_oh;
#endif
#if (shatteredhand_mh)
    RPPM_t enchant_mh;
#endif
#if (shatteredhand_oh)
    RPPM_t enchant_oh;
#endif
#if (RACE == RACE_BLOODELF)
    time_t arcanetorrent;
    #define arcanetorrent_cd (rti->player.class->arcanetorrent)
#else
    #define arcanetorrent_cd (0)
#endif
#if (RACE == RACE_TROLL)
    struct{
        time_t cd;
        time_t expire;
    } berserking;
    #define berserking_cd     (rti->player.class->berserking.cd)
    #define berserking_expire (rti->player.class->berserking.expire)
#else
    #define berserking_cd     (0)
    #define berserking_expire (0)
#endif
#if (RACE == RACE_ORC)
    struct{
        time_t cd;
        time_t expire;
    } bloodfury;
    #define bloodfury_cd     (rti->player.class->bloodfury.cd)
    #define bloodfury_expire (rti->player.class->bloodfury.expire)
#else
    #define bloodfury_cd     (0)
    #define bloodfury_expire (0)
#endif
#if (RACE == RACE_UNDEAD)
    ICD_t           touch_of_the_grave;
#endif
#if defined(trinket_vial_of_convulsive_shadows)
    struct {
        time_t cd;
        time_t expire;
    } vial_of_convulsive_shadows;
    #define vial_of_convulsive_shadows_cd     (rti->player.class->vial_of_convulsive_shadows.cd)
    #define vial_of_convulsive_shadows_expire (rti->player.class->vial_of_convulsive_shadows.expire)
#else
    #define vial_of_convulsive_shadows_cd     (0)
    #define vial_of_convulsive_shadows_expire (0)
#endif
#if defined(trinket_forgemasters_insignia)
    struct {
        time_t expire;
        k32u stack;
        RPPM_t proc;
    } forgemasters_insignia;
    #define forgemasters_insignia_expire (rti->player.class->forgemasters_insignia.expire)
    #define forgemasters_insignia_stack  (rti->player.class->forgemasters_insignia.stack)
#else
    #define forgemasters_insignia_expire (0)
    #define forgemasters_insignia_stack  (0)
#endif
#if defined(trinket_horn_of_screaming_spirits)
    struct {
        time_t expire;
        RPPM_t proc;
    } horn_of_screaming_spirits;
    #define horn_of_screaming_spirits_expire (rti->player.class->horn_of_screaming_spirits.expire)
#else
    #define horn_of_screaming_spirits_expire (0)
#endif
#if defined(trinket_scabbard_of_kyanos)
    struct {
        time_t cd;
        time_t expire;
    } scabbard_of_kyanos;
    #define scabbard_of_kyanos_cd     (rti->player.class->scabbard_of_kyanos.cd)
    #define scabbard_of_kyanos_expire (rti->player.class->scabbard_of_kyanos.expire)
#else
    #define scabbard_of_kyanos_cd     (0)
    #define scabbard_of_kyanos_expire (0)
#endif
#if defined(trinket_badge_of_victory)
    struct {
        time_t cd;
        time_t expire;
    } badge_of_victory;
    #define badge_of_victory_cd     (rti->player.class->badge_of_victory.cd)
    #define badge_of_victory_expire (rti->player.class->badge_of_victory.expire)
#else
    #define badge_of_victory_cd     (0)
    #define badge_of_victory_expire (0)
#endif
#if defined(trinket_insignia_of_victory)
    struct {
        time_t expire;
        ICD_t proc;
    } insignia_of_victory;
    #define insignia_of_victory_expire (rti->player.class->insignia_of_victory.expire)
#else
    #define insignia_of_victory_expire (0)
#endif
#if defined(trinket_tectus_beating_heart)
    struct {
        time_t expire;
        RPPM_t proc;
    } tectus_beating_heart;
    #define tectus_beating_heart_expire (rti->player.class->tectus_beating_heart.expire)
#else
    #define tectus_beating_heart_expire (0)
#endif
#if defined(trinket_formidable_fang)
    struct {
        time_t expire;
        RPPM_t proc;
    } formidable_fang;
    #define formidable_fang_expire (rti->player.class->formidable_fang.expire)
#else
    #define formidable_fang_expire (0)
#endif
#if defined(trinket_draenic_stone)
    struct {
        time_t expire;
        ICD_t proc;
    } draenic_stone;
    #define draenic_stone_expire (rti->player.class->draenic_stone.expire)
#else
    #define draenic_stone_expire (0)
#endif
#if defined(trinket_skull_of_war)
    struct {
        time_t expire;
        ICD_t proc;
    } skull_of_war;
    #define skull_of_war_expire (rti->player.class->skull_of_war.expire)
#else
    #define skull_of_war_expire (0)
#endif
#if defined(trinket_mote_of_the_mountain)
    struct {
        time_t expire;
        RPPM_t proc;
    } mote_of_the_mountain;
    #define mote_of_the_mountain_expire (rti->player.class->mote_of_the_mountain.expire)
#else
    #define mote_of_the_mountain_expire (0)
#endif
#if defined(trinket_discordant_chorus)
    RPPM_t discordant_chorus;
#endif
#if defined(trinket_unending_hunger)
    struct {
        time_t expire;
        k32u stack;
        RPPM_t proc;
    } unending_hunger;
    #define unending_hunger_expire (rti->player.class->unending_hunger.expire)
    #define unending_hunger_stack  (rti->player.class->unending_hunger.stack)
#else
    #define unending_hunger_expire (0)
    #define unending_hunger_stack  (0)
#endif
#if defined(trinket_spores_of_alacrity)
    struct {
        time_t expire;
        RPPM_t proc;
    } spores_of_alacrity;
    #define spores_of_alacrity_expire (rti->player.class->spores_of_alacrity.expire)
#else
    #define spores_of_alacrity_expire (0)
#endif
#if defined(trinket_bonemaws_big_toe)
    struct {
        time_t cd;
        time_t expire;
    } bonemaws_big_toe;
    #define bonemaws_big_toe_cd     (rti->player.class->bonemaws_big_toe.cd)
    #define bonemaws_big_toe_expire (rti->player.class->bonemaws_big_toe.expire)
#else
    #define bonemaws_big_toe_cd     (0)
    #define bonemaws_big_toe_expire (0)
#endif
#if defined(trinket_emberscale_talisman)
    struct {
        time_t cd;
        time_t expire;
    } emberscale_talisman;
    #define emberscale_talisman_cd     (rti->player.class->emberscale_talisman.cd)
    #define emberscale_talisman_expire (rti->player.class->emberscale_talisman.expire)
#else
    #define emberscale_talisman_cd     (0)
    #define emberscale_talisman_expire (0)
#endif
#if defined(trinket_gronntooth_war_horn)
    struct {
        time_t expire;
        RPPM_t proc;
    } gronntooth_war_horn;
    #define gronntooth_war_horn_expire (rti->player.class->gronntooth_war_horn.expire)
#else
    #define gronntooth_war_horn_expire (0)
#endif
};
struct class_debuff_t{
    struct spec_debuff_t* spec;
#if (shatteredhand_mh)
    struct {
        time_t expire;
        float ticks;
    } enchant_mh;
#endif
#if (shatteredhand_oh)
    struct {
        time_t expire;
        float ticks;
    } enchant_oh;
#endif
#if defined(trinket_empty_drinking_horn)
    struct {
        time_t expire;
        k32u stack;
    } empty_drinking_horn;
#endif
};

/* stat processor */
void refresh_str( rtinfo_t* rti ) {
    float fstr = ( float )rti->player.stat.gear_str;
    k32u str;
    float coeff = 1.0f;
    if ( PLATE_SPECIALIZATION ) coeff *= 1.05f;
#if (archmages_incandescence || archmages_greater_incandescence)
    if ( UP( incandescence_expire ) ) coeff *= archmages_greater_incandescence ? 1.15f : 1.1f;
#endif
    str = convert_uint_rtz( fstr * coeff );
    fstr = 1455; /* Base str @lvl 100. */
    fstr += racial_base_str[RACE]; /* Racial str. */
    str += convert_uint_rtz( fstr * coeff );
    rti->player.stat.str = str;
}

void refresh_ap( rtinfo_t* rti ) {
    k32u ap = rti->player.stat.str;
#if (RACE == RACE_ORC)
    if ( UP( bloodfury.expire ) ) ap += 345;
#endif
    rti->player.stat.ap = ap;
}

float spec_mastery_coefficient( rtinfo_t* rti );
float spec_mastery_increament( rtinfo_t* rti );

void refresh_mastery( rtinfo_t* rti ) {
    float mastery = ( float )rti->player.stat.gear_mastery;
#if (bleedinghollow_mh)
    if ( UP( rti->player.class->enchant_mh.expire ) ) mastery += 500.0f;
#endif
#if (bleedinghollow_oh)
    if ( UP( rti->player.class->enchant_oh.expire ) ) mastery += 500.0f;
#endif
    mastery = spec_mastery_coefficient( rti ) * ( 0.08f + mastery / 11000 ) + spec_mastery_increament( rti );
    rti->player.stat.mastery = mastery;
}

void refresh_crit( rtinfo_t* rti ) {
    float crit = ( float )rti->player.stat.gear_crit;
#if (thunderlord_mh)
    if ( UP( rti->player.class->enchant_mh.expire ) ) crit += 500.0f;
#endif
#if (thunderlord_oh)
    if ( UP( rti->player.class->enchant_oh.expire ) ) crit += 500.0f;
#endif
    crit *= 1.05f;
    crit = 0.05f + crit / 11000;
    if ( ( RACE == RACE_NIGHTELF_DAY ) || ( RACE == RACE_BLOODELF ) || ( RACE == RACE_WORGEN ) )
        crit += 0.01f;
/*#if (t17_4pc)
    if ( UP( rampage.expire ) ) {
        crit += 0.06f * rti->player.rampage.stack;
    }
#endif*/
    rti->player.stat.crit = crit;
}

float spec_haste_coefficient( rtinfo_t* rti );

void refresh_haste( rtinfo_t* rti ) {
    float haste = ( float )rti->player.stat.gear_haste;
    haste = 1.0f + haste / 10000;
    if ( ( RACE == RACE_NIGHTELF_NIGHT ) || ( RACE == RACE_GOBLIN ) || ( RACE == RACE_GNOME ) )
        haste *= 1.01f;
#if (RACE == RACE_TROLL)
    if ( UP( berserking_expire ) ) haste *= 1.15f;
#endif
    if ( BUFF_BLOODLUST hostonly( && rti->timestamp ) ) if ( ( rti->timestamp % FROM_SECONDS( 600 ) ) < FROM_SECONDS( 30 ) ) haste *= 1.3f;
    haste *= spec_haste_coefficient( rti );
    rti->player.stat.haste = haste - 1.0f;
}

void refresh_vers( rtinfo_t* rti ) {
    float vers = ( float )rti->player.stat.gear_vers;
    if ( RACE == RACE_HUMAN ) vers += 100;
    vers = vers / 13000;
    rti->player.stat.vers = vers;
}

float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )weapon[offhand].low;
    dmg += uni_rng( rti ) * ( weapon[offhand].high - weapon[offhand].low );
    dmg += ( normalized ? normalized_weapon_speed[weapon[offhand].type] : weapon[offhand].speed ) * rti->player.stat.ap / 3.5f;
    dmg *= weapon_multiplier;
    if ( offhand ) dmg *= 0.5f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    return dmg;
}

enum {
    ATYPE_WHITE_MELEE,
    ATYPE_YELLOW_MELEE,
    ATYPE_SPELL,
    DTYPE_DIRECT,
    DTYPE_PHYSICAL,
    DTYPE_SHADOW,
    DTYPE_FIRE,
};
enum {
    DICE_MISS,
    DICE_GLANCE,
    DICE_CRIT,
    DICE_HIT,
};
void special_procs( rtinfo_t* rti, k32u attacktype, k32u target_id );

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate );

//k32s deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, float extra_crit_rate, float extra_crit_bonus, kbool ignore_armor ) {
float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor );

/* Event list. */
#define DECL_EVENT( name ) void event_##name ( rtinfo_t* rti, k32u target_id )
#define HOOK_EVENT( name ) case routnum_##name: event_##name( rti, e.target_id ); break;
#define DECL_SPELL( name ) int spell_##name ( rtinfo_t* rti )
#define SPELL( name ) safemacro(if(spell_##name ( rti )) return;)
enum {
    routnum_gcd_expire,
#if (BUFF_BLOODLUST == 1)
    routnum_bloodlust_start,
    routnum_bloodlust_end,
#endif
#if (BUFF_POTION == 1)
    routnum_potion_start,
    routnum_potion_cd,
    routnum_potion_expire,
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    routnum_incandescence_trigger,
    routnum_incandescence_expire,
#endif
#if defined(legendary_ring)
    routnum_thorasus_the_stone_heart_of_draenor_start,
    routnum_thorasus_the_stone_heart_of_draenor_expire,
    routnum_thorasus_the_stone_heart_of_draenor_cd,
#endif
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
    routnum_enchant_mh_trigger,
    routnum_enchant_mh_expire,
#endif
#if (shatteredhand_mh)
    routnum_enchant_mh_tick,
#endif
#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
    routnum_enchant_oh_trigger,
    routnum_enchant_oh_expire,
#endif
#if (shatteredhand_oh)
    routnum_enchant_oh_tick,
#endif
#if (RACE == RACE_BLOODELF)
    routnum_arcanetorrent_cd,
    routnum_arcanetorrent_execute,
#endif
#if (RACE == RACE_TROLL)
    routnum_berserking_start,
    routnum_berserking_expire,
    routnum_berserking_cd,
#endif
#if (RACE == RACE_ORC)
    routnum_bloodfury_start,
    routnum_bloodfury_expire,
    routnum_bloodfury_cd,
#endif
#if (RACE == RACE_UNDEAD)
    routnum_touch_of_the_grave_trigger,
#endif
#if defined(trinket_vial_of_convulsive_shadows)
    routnum_vial_of_convulsive_shadows_expire,
    routnum_vial_of_convulsive_shadows_start,
    routnum_vial_of_convulsive_shadows_cd,
#endif
#if defined(trinket_forgemasters_insignia)
    routnum_forgemasters_insignia_tick,
#endif
#if defined(trinket_horn_of_screaming_spirits)
    routnum_horn_of_screaming_spirits_trigger,
    routnum_horn_of_screaming_spirits_expire,
#endif
#if defined(trinket_scabbard_of_kyanos)
    routnum_scabbard_of_kyanos_expire,
    routnum_scabbard_of_kyanos_start,
    routnum_scabbard_of_kyanos_cd,
#endif
#if defined(trinket_badge_of_victory)
    routnum_badge_of_victory_expire,
    routnum_badge_of_victory_start,
    routnum_badge_of_victory_cd,
#endif
#if defined(trinket_insignia_of_victory)
    routnum_insignia_of_victory_expire,
    routnum_insignia_of_victory_trigger,
#endif
#if defined(trinket_tectus_beating_heart)
    routnum_tectus_beating_heart_trigger,
    routnum_tectus_beating_heart_expire,
#endif
#if defined(trinket_formidable_fang)
    routnum_formidable_fang_trigger,
    routnum_formidable_fang_expire,
#endif
#if defined(trinket_draenic_stone)
    routnum_draenic_stone_expire,
    routnum_draenic_stone_trigger,
#endif
#if defined(trinket_skull_of_war)
    routnum_skull_of_war_expire,
    routnum_skull_of_war_trigger,
#endif
#if defined(trinket_mote_of_the_mountain)
    routnum_mote_of_the_mountain_trigger,
    routnum_mote_of_the_mountain_expire,
#endif
#if defined(trinket_discordant_chorus)
    routnum_discordant_chorus_trigger,
#endif
#if defined(trinket_empty_drinking_horn)
    routnum_empty_drinking_horn_trigger,
    routnum_empty_drinking_horn_expire,
    routnum_empty_drinking_horn_tick,
#endif
#if defined(trinket_unending_hunger)
    routnum_unending_hunger_trigger,
    routnum_unending_hunger_expire,
#endif
#if defined(trinket_spores_of_alacrity)
    routnum_spores_of_alacrity_trigger,
    routnum_spores_of_alacrity_expire,
#endif
#if defined(trinket_bonemaws_big_toe)
    routnum_bonemaws_big_toe_expire,
    routnum_bonemaws_big_toe_start,
    routnum_bonemaws_big_toe_cd,
#endif
#if defined(trinket_emberscale_talisman)
    routnum_emberscale_talisman_expire,
    routnum_emberscale_talisman_start,
    routnum_emberscale_talisman_cd,
#endif
#if defined(trinket_gronntooth_war_horn)
    routnum_gronntooth_war_horn_trigger,
    routnum_gronntooth_war_horn_expire,
#endif
    START_OF_SPEC_ROUTNUM,
};

// === General Cooldown =======================================================
void gcd_start ( rtinfo_t* rti, time_t length ) {
    rti->player.gcd = TIME_OFFSET( max( length, FROM_SECONDS( 1 ) ) );
    eq_enqueue( rti, rti->player.gcd, routnum_gcd_expire, 0 );
}

DECL_EVENT( gcd_expire ) {
    /* Do nothing. */
}

// === bloodlust ==============================================================
#if (BUFF_BLOODLUST == 1)
DECL_EVENT( bloodlust_start ) {
    lprintf( ( "bloodlust start" ) );
    refresh_haste( rti );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 30 ) ), routnum_bloodlust_end, target_id );
}

DECL_EVENT( bloodlust_end ) {
    lprintf( ( "bloodlust end" ) );
    refresh_haste( rti );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 570 ) ), routnum_bloodlust_start, target_id );
}
#endif

// === potion =================================================================
#if (BUFF_POTION == 1)
DECL_EVENT( potion_expire ) {
    lprintf( ( "potion end" ) );
    rti->player.stat.gear_str -= 1000;
    refresh_str( rti );
    refresh_ap( rti );
}

DECL_EVENT( potion_cd ) {
    lprintf( ( "potion cd" ) );
}

DECL_EVENT( potion_start ) {
    lprintf( ( "potion start" ) );
    rti->player.stat.gear_str += 1000;
    refresh_str( rti );
    refresh_ap( rti );
    potion_expire = TIME_OFFSET( FROM_SECONDS( 25 ) );
    eq_enqueue( rti, potion_expire, routnum_potion_expire, target_id );
}

DECL_SPELL( potion ) {
    if ( potion_cd > rti->timestamp ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_potion_start, 0 );
    if ( rti->timestamp == FROM_SECONDS( 0 ) ) {
        potion_cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
        eq_enqueue( rti, potion_cd, routnum_potion_cd, 0 );
    } else {
        potion_cd = rti->expected_combat_length + 1;
    }
    return 1;
}
#endif

// === legendary ring =========================================================
#if (archmages_incandescence || archmages_greater_incandescence)
DECL_EVENT( incandescence_trigger ) {
    incandescence_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, incandescence_expire, routnum_incandescence_expire, target_id );
    refresh_str( rti );
    refresh_ap( rti );
    lprintf( ( "incandescence trigger" ) );
}
DECL_EVENT( incandescence_expire ) {
    if ( incandescence_expire == rti->timestamp ) {
        lprintf( ( "incandescence expire" ) );
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif
#if defined(legendary_ring)
DECL_EVENT( thorasus_the_stone_heart_of_draenor_start ) {
    thorasus_the_stone_heart_of_draenor_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, thorasus_the_stone_heart_of_draenor_expire, routnum_thorasus_the_stone_heart_of_draenor_expire, target_id );
    rti->player.class->thorasus_the_stone_heart_of_draenor.dmg_snapshot = rti->damage_collected;
    lprintf( ( "thorasus the stone heart of draenor start" ) );
}
DECL_EVENT( thorasus_the_stone_heart_of_draenor_expire ) {
    float dmg = rti->damage_collected - rti->player.class->thorasus_the_stone_heart_of_draenor.dmg_snapshot;
    dmg *= legendary_ring * 0.0001;
    for ( int i = 0; i != num_enemies; i++ ) {
        deal_damage( rti, i, dmg, DTYPE_DIRECT, DICE_HIT, 0, 0 );
    }
    lprintf( ( "thorasus the stone heart of draenor expire" ) );
}
DECL_EVENT( thorasus_the_stone_heart_of_draenor_cd ) {
    lprintf( ( "thorasus the stone heart of draenor cd" ) );
}
DECL_SPELL( thorasus_the_stone_heart_of_draenor ) {
    if ( thorasus_the_stone_heart_of_draenor_cd > rti->timestamp ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    thorasus_the_stone_heart_of_draenor_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, thorasus_the_stone_heart_of_draenor_cd, routnum_thorasus_the_stone_heart_of_draenor_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_thorasus_the_stone_heart_of_draenor_start, 0 );
    lprintf( ( "cast thorasus the stone heart of draenor" ) );
    return 1;
}
#endif

// === enchants ===============================================================
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
DECL_EVENT( enchant_mh_expire ) {
#if (shatteredhand_mh)
	if ( rti->enemy[target_id].class->enchant_mh.expire == rti->timestamp ) {
#else
	if ( rti->player.class->enchant_mh.expire == rti->timestamp ) {
#endif
		lprintf( ( "mh enchant expire" ) );
        if ( thunderlord_mh ) refresh_crit( rti );
        if ( bleedinghollow_mh ) refresh_mastery( rti );
    }
}

DECL_EVENT( enchant_mh_trigger ) {
#if (thunderlord_mh)
    rti->player.class->enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->player.class->enchant_mh.extend = 3;
    refresh_crit( rti );
#endif
#if (bleedinghollow_mh)
    rti->player.class->enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    refresh_mastery( rti );
#endif
#if (shatteredhand_mh)
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0 );
    deal_damage( rti, target_id, 1500.0f, DTYPE_PHYSICAL, dice, 0, 0 );
    rti->enemy[target_id].class->enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->enemy[target_id].class->enchant_mh.ticks = 6.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_mh_tick, target_id );
	eq_enqueue( rti, rti->enemy[target_id].class->enchant_mh.expire, routnum_enchant_mh_expire, target_id );
#else
	eq_enqueue( rti, rti->player.class->enchant_mh.expire, routnum_enchant_mh_expire, target_id );
#endif
}
#endif

#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
DECL_EVENT( enchant_oh_expire ) {
#if (shatteredhand_oh)
	if ( rti->enemy[target_id].class->enchant_oh.expire == rti->timestamp ) {
#else
	if ( rti->player.class->enchant_oh.expire == rti->timestamp ) {
#endif
        lprintf( ( "oh enchant expire" ) );
        if ( thunderlord_oh ) refresh_crit( rti );
        if ( bleedinghollow_oh ) refresh_mastery( rti );
    }
}

DECL_EVENT( enchant_oh_trigger ) {
#if (thunderlord_oh)
    rti->player.class->enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->player.class->enchant_oh.extend = 3;
    refresh_crit( rti );
#endif
#if (bleedinghollow_oh)
    rti->player.class->enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    refresh_mastery( rti );
#endif
#if (shatteredhand_oh)
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0 );
    deal_damage( rti, target_id, 1500.0f, DTYPE_PHYSICAL, dice, 0, 0 );
    rti->enemy[target_id].class->enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->enemy[target_id].class->enchant_oh.ticks = 6.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_oh_tick, target_id );
	eq_enqueue( rti, rti->enemy[target_id].class->enchant_oh.expire, routnum_enchant_oh_expire, target_id );
#else
	eq_enqueue( rti, rti->player.class->enchant_oh.expire, routnum_enchant_oh_expire, target_id );
#endif
}
#endif

#if (shatteredhand_mh)
DECL_EVENT( enchant_mh_tick ) {
    if ( TIME_OFFSET( FROM_SECONDS( rti->enemy[target_id].class->enchant_mh.ticks - 1.0f ) ) == rti->enemy[target_id].class->enchant_mh.expire ) {
        rti->enemy[target_id].class->enchant_mh.ticks -= 1.0f;
        deal_damage( rti, target_id, 750.0f, DTYPE_PHYSICAL, DICE_HIT, 0, 0 );
        if ( rti->enemy[target_id].class->enchant_mh.ticks >= 1.0f )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_mh_tick, target_id );
    }
}
#endif
#if (shatteredhand_oh)
DECL_EVENT( enchant_oh_tick ) {
    if ( TIME_OFFSET( FROM_SECONDS( rti->enemy[target_id].class->enchant_oh.ticks - 1.0f ) ) == rti->enemy[target_id].class->enchant_oh.expire ) {
        rti->enemy[target_id].class->enchant_oh.ticks -= 1.0f;
        deal_damage( rti, target_id, 750.0f, DTYPE_PHYSICAL, DICE_HIT, 0, 0 );
        if ( rti->enemy[target_id].class->enchant_oh.ticks >= 1.0f )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_oh_tick, target_id );
    }
}
#endif

// === racial traits ==========================================================
#if (RACE == RACE_BLOODELF)
DECL_EVENT( arcanetorrent_cd ) {
    lprintf( ( "arcanetorrent ready" ) );
}
DECL_EVENT( arcanetorrent_execute ) {
    lprintf( ( "cast arcanetorrent" ) );
}

DECL_SPELL( arcanetorrent ) {
    if ( arcanetorrent_cd > rti->timestamp ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    arcanetorrent_cd = TIME_OFFSET( FROM_SECONDS( 90 ) ); // 120->90 patch 6.2.2
    eq_enqueue( rti, arcanetorrent_cd, routnum_arcanetorrent_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_arcanetorrent_execute, 0 );
    power_gain( rti, 15.0f );
    lprintf( ( "cast arcanetorrent" ) );
    return 1;
}
#endif

#if (RACE == RACE_TROLL)
DECL_EVENT( berserking_cd ) {
    lprintf( ( "berserking ready" ) );
}
DECL_EVENT( berserking_start ) {
    lprintf( ( "berserking start" ) );
    refresh_haste( rti );
}
DECL_EVENT( berserking_expire ) {
    lprintf( ( "berserking expire" ) );
    refresh_haste( rti );
}

DECL_SPELL( berserking ) {
    if ( berserking_cd > rti->timestamp ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_berserking_start, 0 );
    berserking_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, berserking_expire, routnum_berserking_expire, 0 );
    berserking_cd = TIME_OFFSET( FROM_SECONDS( 180 ) );
    eq_enqueue( rti, berserking_cd, routnum_berserking_cd, 0 );
    lprintf( ( "cast berserking" ) );
    return 1;
}
#endif

#if (RACE == RACE_ORC)
DECL_EVENT( bloodfury_cd ) {
    lprintf( ( "bloodfury ready" ) );
}
DECL_EVENT( bloodfury_start ) {
    lprintf( ( "bloodfury start" ) );
    refresh_ap( rti );
}
DECL_EVENT( bloodfury_expire ) {
    lprintf( ( "bloodfury expire" ) );
    refresh_ap( rti );
}

DECL_SPELL( bloodfury ) {
    if ( bloodfury_cd > rti->timestamp ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_bloodfury_start, 0 );
    bloodfury_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, bloodfury_expire, routnum_bloodfury_expire, 0 );
    bloodfury_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, bloodfury_cd, routnum_bloodfury_cd, 0 );
    lprintf( ( "cast bloodfury" ) );
    return 1;
}
#endif
#if (RACE == RACE_UNDEAD)
DECL_EVENT( touch_of_the_grave_trigger ) {
    // old data for 6.2.0
	//float d = 1932.0f;
    //d += uni_rng( rti ) * ( 2244.0f - 1932.0f );
    float d = 0.5f * rti->player.stat.ap; // To avoid SMF bonus.
    d *= 2.0f; // 2015.11.19 hotfix
	deal_damage( rti, target_id, d, DTYPE_SHADOW, DICE_HIT, 0, 0 );
}
#endif

// === trinkets ===============================================================
#if defined(trinket_vial_of_convulsive_shadows)
DECL_EVENT( vial_of_convulsive_shadows_cd ) {
    lprintf( ( "convulsiveshadows ready" ) );
}
DECL_EVENT( vial_of_convulsive_shadows_start ) {
    lprintf( ( "convulsiveshadows start" ) );
    rti->player.stat.gear_haste += trinket_vial_of_convulsive_shadows;
    refresh_haste( rti );
}
DECL_EVENT( vial_of_convulsive_shadows_expire ) {
    lprintf( ( "convulsiveshadows expire" ) );
    rti->player.stat.gear_haste -= trinket_vial_of_convulsive_shadows;
    refresh_haste( rti );
}

DECL_SPELL( vial_of_convulsive_shadows ) {
    if ( vial_of_convulsive_shadows_cd > rti->timestamp ) return 0;
    if ( UP( scabbard_of_kyanos_expire ) ) return 0;
    if ( UP( emberscale_talisman_expire ) ) return 0;
    if ( UP( bonemaws_big_toe_expire ) ) return 0;
    if ( UP( badge_of_victory_expire ) ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_vial_of_convulsive_shadows_start, 0 );
    vial_of_convulsive_shadows_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, vial_of_convulsive_shadows_expire, routnum_vial_of_convulsive_shadows_expire, 0 );
    vial_of_convulsive_shadows_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, vial_of_convulsive_shadows_cd, routnum_vial_of_convulsive_shadows_cd, 0 );
    lprintf( ( "cast vial_of_convulsive_shadows" ) );
    return 1;
}
#endif

#if defined(trinket_forgemasters_insignia)
DECL_EVENT( forgemasters_insignia_tick ) {
    if ( forgemasters_insignia_stack < 20 ) {
        if ( forgemasters_insignia_stack == 0 ) {
            forgemasters_insignia_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
            lprintf( ( "forgemasters_insignia start" ) );
        }
        forgemasters_insignia_stack++;
        rti->player.stat.gear_mastery += trinket_forgemasters_insignia;
        refresh_mastery( rti );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 0.5 ) ), routnum_forgemasters_insignia_tick, target_id );
    } else {
        forgemasters_insignia_stack = 0;
        rti->player.stat.gear_mastery -= 20 * trinket_forgemasters_insignia;
        refresh_mastery( rti );
        lprintf( ( "forgemasters_insignia expire" ) );
    }
}

#endif

#if defined(trinket_horn_of_screaming_spirits)
DECL_EVENT( horn_of_screaming_spirits_trigger ) {
    lprintf( ( "horn_of_screaming_spirits start" ) );
    rti->player.stat.gear_mastery += trinket_horn_of_screaming_spirits;
    refresh_mastery( rti );
    horn_of_screaming_spirits_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, horn_of_screaming_spirits_expire, routnum_horn_of_screaming_spirits_expire, target_id );
}
DECL_EVENT( horn_of_screaming_spirits_expire ) {
    lprintf( ( "horn_of_screaming_spirits expire" ) );
    rti->player.stat.gear_mastery -= trinket_horn_of_screaming_spirits;
    refresh_mastery( rti );
}
#endif

#if defined(trinket_scabbard_of_kyanos)
DECL_EVENT( scabbard_of_kyanos_cd ) {
    lprintf( ( "scabbard_of_kyanos ready" ) );
}
DECL_EVENT( scabbard_of_kyanos_start ) {
    lprintf( ( "scabbard_of_kyanos start" ) );
    rti->player.stat.gear_str += trinket_scabbard_of_kyanos;
    refresh_str( rti );
    refresh_ap( rti );
}
DECL_EVENT( scabbard_of_kyanos_expire ) {
    lprintf( ( "scabbard_of_kyanos expire" ) );
    rti->player.stat.gear_str -= trinket_scabbard_of_kyanos;
    refresh_str( rti );
    refresh_ap( rti );
}

DECL_SPELL( scabbard_of_kyanos ) {
    if ( scabbard_of_kyanos_cd > rti->timestamp ) return 0;
    if ( UP( vial_of_convulsive_shadows_expire ) ) return 0;
    if ( UP( emberscale_talisman_expire ) ) return 0;
    if ( UP( bonemaws_big_toe_expire ) ) return 0;
    if ( UP( badge_of_victory_expire ) ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_scabbard_of_kyanos_start, 0 );
    scabbard_of_kyanos_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, scabbard_of_kyanos_expire, routnum_scabbard_of_kyanos_expire, 0 );
    scabbard_of_kyanos_cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
    eq_enqueue( rti, scabbard_of_kyanos_cd, routnum_scabbard_of_kyanos_cd, 0 );
    lprintf( ( "cast scabbard_of_kyanos" ) );
    return 1;
}
#endif

#if defined(trinket_emberscale_talisman)
DECL_EVENT( emberscale_talisman_cd ) {
    lprintf( ( "emberscale_talisman ready" ) );
}
DECL_EVENT( emberscale_talisman_start ) {
    lprintf( ( "emberscale_talisman start" ) );
    rti->player.stat.gear_vers += trinket_emberscale_talisman;
    refresh_vers( rti );
}
DECL_EVENT( emberscale_talisman_expire ) {
    lprintf( ( "emberscale_talisman expire" ) );
    rti->player.stat.gear_vers -= trinket_emberscale_talisman;
    refresh_vers( rti );
}

DECL_SPELL( emberscale_talisman ) {
    if ( emberscale_talisman_cd > rti->timestamp ) return 0;
    if ( UP( vial_of_convulsive_shadows_expire ) ) return 0;
    if ( UP( scabbard_of_kyanos_expire ) ) return 0;
    if ( UP( bonemaws_big_toe_expire ) ) return 0;
    if ( UP( badge_of_victory_expire ) ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_emberscale_talisman_start, 0 );
    emberscale_talisman_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, emberscale_talisman_expire, routnum_emberscale_talisman_expire, 0 );
    emberscale_talisman_cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
    eq_enqueue( rti, emberscale_talisman_cd, routnum_emberscale_talisman_cd, 0 );
    lprintf( ( "cast emberscale_talisman" ) );
    return 1;
}
#endif

#if defined(trinket_bonemaws_big_toe)
DECL_EVENT( bonemaws_big_toe_cd ) {
    lprintf( ( "bonemaws_big_toe ready" ) );
}
DECL_EVENT( bonemaws_big_toe_start ) {
    lprintf( ( "bonemaws_big_toe start" ) );
    rti->player.stat.gear_crit += trinket_bonemaws_big_toe;
    refresh_crit( rti );
}
DECL_EVENT( bonemaws_big_toe_expire ) {
    lprintf( ( "bonemaws_big_toe expire" ) );
    rti->player.stat.gear_crit -= trinket_bonemaws_big_toe;
    refresh_crit( rti );
}

DECL_SPELL( bonemaws_big_toe ) {
    if ( bonemaws_big_toe_cd > rti->timestamp ) return 0;
    if ( UP( vial_of_convulsive_shadows_expire ) ) return 0;
    if ( UP( scabbard_of_kyanos_expire ) ) return 0;
    if ( UP( emberscale_talisman_expire ) ) return 0;
    if ( UP( badge_of_victory_expire ) ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_bonemaws_big_toe_start, 0 );
    bonemaws_big_toe_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, bonemaws_big_toe_expire, routnum_bonemaws_big_toe_expire, 0 );
    bonemaws_big_toe_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, bonemaws_big_toe_cd, routnum_bonemaws_big_toe_cd, 0 );
    lprintf( ( "cast bonemaws_big_toe" ) );
    return 1;
}
#endif


#if defined(trinket_badge_of_victory)
DECL_EVENT( badge_of_victory_cd ) {
    lprintf( ( "badge_of_victory ready" ) );
}
DECL_EVENT( badge_of_victory_start ) {
    lprintf( ( "badge_of_victory start" ) );
    rti->player.stat.gear_vers += trinket_badge_of_victory;
    refresh_vers( rti );
}
DECL_EVENT( badge_of_victory_expire ) {
    lprintf( ( "badge_of_victory expire" ) );
    rti->player.stat.gear_vers -= trinket_badge_of_victory;
    refresh_vers( rti );
}

DECL_SPELL( badge_of_victory ) {
    if ( badge_of_victory_cd > rti->timestamp ) return 0;
    if ( UP( vial_of_convulsive_shadows_expire ) ) return 0;
    if ( UP( scabbard_of_kyanos_expire ) ) return 0;
    if ( UP( emberscale_talisman_expire ) ) return 0;
    if ( UP( bonemaws_big_toe_expire ) ) return 0;
    if ( UP( bladestorm_expire ) ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_badge_of_victory_start, 0 );
    badge_of_victory_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, badge_of_victory_expire, routnum_badge_of_victory_expire, 0 );
    badge_of_victory_cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    eq_enqueue( rti, badge_of_victory_cd, routnum_badge_of_victory_cd, 0 );
    lprintf( ( "cast badge_of_victory" ) );
    return 1;
}
#endif

#if defined(trinket_insignia_of_victory)
DECL_EVENT( insignia_of_victory_trigger ) {
    lprintf( ( "insignia_of_victory start" ) );
    rti->player.stat.gear_str += trinket_insignia_of_victory;
    refresh_str( rti );
    refresh_ap( rti );
    insignia_of_victory_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, insignia_of_victory_expire, routnum_insignia_of_victory_expire, 0 );
}
DECL_EVENT( insignia_of_victory_expire ) {
    lprintf( ( "insignia_of_victory expire" ) );
    rti->player.stat.gear_str -= trinket_insignia_of_victory;
    refresh_str( rti );
    refresh_ap( rti );
}
#endif

#if defined(trinket_tectus_beating_heart)
DECL_EVENT( tectus_beating_heart_trigger ) {
    lprintf( ( "tectus_beating_heart start" ) );
    rti->player.stat.gear_crit += trinket_tectus_beating_heart;
    refresh_crit( rti );
    tectus_beating_heart_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, tectus_beating_heart_expire, routnum_tectus_beating_heart_expire, 0 );
}
DECL_EVENT( tectus_beating_heart_expire ) {
    lprintf( ( "tectus_beating_heart expire" ) );
    rti->player.stat.gear_crit -= trinket_tectus_beating_heart;
    refresh_crit( rti );
}
#endif

#if defined(trinket_formidable_fang)
DECL_EVENT( formidable_fang_trigger ) {
    lprintf( ( "formidable_fang start" ) );
    rti->player.stat.gear_mastery += trinket_formidable_fang;
    refresh_mastery( rti );
    formidable_fang_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, formidable_fang_expire, routnum_formidable_fang_expire, 0 );
}
DECL_EVENT( formidable_fang_expire ) {
    lprintf( ( "formidable_fang expire" ) );
    rti->player.stat.gear_mastery -= trinket_formidable_fang;
    refresh_mastery( rti );
}
#endif

#if defined(trinket_draenic_stone)
DECL_EVENT( draenic_stone_trigger ) {
    lprintf( ( "draenic_stone start" ) );
    rti->player.stat.gear_str += trinket_draenic_stone;
    refresh_str( rti );
    refresh_ap( rti );
    draenic_stone_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, draenic_stone_expire, routnum_draenic_stone_expire, 0 );
}
DECL_EVENT( draenic_stone_expire ) {
    lprintf( ( "draenic_stone expire" ) );
    rti->player.stat.gear_str -= trinket_draenic_stone;
    refresh_str( rti );
    refresh_ap( rti );
}
#endif

#if defined(trinket_skull_of_war)
DECL_EVENT( skull_of_war_trigger ) {
    lprintf( ( "skull_of_war start" ) );
    rti->player.stat.gear_crit += trinket_skull_of_war;
    refresh_crit( rti );
    skull_of_war_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, skull_of_war_expire, routnum_skull_of_war_expire, 0 );
}
DECL_EVENT( skull_of_war_expire ) {
    lprintf( ( "skull_of_war expire" ) );
    rti->player.stat.gear_crit -= trinket_skull_of_war;
    refresh_crit( rti );
}
#endif

#if defined(trinket_mote_of_the_mountain)
DECL_EVENT( mote_of_the_mountain_trigger ) {
    lprintf( ( "mote_of_the_mountain start" ) );
    rti->player.stat.gear_vers += trinket_mote_of_the_mountain;
    refresh_vers( rti );
    mote_of_the_mountain_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, mote_of_the_mountain_expire, routnum_mote_of_the_mountain_expire, 0 );
}
DECL_EVENT( mote_of_the_mountain_expire ) {
    lprintf( ( "mote_of_the_mountain expire" ) );
    rti->player.stat.gear_vers -= trinket_mote_of_the_mountain;
    refresh_vers( rti );
}
#endif

#if defined(trinket_spores_of_alacrity)
DECL_EVENT( spores_of_alacrity_trigger ) {
    lprintf( ( "spores_of_alacrity start" ) );
    rti->player.stat.gear_haste += trinket_spores_of_alacrity;
    refresh_haste( rti );
    spores_of_alacrity_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, spores_of_alacrity_expire, routnum_spores_of_alacrity_expire, 0 );
}
DECL_EVENT( spores_of_alacrity_expire ) {
    lprintf( ( "spores_of_alacrity expire" ) );
    rti->player.stat.gear_haste -= trinket_spores_of_alacrity;
    refresh_haste( rti );
}
#endif

#if defined(trinket_discordant_chorus)
DECL_EVENT( discordant_chorus_trigger ) {
    lprintf( ( "discordant chorus trigger" ) );
    for ( int i = 0; i != num_enemies; i++ ) {
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );
        deal_damage( rti, i, 0.5 * trinket_discordant_chorus, DTYPE_PHYSICAL, dice, 0, 0 );
    }
}
#endif

#if defined(trinket_empty_drinking_horn)
DECL_EVENT( empty_drinking_horn_trigger ) {
    if ( rti->enemy[target_id].class->empty_drinking_horn.expire >= rti->timestamp ) {
        if ( rti->enemy[target_id].class->empty_drinking_horn.stack < 30 )
            rti->enemy[target_id].class->empty_drinking_horn.stack++;
    }
    else {
        rti->enemy[target_id].class->empty_drinking_horn.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
        rti->enemy[target_id].class->empty_drinking_horn.stack = 1;
        eq_enqueue( rti, rti->enemy[target_id].class->empty_drinking_horn.expire, routnum_empty_drinking_horn_expire, target_id );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_empty_drinking_horn_tick, target_id );
    }
    lprintf( ( "empty_drinking_horn stack %d @tar%d", rti->enemy[target_id].class->empty_drinking_horn.stack, target_id ) );
}
DECL_EVENT( empty_drinking_horn_expire ) {
    rti->enemy[target_id].class->empty_drinking_horn.stack = 0;
    lprintf( ( "empty_drinking_horn stack %d @tar%d", rti->enemy[target_id].class->empty_drinking_horn.stack, target_id ) );
}
DECL_EVENT( empty_drinking_horn_tick ) {
    float dmg = trinket_empty_drinking_horn * 0.5; /* Nerfed to half. */
    dmg *= rti->enemy[target_id].class->empty_drinking_horn.stack;
    deal_damage( rti, target_id, dmg, DTYPE_FIRE, DICE_HIT, 0, 0 );
    time_t next_tick = TIME_OFFSET( FROM_SECONDS( 1 ) );
    if ( next_tick <= rti->enemy[target_id].class->empty_drinking_horn.expire )
        eq_enqueue( rti, next_tick, routnum_empty_drinking_horn_tick, target_id );
}
#endif

#if defined(trinket_unending_hunger)
DECL_EVENT( unending_hunger_trigger ) {
    lprintf( ( "unending_hunger trigger" ) );
    unending_hunger_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, unending_hunger_expire, routnum_unending_hunger_expire, target_id );
    if ( !UP( unending_hunger_expire ) ) {
        unending_hunger_stack = 1;
        rti->player.stat.gear_str += trinket_unending_hunger;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
DECL_EVENT( unending_hunger_expire ) {
    if ( unending_hunger_expire == rti->timestamp ) {
        lprintf( ( "unending_hunger expire" ) );
        rti->player.stat.gear_str -= trinket_unending_hunger * unending_hunger_stack;
        unending_hunger_stack = 0;
        unending_hunger_expire = 0;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif

#if defined(trinket_gronntooth_war_horn)
DECL_EVENT( gronntooth_war_horn_trigger ) {
    if( !UP( gronntooth_war_horn_expire ) ) {
        rti->player.stat.gear_str += trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }
    gronntooth_war_horn_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, gronntooth_war_horn_expire, routnum_gronntooth_war_horn_expire, target_id );
    lprintf( ( "gronntooth_war_horn trigger" ) );
}
DECL_EVENT( gronntooth_war_horn_expire ) {
    if ( gronntooth_war_horn_expire == rti->timestamp ) {
        lprintf( ( "gronntooth_war_horn expire" ) );
        gronntooth_war_horn_expire = 0;
        rti->player.stat.gear_str -= trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif

void spec_routine_entries( rtinfo_t* rti, _event_t e );

void routine_entries( rtinfo_t* rti, _event_t e ) {
    if( e.routine >= START_OF_SPEC_ROUTNUM ){
        spec_routine_entries( rti, e );
    }
    else switch( e.routine ) {
        HOOK_EVENT( gcd_expire );

#if (BUFF_BLOODLUST == 1)
        HOOK_EVENT( bloodlust_start );
        HOOK_EVENT( bloodlust_end );
#endif
#if (BUFF_POTION == 1)
        HOOK_EVENT( potion_start );
        HOOK_EVENT( potion_cd );
        HOOK_EVENT( potion_expire );
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
        HOOK_EVENT( incandescence_trigger );
        HOOK_EVENT( incandescence_expire );
#endif
#if defined(legendary_ring)
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_start );
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_expire );
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_cd );
#endif
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
        HOOK_EVENT( enchant_mh_trigger );
        HOOK_EVENT( enchant_mh_expire );
#endif
#if (shatteredhand_mh)
        HOOK_EVENT( enchant_mh_tick );
#endif
#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
        HOOK_EVENT( enchant_oh_trigger );
        HOOK_EVENT( enchant_oh_expire );
#endif
#if (shatteredhand_oh)
        HOOK_EVENT( enchant_oh_tick );
#endif
#if (RACE == RACE_BLOODELF)
        HOOK_EVENT( arcanetorrent_cd );
        HOOK_EVENT( arcanetorrent_execute );
#endif
#if (RACE == RACE_TROLL)
        HOOK_EVENT( berserking_start );
        HOOK_EVENT( berserking_expire );
        HOOK_EVENT( berserking_cd );
#endif
#if (RACE == RACE_ORC)
        HOOK_EVENT( bloodfury_start );
        HOOK_EVENT( bloodfury_expire );
        HOOK_EVENT( bloodfury_cd );
#endif
#if (RACE == RACE_UNDEAD)
        HOOK_EVENT( touch_of_the_grave_trigger );
#endif
#if defined(trinket_vial_of_convulsive_shadows)
        HOOK_EVENT( vial_of_convulsive_shadows_expire );
        HOOK_EVENT( vial_of_convulsive_shadows_start );
        HOOK_EVENT( vial_of_convulsive_shadows_cd );
#endif
#if defined(trinket_forgemasters_insignia)
        HOOK_EVENT( forgemasters_insignia_tick );
#endif
#if defined(trinket_horn_of_screaming_spirits)
        HOOK_EVENT( horn_of_screaming_spirits_trigger );
        HOOK_EVENT( horn_of_screaming_spirits_expire );
#endif
#if defined(trinket_scabbard_of_kyanos)
        HOOK_EVENT( scabbard_of_kyanos_expire );
        HOOK_EVENT( scabbard_of_kyanos_start );
        HOOK_EVENT( scabbard_of_kyanos_cd );
#endif
#if defined(trinket_badge_of_victory)
        HOOK_EVENT( badge_of_victory_expire );
        HOOK_EVENT( badge_of_victory_start );
        HOOK_EVENT( badge_of_victory_cd );
#endif
#if defined(trinket_insignia_of_victory)
        HOOK_EVENT( insignia_of_victory_expire );
        HOOK_EVENT( insignia_of_victory_trigger );
#endif
#if defined(trinket_tectus_beating_heart)
        HOOK_EVENT( tectus_beating_heart_trigger );
        HOOK_EVENT( tectus_beating_heart_expire );
#endif
#if defined(trinket_formidable_fang)
        HOOK_EVENT( formidable_fang_trigger );
        HOOK_EVENT( formidable_fang_expire );
#endif
#if defined(trinket_draenic_stone)
        HOOK_EVENT( draenic_stone_expire );
        HOOK_EVENT( draenic_stone_trigger );
#endif
#if defined(trinket_skull_of_war)
        HOOK_EVENT( skull_of_war_expire );
        HOOK_EVENT( skull_of_war_trigger );
#endif
#if defined(trinket_mote_of_the_mountain)
        HOOK_EVENT( mote_of_the_mountain_trigger );
        HOOK_EVENT( mote_of_the_mountain_expire );
#endif
#if defined(trinket_discordant_chorus)
        HOOK_EVENT( discordant_chorus_trigger );
#endif
#if defined(trinket_empty_drinking_horn)
        HOOK_EVENT( empty_drinking_horn_trigger );
        HOOK_EVENT( empty_drinking_horn_tick );
        HOOK_EVENT( empty_drinking_horn_expire );
#endif
#if defined(trinket_unending_hunger)
        HOOK_EVENT( unending_hunger_trigger );
        HOOK_EVENT( unending_hunger_expire );
#endif
#if defined(trinket_spores_of_alacrity)
        HOOK_EVENT( spores_of_alacrity_trigger );
        HOOK_EVENT( spores_of_alacrity_expire );
#endif
#if defined(trinket_bonemaws_big_toe)
        HOOK_EVENT( bonemaws_big_toe_expire );
        HOOK_EVENT( bonemaws_big_toe_start );
        HOOK_EVENT( bonemaws_big_toe_cd );
#endif
#if defined(trinket_emberscale_talisman)
        HOOK_EVENT( emberscale_talisman_expire );
        HOOK_EVENT( emberscale_talisman_start );
        HOOK_EVENT( emberscale_talisman_cd );
#endif
#if defined(trinket_gronntooth_war_horn)
        HOOK_EVENT( gronntooth_war_horn_trigger );
        HOOK_EVENT( gronntooth_war_horn_expire );
#endif
    default:
        lprintf( ( "wild class routine entry %d", e.routine ) );
        assert( 0 );
    }
}

#define initialize_rppm( proc ) safemacro(proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 ))

void spec_module_init( rtinfo_t* rti );

void class_module_init( rtinfo_t* rti ) {
    static struct class_state_t class_state;
    static struct class_debuff_t class_debuff[num_enemies];
    rti->player.class = &class_state;
    for(int i = 0; i < num_enemies; i++){
        rti->enemy[i].class = &class_debuff[i];
    }
    spec_module_init( rti );

    rti->player.power = 0.0f;

    refresh_str( rti );
    refresh_ap( rti );
    refresh_crit( rti );
    refresh_haste( rti );
    refresh_mastery( rti );
    refresh_vers( rti );

    lprintf( ( "Raid buffed str %d", rti->player.stat.str ) );
    lprintf( ( "Raid buffed ap %d", rti->player.stat.ap ) );
    lprintf( ( "Raid buffed crit %f", rti->player.stat.crit ) );
    lprintf( ( "Raid buffed haste %f", rti->player.stat.haste ) );
    lprintf( ( "Raid buffed mastery %f", rti->player.stat.mastery ) );
    lprintf( ( "Raid buffed vers %f", rti->player.stat.vers ) );

#if (BUFF_BLOODLUST == 1)
    eq_enqueue( rti, hostonly( FROM_MILLISECONDS( 1 ) ) deviceonly( rti->timestamp ), routnum_bloodlust_start, 0 );
#endif
#if (BUFF_POTION == 1)
    spell_potion( rti );
#endif

#if (thunderlord_mh || bleedinghollow_mh)
    initialize_rppm( rti->player.class->enchant_mh.proc );
#endif
#if (shatteredhand_mh)
    initialize_rppm( rti->player.class->enchant_mh );
#endif
#if (thunderlord_oh || bleedinghollow_oh)
    initialize_rppm( rti->player.class->enchant_oh.proc );
#endif
#if (shatteredhand_oh)
    initialize_rppm( rti->player.class->enchant_mh );
#endif
#if defined(trinket_forgemasters_insignia)
    initialize_rppm( rti->player.class->forgemasters_insignia.proc );
#endif // defined
#if defined(trinket_horn_of_screaming_spirits)
    initialize_rppm( rti->player.class->horn_of_screaming_spirits.proc );
#endif // defined
#if defined(trinket_tectus_beating_heart)
    initialize_rppm( rti->player.class->tectus_beating_heart.proc );
#endif // defined
#if defined(trinket_formidable_fang)
    initialize_rppm( rti->player.class->formidable_fang.proc );
#endif // defined
#if defined(trinket_mote_of_the_mountain)
    initialize_rppm( rti->player.class->mote_of_the_mountain.proc );
#endif // defined
#if defined(trinket_discordant_chorus)
    initialize_rppm( rti->player.class->discordant_chorus );
#endif // defined
#if defined(trinket_unending_hunger)
    initialize_rppm( rti->player.class->unending_hunger.proc );
#endif // defined
#if defined(trinket_spores_of_alacrity)
    initialize_rppm( rti->player.class->spores_of_alacrity.proc );
#endif // defined
#if defined(trinket_gronntooth_war_horn)
    initialize_rppm( rti->player.class->gronntooth_war_horn.proc );
#endif // defined
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u target_id );

void special_procs( rtinfo_t* rti, k32u attacktype, k32u target_id ) {
#if (RACE == RACE_UNDEAD)
    proc_ICD( rti, &rti->player.class->touch_of_the_grave, 0.2f, FROM_SECONDS( 15 ), routnum_touch_of_the_grave_trigger, target_id );
#endif
    if ( ATYPE_WHITE_MELEE == attacktype || ATYPE_YELLOW_MELEE == attacktype ){
#if (archmages_incandescence || archmages_greater_incandescence)
        if ( !UP( incandescence_expire ) ) {
            proc_RPPM( rti, &rti->player.class->incandescence.proc, 0.92f, routnum_incandescence_trigger, target_id );
        }
#endif
#if (thunderlord_mh)
        proc_RPPM( rti, &rti->player.class->enchant_mh.proc, 2.5f, routnum_enchant_mh_trigger, target_id );
#elif (bleedinghollow_mh)
        proc_RPPM( rti, &rti->player.class->enchant_mh.proc, 2.3f, routnum_enchant_mh_trigger, target_id );
#elif (shatteredhand_mh)
        proc_RPPM( rti, &rti->player.class->enchant_mh, 3.5f * ( 1.0f + rti->player.stat.haste ), routnum_enchant_mh_trigger, target_id );
#endif
#if (thunderlord_oh)
        proc_RPPM( rti, &rti->player.class->enchant_oh.proc, 2.5f, routnum_enchant_oh_trigger, target_id );
#elif (bleedinghollow_oh)
        proc_RPPM( rti, &rti->player.class->enchant_oh.proc, 2.3f, routnum_enchant_oh_trigger, target_id );
#elif (shatteredhand_oh)
        proc_RPPM( rti, &rti->player.class->enchant_oh, 3.5f * ( 1.0f + rti->player.stat.haste ), routnum_enchant_oh_trigger, target_id );
#endif
#if defined(trinket_forgemasters_insignia)
        if ( !UP( forgemasters_insignia_expire ) ) {
            proc_RPPM( rti, &rti->player.class->forgemasters_insignia.proc, 0.92f, routnum_forgemasters_insignia_tick, target_id );
        }
#endif
#if defined(trinket_horn_of_screaming_spirits)
        if ( !UP( horn_of_screaming_spirits_expire ) ) {
            proc_RPPM( rti, &rti->player.class->horn_of_screaming_spirits.proc, 0.92f, routnum_horn_of_screaming_spirits_trigger, target_id );
        }
#endif
#if defined(trinket_insignia_of_victory)
        proc_ICD( rti, &rti->player.class->insignia_of_victory.proc, 0.15f, FROM_SECONDS( 55 ), routnum_insignia_of_victory_trigger, target_id );
#endif
#if defined(trinket_tectus_beating_heart)
        if ( !UP( tectus_beating_heart_expire ) ) {
            proc_RPPM( rti, &rti->player.class->tectus_beating_heart.proc, 0.92f, routnum_tectus_beating_heart_trigger, target_id );
        }
#endif
#if defined(trinket_formidable_fang)
        if ( !UP( formidable_fang_expire ) ) {
            proc_RPPM( rti, &rti->player.class->formidable_fang.proc, 0.92f, routnum_formidable_fang_trigger, target_id );
        }
#endif
#if defined(trinket_draenic_stone)
        proc_ICD( rti, &rti->player.class->draenic_stone.proc, 0.35f, FROM_SECONDS( 55 ), routnum_draenic_stone_trigger, target_id );
#endif
#if defined(trinket_skull_of_war)
        proc_ICD( rti, &rti->player.class->skull_of_war.proc, 0.15f, FROM_SECONDS( 115 ), routnum_skull_of_war_trigger, target_id );
#endif
#if defined(trinket_mote_of_the_mountain)
        if ( !UP( mote_of_the_mountain_expire ) ) {
            proc_RPPM( rti, &rti->player.class->mote_of_the_mountain.proc, 0.92f, routnum_mote_of_the_mountain_trigger, target_id );
        }
#endif
#if defined(trinket_discordant_chorus)
        proc_RPPM( rti, &rti->player.class->discordant_chorus, 6.0f * ( 1.0f + rti->player.stat.haste ), routnum_discordant_chorus_trigger, target_id );
#endif
#if defined(trinket_empty_drinking_horn)
        eq_enqueue( rti, rti->timestamp, routnum_empty_drinking_horn_trigger, target_id );
#endif
#if defined(trinket_unending_hunger)
        proc_RPPM( rti, &rti->player.class->unending_hunger.proc, 1.0f, routnum_unending_hunger_trigger, target_id );
        if( UP( unending_hunger_expire ) && unending_hunger_stack < 20 ) {
            unending_hunger_stack++;
            rti->player.stat.gear_str += trinket_unending_hunger;
            refresh_str( rti );
            refresh_ap( rti );
        }
#endif
#if defined(trinket_spores_of_alacrity)
        if ( !UP( spores_of_alacrity_expire ) ) {
            proc_RPPM( rti, &rti->player.class->spores_of_alacrity.proc, 0.92f, routnum_spores_of_alacrity_trigger, target_id );
        }
#endif
#if defined(trinket_gronntooth_war_horn)
        proc_RPPM( rti, &rti->player.class->gronntooth_war_horn.proc, 1.5f, routnum_gronntooth_war_horn_trigger, target_id );
#endif
    }
    spec_special_procs( rti, attacktype, target_id );
}
