// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Aniket Chavan (z5265106)
// on 29-04-19
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Added pointer check for the provided tests.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.


// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

#define WEEDLE_ID 13
#define WEEDLE_NAME "Weedle"
#define WEEDLE_HEIGHT 0.3
#define WEEDLE_WEIGHT 3.2
#define WEEDLE_FIRST_TYPE BUG_TYPE
#define WEEDLE_SECOND_TYPE POISON_TYPE

#define CATERPIE_ID 10
#define CATERPIE_NAME "Caterpie"
#define CATERPIE_HEIGHT 0.3
#define CATERPIE_WEIGHT 2.9
#define CATERPIE_FIRST_TYPE BUG_TYPE
#define CATERPIE_SECOND_TYPE NONE_TYPE

#define GLOOM_ID 44
#define GLOOM_NAME "Gloom"
#define GLOOM_HEIGHT 0.8
#define GLOOM_WEIGHT 8.6
#define GLOOM_FIRST_TYPE POISON_TYPE
#define GLOOM_SECOND_TYPE GRASS_TYPE

#define OMANYTE_ID 138
#define OMANYTE_NAME "Omanyte"
#define OMANYTE_HEIGHT 0.4
#define OMANYTE_WEIGHT 7.5
#define OMANYTE_FIRST_TYPE WATER_TYPE
#define OMANYTE_SECOND_TYPE ROCK_TYPE

#define OMASTER_ID 139
#define OMASTER_NAME "Omaster"
#define OMASTER_HEIGHT 1.0
#define OMASTER_WEIGHT 35.0
#define OMASTER_FIRST_TYPE WATER_TYPE
#define OMASTER_SECOND_TYPE ROCK_TYPE

#define KABUTO_ID 140
#define KABUTO_NAME "Kabuto"
#define KABUTO_HEIGHT 0.5
#define KABUTO_WEIGHT 11.5
#define KABUTO_FIRST_TYPE WATER_TYPE
#define KABUTO_SECOND_TYPE ROCK_TYPE

#define KABUTOPS_ID 141
#define KABUTOPS_NAME "Kabutops"
#define KABUTOPS_HEIGHT 1.3
#define KABUTOPS_WEIGHT 40.5
#define KABUTOPS_FIRST_TYPE WATER_TYPE
#define KABUTOPS_SECOND_TYPE ROCK_TYPE

#define AERODACTYL_ID 142
#define AERODACTYL_NAME "Aerodactyl"
#define AERODACTYL_HEIGHT 1.8
#define AERODACTYL_WEIGHT 59.0
#define AERODACTYL_FIRST_TYPE FLYING_TYPE
#define AERODACTYL_SECOND_TYPE ROCK_TYPE

#define HOOTHOOT_ID 163
#define HOOTHOOT_NAME "Hoothoot"
#define HOOTHOOT_HEIGHT 0.7
#define HOOTHOOT_WEIGHT 21.2
#define HOOTHOOT_FIRST_TYPE NORMAL_TYPE
#define HOOTHOOT_SECOND_TYPE FLYING_TYPE

#define PICHU_ID 172
#define PICHU_NAME "Pichu"
#define PICHU_HEIGHT 0.3
#define PICHU_WEIGHT 2.0
#define PICHU_FIRST_TYPE ELECTRIC_TYPE
#define PICHU_SECOND_TYPE NONE_TYPE

#define PIKACHU_ID 25
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 0.4
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

#define MAGIKARP_ID 129
#define MAGIKARP_NAME "Magikarp"
#define MAGIKARP_HEIGHT 0.9
#define MAGIKARP_WEIGHT 10.0
#define MAGIKARP_FIRST_TYPE WATER_TYPE
#define MAGIKARP_SECOND_TYPE NONE_TYPE

// Add your own prototypes here.
static void test_remove_pokemon(void);
static void test_add_evolution(void);
static void test_search_pokemon(void);
static Pokemon create_weedle(void);
static Pokemon create_caterpie(void);
static Pokemon create_gloom(void);
static Pokemon create_omanyte(void);
static Pokemon create_omaster(void);
static Pokemon create_kabuto(void);
static Pokemon create_kabutops(void);
static Pokemon create_aerodactyl(void);
static Pokemon create_hoothoot(void);
static Pokemon create_pichu(void);
static Pokemon create_pikachu(void);
static Pokemon create_magikarp(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_found_pokemon(void);
static void test_next_pokemon(void);

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_remove_pokemon();
    test_get_found_pokemon();
    test_add_evolution();
    test_search_pokemon();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}

////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Weedle, Kabutops, Hoothoot\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon weedle = create_weedle();
    Pokemon kabutops = create_kabutops();
    Pokemon hoothoot = create_hoothoot();

    printf("    ... Adding Bulbasaur, Weedle, Kabutops, Hoothoot"
            " to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, weedle);
    add_pokemon(pokedex, kabutops);
    add_pokemon(pokedex, hoothoot);
    
    printf("    ... printing to see added pokemon\n");
    print_pokemon(pokedex);
    
    printf("    ... count_total_pokemon should give 4\n");
    assert(count_total_pokemon(pokedex) == 4);
    
    printf("    ... First pokemon added, Bulbasaur, should be selected\n"
        "     ... we'll find it and print_detail to find out if that's true\n");
    find_current_pokemon(pokedex);
    detail_pokemon(pokedex);
    assert(is_same_pokemon(bulbasaur,get_current_pokemon(pokedex)));
    
    printf("    ... Adding Kabuto and Gloom to the pokedex\n");
    Pokemon kabuto = create_kabuto();
    Pokemon gloom = create_gloom();
    add_pokemon(pokedex, kabuto);
    add_pokemon(pokedex, gloom);
    
    printf("   ... Printing all pokemon, Kabuto should be added to list\n");
    print_pokemon(pokedex);

    printf("\n    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("\n    ... Using next_pokemon without "
           "pokemon should print an error but continue just fine\n");
    next_pokemon(pokedex);

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("    ... Printing pokemon in the pokedex\n");
    print_pokemon(pokedex);
    
    printf("\n    ... Trying to select the next pokemon when there is none\n");
    next_pokemon(pokedex);
    
    printf("    ... Adding Ivysaur as a pokemon\n");
    add_pokemon(pokedex, ivysaur);

    printf("\n       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("\n       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("\n    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}
//Test remove_pokemon tests for these situations:
// --> Calling the function on an empty pokedex
// --> Calling the function normally
static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling remove_pokemon on the empty pokedex\n");
    remove_pokemon(pokedex);
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("    ... Removing Bulbasaur\n");
    remove_pokemon(pokedex);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("\n    ... Removing Ivysaur\n");
    remove_pokemon(pokedex);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("\n    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);
    
    printf(">> Passed remove_pokemon tests!\n");
}

static void test_go_exploring(void) {
    printf("\n>> Testing go_exploring\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur, Weedle, Caterpie, "
           "Omanyte, Omaster, Kabuto, Kabutops and Aerodactyl\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon weedle = create_weedle();
    Pokemon caterpie = create_caterpie();
    Pokemon omanyte = create_omanyte();
    Pokemon omaster = create_omaster();
    Pokemon kabuto = create_kabuto();
    Pokemon kabutops = create_kabutops();
    Pokemon aerodactyl = create_aerodactyl();
    
    printf("    ... Adding all pokemon to pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, weedle);
    add_pokemon(pokedex, caterpie);
    add_pokemon(pokedex, omanyte);
    add_pokemon(pokedex, omaster);
    add_pokemon(pokedex, kabuto);
    add_pokemon(pokedex, kabutops);
    add_pokemon(pokedex, aerodactyl);
    
    printf("\n    ... Going exploring\n");
    printf("    ... Seed = 1, factor = 150, how_many = 8");
    go_exploring(pokedex, 1, 150, 8);
    
    printf("    ... Printing all pokemon, some should be found now");
    print_pokemon(pokedex);
    
    printf("\n    ... Destroying pokedex\n");
    destroy_pokedex(pokedex);
    
    printf("    ... Passed go_explore tests!");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("\n    ... Calling get_found on the empty pokedex\n");
    Pokedex foundex = get_found_pokemon(pokedex);
    
    printf("    ... Printing the foundex (found pokedex)\n");
    print_pokemon(foundex);
    
    printf("    ... Destroying the foundex (found pokedex)\n");
    destroy_pokedex(foundex);

    printf("\n    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("    ... Calling get_found when no pokemon are found\n");
    Pokedex foundex_two = get_found_pokemon(pokedex);
    
    printf("    ... Destroying the foundex again\n");
    destroy_pokedex(foundex_two);
    
    printf("\n       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);
    print_pokemon(found_pokedex);
    
    printf("       --> Checking the correct Pokemon "
           "were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    
    printf("\n    ... Destroying the foundex again\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Adding Gloom, Hoothoot, Weedle and Kabuto and finding all\n");
    Pokemon gloom = create_gloom();
    Pokemon hoothoot = create_hoothoot();
    Pokemon weedle = create_weedle();
    Pokemon kabuto = create_kabuto();
    add_pokemon(pokedex, gloom);
    add_pokemon(pokedex, hoothoot);
    add_pokemon(pokedex, weedle);
    add_pokemon(pokedex, kabuto);
    
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    
    printf("    ... Printing pokemon to show they aren't "
           "in ascending ID order\n");
    print_pokemon(pokedex);
    
    printf("\n    --> Calling get_found\n");
    Pokedex foundex_three = get_found_pokemon(pokedex);
    
    printf("    ... Printing pokemon in foundex to show ascending ID ordern\n");
    print_pokemon(foundex_three);
    
    printf("\n    ... Destroying both Pokedexes\n");
    destroy_pokedex(foundex_three);
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}

//Test_add_evolution tests a couple of situations such as:
// --> What if you try to evolve a pokemon into one that hasn't been added
// --> What if happens if you try to evolve a pokemon into itself
// --> What if you show_evolutions on an evolution set with all found pokemon
// --> What if you show_evolutions on an evolution set with unfound pokemon
// --> What if you remove a pokemon from the evolution line and try to use
//      show_evolutions on the base pokemon
static void test_add_evolution(void) {
    printf("\n>> Testing add_evolution\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("\n    --> Calling search_pokemon on an empty pokedex\n");
    Pokedex nodex = search_pokemon(pokedex, "whatever");
    
    printf("    ... Printing searchdex of an empty pokedex");
    print_pokemon(nodex);
    
    printf("    ... Adding Bulbasaur, Ivysaur, Hoothoot, Kabuto, Kabutops\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon hoothoot = create_hoothoot();
    Pokemon kabuto = create_kabuto();
    Pokemon kabutops = create_kabutops();
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, hoothoot);
    add_pokemon(pokedex, kabuto);
    add_pokemon(pokedex, kabutops);
    
    printf("    ... Printing all added pokemon\n");
    print_pokemon(pokedex);
    
    printf("\n    --> Trying to make Bulbasaur evolve into #300 "
           "which hasn't been added yet\n");
    add_pokemon_evolution(pokedex, 1, 300);
    
    printf("\n    --> Trying to make Bulbasaur evolve into itself\n");
    add_pokemon_evolution(pokedex, 1, 1);
    
    printf("    ... find Bulbasaur, Ivysaur,and Kabuto\n");
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    change_current_pokemon(pokedex, 140);
    find_current_pokemon(pokedex);
    
    printf("    ... Printing pokemon to show found pokemon\n");
    print_pokemon(pokedex);
    
    printf("\n    --> Adding evolution of Bulbasaur -> Ivysaur\n");
    add_pokemon_evolution(pokedex, 1, 2);
    
    printf("    ... Showing evolution of Bulbasaur, with a found Ivysaur\n");
    change_current_pokemon(pokedex, 1);
    show_evolutions(pokedex);
    
    printf("\n    --> Adding evolution of Kabuto -> Kabutops\n");
    add_pokemon_evolution(pokedex, 140, 141);
    
    printf("    ... Showing evolution of Kabuto, with and unfound Kabutops\n");
    change_current_pokemon(pokedex, 140);
    show_evolutions(pokedex);
    
    printf("\n    --> Removing Kabutops");
    next_pokemon(pokedex);
    remove_pokemon(pokedex);
    
    printf("    ... Showing evolution of Kabuto, with a removed Kabubtops\n");
    show_evolutions(pokedex);
    
    printf("\n    ... Creating and adding Pichu and Pikachu\n");
    Pokemon pichu = create_pichu();
    Pokemon pikachu = create_pikachu();
    add_pokemon(pokedex, pichu);
    add_pokemon(pokedex, pikachu);
    
    printf("    ... Printing Pokemon\n");
    print_pokemon(pokedex);
    
    printf("    --> Adding evolution of Pichu -> Pikachu\n");
    add_pokemon_evolution(pokedex, 172, 25);
    
    printf("    ... Changing current pokemon to Pichu\n");
    change_current_pokemon(pokedex, 172);
    
    printf("    ... Showing evolution of Pichu\n");
    show_evolutions(pokedex);
    
    printf("    ... Using get_next_evolution to change to Pikachu\n");
    change_current_pokemon(pokedex, get_next_evolution(pokedex));
    assert(is_same_pokemon(pikachu, get_current_pokemon(pokedex)));
    
    printf("    ... Finding Pikachu and showing details\n");
    find_current_pokemon(pokedex);
    detail_pokemon(pokedex);
    
    printf("    ... Destroying the pokedex\n");
    destroy_pokedex(pokedex);
    
    printf(">> Passed Evolution tests!\n");
}
//The get_pokemon_of_type Test tests the following situations:
// --> Calling the function on an empty pokedex
// --> Calling the function on a normal type
// --> Calling the function on an existing TypeDex to have a secondary filter
static void test_pokemon_of_type(void) {
    printf("\n>> Testing get_pokemon_of_type\n");
    
    printf("    ... Creating a new pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    --> Calling get_pokemon_of_type on an empty pokedex\n");
    Pokedex grassdex = get_pokemon_of_type(pokedex, GRASS_TYPE);
    
    printf("    ... Printing first TypeDex (type specific pokedex)\n");
    print_pokemon(grassdex);
    
    printf("    ... Destroying first TypeDex\n");
    destroy_pokedex(grassdex);
    
    printf("\n    ... Creating Bulbasaur, Magikarp"
           "Omanyte, Omaster, Kabuto, Kabutops and Aerodactyl\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon magikarp = create_magikarp();
    Pokemon omanyte = create_omanyte();
    Pokemon omaster = create_omaster();
    Pokemon kabuto = create_kabuto();
    Pokemon kabutops = create_kabutops();
    Pokemon aerodactyl = create_aerodactyl();
    
    printf("    ... Adding all pokemon to pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, magikarp);
    add_pokemon(pokedex, omanyte);
    add_pokemon(pokedex, omaster);
    add_pokemon(pokedex, kabuto);
    add_pokemon(pokedex, kabutops);
    add_pokemon(pokedex, aerodactyl);
    
    printf("    ... Finding all pokemon\n");
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("    --> Creating a Typedex for ROCK TYPE");
    Pokedex rockdex = get_pokemon_of_type(pokedex, ROCK_TYPE);
    
    printf("    ... Printing all Rock Type pokemon\n");
    print_pokemon(rockdex);
    
    printf("\n   --> Creating a Typedex for WATER TYPE\n");
    Pokedex waterdex = get_pokemon_of_type(rockdex, WATER_TYPE);
    
    printf("    ... Printing all pokemon, Aerodactyl should be filtered out\n"
           "     ... and Magikarp wasn't in rockDex so should not be included");
    print_pokemon(waterdex);
    assert(count_total_pokemon(waterdex) == 4);
    
    printf("    ... Destroying all pokedexs");
    destroy_pokedex(waterdex);
    destroy_pokedex(rockdex);
    destroy_pokedex(pokedex);
    
    printf(">> Passed all get_pokemon_of_type tests!");
}

// This tests out a few areas of the search_pokemon function including: 
// --> Making sure it isn't case-sensitive searches (Test 1 - 'sAuR')
// --> Making sure it keeps checking after finding a partial substring and
//      failing it (Test 2 - 'oM')
// --> Making sure it can search within a searched pokedex (Test 3)
static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");
    
    printf("    ... Creating a new pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Calling search_pokemon on an empty pokedex\n");
    Pokedex nodex = search_pokemon(pokedex, "whatever");
    
    printf("    ... Printing searchdex of an empty pokedex");
    print_pokemon(nodex);
    
    printf("\n    ... Creating Bulbasaur, Ivysaur, Weedle, "
           "Caterpie, Omanyte, Gloom\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon weedle = create_weedle();
    Pokemon caterpie = create_caterpie();
    Pokemon gloom = create_gloom();
    Pokemon omanyte = create_omanyte();
    Pokemon omaster = create_omaster();
    Pokemon kabuto = create_kabuto();
    Pokemon kabutops = create_kabutops();
    Pokemon aerodactyl = create_aerodactyl();
    Pokemon hoothoot = create_hoothoot();
    
    printf("    ... Adding pokemon to the pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, weedle);
    add_pokemon(pokedex, caterpie);
    add_pokemon(pokedex, omanyte);
    add_pokemon(pokedex, omaster);
    add_pokemon(pokedex, gloom);
    add_pokemon(pokedex, kabuto);
    add_pokemon(pokedex, kabutops);
    add_pokemon(pokedex, aerodactyl);
    add_pokemon(pokedex, hoothoot);
    
    printf("    ... Printing all pokemon\n");
    print_pokemon(pokedex);
    
    printf("    ... Finding all pokemon\n");
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    next_pokemon(pokedex);
    find_current_pokemon(pokedex);
    
    printf("\n>> Test 1 - search_pokemon is not case-sensitive. \n");
    printf("    ... Printing all found pokemon\n");
    print_pokemon(pokedex);
    
    printf("    --> Searching through pokedex for 'sAuR' in pokedex\n");
    Pokedex searchdex = search_pokemon(pokedex, "sAuR");
    
    printf("    ... Printing searchDex\n");
    print_pokemon(searchdex);
    
    printf("    ... Destroying searchDex\n");
    destroy_pokedex(searchdex);
    
    printf("\n>> Test 2 - search_pokemon keeps rechecking for substring"
            " after finding a partial substring\n");
    
    printf("    --> Searching through pokedex for 'oM'\n");
    Pokedex searchdex_two = search_pokemon(pokedex, "oM");
    
    printf("    --> Printing searchDex\n");
    print_pokemon(searchdex_two);
    
    printf("    ... Destroying searchDex\n");
    destroy_pokedex(searchdex_two);
    
    printf("\n>> Test 3 - search_pokemon can search inside "
            "pokedex's create with search_pokemon\n");
    
    printf("    --> Searching through pokedex for 'o'\n");
    Pokedex searchdex_three = search_pokemon(pokedex, "o");
    
    printf("    ... Prints all pokemon found\n");
    print_pokemon(searchdex_three);
    
    printf("    --> Searching through searchDex for 'but'\n");
    Pokedex searchdex_four = search_pokemon(searchdex_three,"but");
    
    printf("    ... Printing searchDex_two\n");
    print_pokemon(searchdex_four);
    
    printf("    ... Destroying searchDex and searchDex_two\n");
    destroy_pokedex(searchdex_four);
    destroy_pokedex(searchdex_three); 
    
    destroy_pokedex(pokedex);
    printf(">> Passed search_pokemon tests!\n");
}

////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_weedle(void) {
    Pokemon pokemon = new_pokemon(
            WEEDLE_ID, WEEDLE_NAME,
            WEEDLE_HEIGHT, WEEDLE_WEIGHT, 
            WEEDLE_FIRST_TYPE, WEEDLE_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_caterpie(void) {
    Pokemon pokemon = new_pokemon(
            CATERPIE_ID, CATERPIE_NAME,
            CATERPIE_HEIGHT, CATERPIE_WEIGHT, 
            CATERPIE_FIRST_TYPE, CATERPIE_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_gloom(void) {
    Pokemon pokemon = new_pokemon(
            GLOOM_ID, GLOOM_NAME,
            GLOOM_HEIGHT, GLOOM_WEIGHT, 
            GLOOM_FIRST_TYPE, GLOOM_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_omanyte(void) {
    Pokemon pokemon = new_pokemon(
            OMANYTE_ID, OMANYTE_NAME,
            OMANYTE_HEIGHT, OMANYTE_WEIGHT, 
            OMANYTE_FIRST_TYPE, OMANYTE_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_omaster(void) {
    Pokemon pokemon = new_pokemon(
            OMASTER_ID, OMASTER_NAME,
            OMASTER_HEIGHT, OMASTER_WEIGHT, 
            OMASTER_FIRST_TYPE, OMASTER_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_kabuto(void) {
    Pokemon pokemon = new_pokemon(
            KABUTO_ID, KABUTO_NAME,
            KABUTO_HEIGHT, KABUTO_WEIGHT, 
            KABUTO_FIRST_TYPE, KABUTO_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_kabutops(void) {
    Pokemon pokemon = new_pokemon(
            KABUTOPS_ID, KABUTOPS_NAME,
            KABUTOPS_HEIGHT, KABUTOPS_WEIGHT, 
            KABUTOPS_FIRST_TYPE, KABUTOPS_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_aerodactyl(void) {
    Pokemon pokemon = new_pokemon(
            AERODACTYL_ID, AERODACTYL_NAME,
            AERODACTYL_HEIGHT, AERODACTYL_WEIGHT, 
            AERODACTYL_FIRST_TYPE, AERODACTYL_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_hoothoot(void) {
    Pokemon pokemon = new_pokemon(
            HOOTHOOT_ID, HOOTHOOT_NAME,
            HOOTHOOT_HEIGHT, HOOTHOOT_WEIGHT, 
            HOOTHOOT_FIRST_TYPE, HOOTHOOT_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_pichu(void) {
    Pokemon pokemon = new_pokemon(
            PICHU_ID, PICHU_NAME,
            PICHU_HEIGHT, PICHU_WEIGHT, 
            PICHU_FIRST_TYPE, PICHU_SECOND_TYPE
    );
    return pokemon;
}
static Pokemon create_pikachu(void) {
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT, 
            PIKACHU_FIRST_TYPE, PIKACHU_SECOND_TYPE
    );
    return pokemon;
}

static Pokemon create_magikarp(void) {
    Pokemon pokemon = new_pokemon(
            MAGIKARP_ID, MAGIKARP_NAME,
            MAGIKARP_HEIGHT, MAGIKARP_WEIGHT, 
            MAGIKARP_FIRST_TYPE, MAGIKARP_SECOND_TYPE
    );
    return pokemon;
}
// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!
