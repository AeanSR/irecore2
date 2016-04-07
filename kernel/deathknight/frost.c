//
//  frost.c
//  
//
//  Created by Tianjian Guo on 4/6/16.
//
//
/* Tier 1*/
struct spec_state_t{
    struct {
    } frost_strike;
    struct {
    }howling_blast;
    struct{
    }obliterate;
    struct{
        time_t cd;
    }empower_rune_weapon;
    #define empower_rune_weapon_cd  (rti->player.spec->empower_rune_weapon.cd)
    struct{
        time_t cd;
    }pillar_of_frost;
    #define pillar_of_frost_cd  (rti->player.spec->pillar_of_frost.cd)
    struct{
        time_t cd;
    }remorseless_winter;
    #define remorseless_winter_cd (rti->player.spec->remorseless_winter.cd)
#if (TALENT_HORN_OF_WINTER)
    struct{
        time_t cd;
    }horn_of_winter;
    #define horn_of_winter_cd (rti->player.spec->horn_of_winter.cd)
#else
    #define horn_of_winter_cd (0)
#endif
#if (TALENT_HUNGERING_RUNE_WEAPON)
    struct{
        time_t cd;
        time_t expire;
    }hungering_rune_weapon;
    #define hungering_rune_weapon_cd (rti->player.spec->hungering_rune_weapon.cd)
    #define hungering_rune_weapon_expire (rti->player.spec->hungering_rune_weapon.expire)
#else
    #define hungering_rune_weapon_cd (0)
    #define hungering_rune_weapon_expire (0)
#endif
#if (TALENT_FROSTSCYTHE
    struct{
        time_t cd;
    }frostscythe;
    #define frostscythe_cd (rti->player.spec->frostscythe.cd)
#else
    #define frostscythe_cd (0)
#endif
#if (TALENT_OBLITERATION)
    struct{
        time_t cd;
        time_t expire;
    }obliteration;
    #define obliteration_cd (rti->player.sepc->obliteration.cd)
    #define obliteration_expire (rti->player.sepc->obliteration.expire)
#else
    #define obliteration_cd (0)
    #define obliteration_expire (0)
#endif
#if(TALENT_BREATH_OF_SINDRAGOSA)
    struct{
        time_t cd;
    }breath_of_sindragosa;
    #define breath_of_sindragosa_cd (tri->player.spec->breath_of_sindragosa.cd)
#else
    #define breath_of_sindragosa_cd (0)
#endif
#if (TALENT_GLACIAL_ADVANCE)
    struct{
        time_t cd;
    }glacial_advance;
    #define glacial_advance_cd (tri->player.spec->glacial_advance.cd)
#else
    #define glacial_advance_cd (0)
#endif
};
struct class_debuff_t {
};

