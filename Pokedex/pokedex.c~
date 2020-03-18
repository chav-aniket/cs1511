// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by ANIKET-CHAVAN (z5265106)
// on 17-04-19
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
    struct pokenode *selected;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *evolution;
    struct pokenode *prevolution;
    Pokemon         pokemon;
    int             id;
    int             found;
};
// Add any other structs you define here.


// Add prototypes for any extra functions you create here.
typedef struct pokenode *Pokenode;

static Pokenode new_pokenode(Pokemon pokemon);
static void print_id(Pokemon pokemon, int suffix, int newline);
static void print_unfound(Pokemon pokemon);
static int compare_id(int first_id, int second_id);
static int compare_type(pokemon_type type, Pokemon pokemon);
static int manual_tolower (int input);
static int substr_check(Pokedex pokedex, Pokemon pokemon, char *sub);
static void find_all_pokemon(Pokedex pokedex);
static void pokemon_rand_find(Pokedex pokedex, int seed, 
                              int factor, int how_many);
static int check_if_all_pokemon_unfound(Pokedex pokedex);
// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    new_pokedex->selected = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

//Adding a new poekmon to the pokedex
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    
    Pokenode new_node = new_pokenode(pokemon);
    //If this is the first pokemon being added
    if (pokedex->head == NULL) {
        pokedex->head = new_node;
        pokedex->selected = pokedex->head;
    } else {
    //If this is anything other than the first pokemon being added
        struct pokenode *tmp = pokedex->head;
        while (tmp->next != NULL) {
            if (tmp->id == pokemon_id(pokemon)) {
            //If a pokemon with the same ID has been added already
                printf("This pokemon has already been added.\n");
                exit(1);
            }
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}
//Printing details of found pokemon and empty field of unfound but added pokemon
void detail_pokemon(Pokedex pokedex) {
    Pokemon pokemon = pokedex->selected->pokemon;
    //If pokemon has been found
    if (pokedex->selected->found) {
        printf("Id: ");
        print_id(pokemon, 0, 1);
        printf("Name: %s\n",pokemon_name(pokemon));
        printf("Height: %.1fm\n",pokemon_height(pokemon));
        printf("Weight: %.1fkg\n",pokemon_weight(pokemon));
        printf("Type: %s",pokemon_type_to_string(pokemon_first_type(pokemon)));
        if (pokemon_second_type(pokemon) != NONE_TYPE) {
            printf(" %s",pokemon_type_to_string(pokemon_second_type(pokemon)));
        }
        printf("\n");
    } else {
    //If pokemon has not been found
        printf("Id: ");
        print_id(pokemon, 0, 1);
        printf("Name: ");
        print_unfound(pokemon);
        printf("\n");
        printf("Height: --\n"
               "Weight: --\n"
               "Type: --\n");
    }
}
//Geting the currently selected pokemon
Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        printf("The Pokedex is currently empty.\n");
        exit(1);
    }
    return pokedex->selected->pokemon;
}
//Finding the currently selected pokemon, unlocking all its data in the pokedex
void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->selected != NULL) {
        pokedex->selected->found = 1;
    }
}
//Prints all pokemon added showing which is selected
// ALso hides the names of unfound ones
void print_pokemon(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    if (tmp == NULL) {
        return;
    } else {
        while (tmp != NULL) {
            if (compare_id(pokedex->selected->id,tmp->id)) {
                printf("--> ");
            } else {
                printf("    ");
            }
            printf("#");
            print_id(tmp->pokemon,1,0);
            if (tmp->found) {
                printf("%s",pokemon_name(tmp->pokemon));
            } else {
                print_unfound(tmp->pokemon);
            }
            printf("\n");
            tmp = tmp->next;
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

//Changes the selected pokemon to the next one
void next_pokemon(Pokedex pokedex) {
    if (pokedex->selected == NULL) {
        return;
    } else if (pokedex->selected->next == NULL) {
        return;
    } else {
        pokedex->selected = pokedex->selected->next;
    }
}
//Changes the selected pokemon to the previous one
void prev_pokemon(Pokedex pokedex) {
    if (pokedex->selected == NULL) {
        return;
    } else if (compare_id(pokedex->head->id,pokedex->selected->id)) {
        return;
    } else {
        struct pokenode *tmp = pokedex->head;
        while (tmp->next->id != pokedex->selected->id) {
            tmp = tmp->next;
        }
        pokedex->selected = tmp;
    }
}
//Changes the selected pokemon to the pokemon of the given ID
void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        if (tmp->id == id) {
            pokedex->selected = tmp;
            break;
        }
        tmp = tmp->next;
    }
}
//Removes the currently selected pokemon and frees all allocated memory
void remove_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) return;
    struct pokenode *tmp_selected = pokedex->selected;
    //Tmp here checks if the pokemon being removed has a pre-evolution
    // if it does, it is set to the pre-evo and sets its evolution to NULL
    struct pokenode *tmp = pokedex->selected->prevolution;
    if (tmp != NULL) tmp->evolution = NULL;
    
    //If the selected pokemon is the first one
    if (pokedex->selected->id == pokedex->head->id) {
        tmp_selected = pokedex->head;
        pokedex->head = pokedex->head->next;
        pokedex->selected = pokedex->head;
    } else {
    //If the selected pokemon is anything but the first
        struct pokenode *tmp = pokedex->head;
        while (!compare_id(tmp->next->id, pokedex->selected->id)) {
            tmp = tmp->next;
        }
        if (pokedex->selected->next != NULL) {
        //If selected has a pokemon after it
            tmp_selected = pokedex->selected;
            pokedex->selected = pokedex->selected->next;
            tmp->next = pokedex->selected;
        } else {
        //If there is no pokemon after selected
            tmp_selected = pokedex->selected;
            pokedex->selected = tmp;
            pokedex->selected->next = NULL;
        }
    }
    //free memory allocated with removed pokemon and node
    destroy_pokemon(tmp_selected->pokemon);
    free(tmp_selected);
}
//Destroys the pokedex and frees all allocated memory
void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    struct pokenode *trail = tmp;
    while (tmp != NULL) {
        trail = tmp;
        tmp = tmp->next;
        destroy_pokemon(trail->pokemon);
        free(trail);
    }
    free(pokedex);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

//Finds an added pokemon randomly based on the parameters given
void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    int pokemon_available = 0;
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        if (tmp->id < factor) {
            pokemon_available = 1;
        }
        tmp = tmp->next;
    }
    if (!pokemon_available) {
        printf("There are no pokemon added between 0 and %03d.\n",factor);
        exit(1);
    }
    
    if (count_found_pokemon(pokedex) == count_total_pokemon(pokedex)) {
        return;
    } else {
        pokemon_rand_find(pokedex, seed, factor, how_many);
    }
}
//Counts the number of pokemon found
int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    int counter = 0;
    while (tmp != NULL) {
        if (tmp->found) {
            counter++;
        }
        tmp = tmp->next;
    }
    return counter;
}
//Counts the number of pokemon added to the pokedex
int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    int counter = 0;
    while (tmp != NULL) {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

//Creates secondary linked lists allowing for evolutions to be connected
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    if (pokedex->head == NULL) return;
    struct pokenode *from = pokedex->head;
    struct pokenode *to = pokedex->head;
    //Finds the nodes with associated ID's or else pushes both lists to NULL
    while (from != NULL) {
        if (from->id != from_id) {
            from = from->next;
        } else {
            break;
        }
    }
    while (to != NULL) {
        if (to->id != to_id) {
            to = to->next;
        } else {
            break;
        }
    }
    //If either list is NULL or if both ID's are the same, prints out the error
    if (from_id == to_id) {
        printf("The given ids are the same.\n");
    } else if (to == NULL) {
        printf("There is no pokemon with ID to evolve"
               "from added in the pokedex");
    } else if (to == NULL) {
        printf("There is no pokemon with ID to evolve" 
               "to added in the pokedex");
    } else {
        from->evolution = to;
        to->prevolution = from;
    }
}
//Shows the evolution line of the currently selected pokemon
void show_evolutions(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->selected;
    if (pokedex->selected == NULL) return;
    while (tmp != NULL) {
        printf("#");
        print_id(tmp->pokemon,0,0);
        if (tmp->found) {
            printf(" %s ",pokemon_name(tmp->pokemon));
            printf("[%s",
            pokemon_type_to_string(pokemon_first_type(tmp->pokemon)));
            if (pokemon_second_type(tmp->pokemon) != NONE_TYPE) {
                printf(",%s",
                pokemon_type_to_string(pokemon_second_type(tmp->pokemon)));
            }
            printf("]");
        } else {
            printf(" ???? ");
            printf("[????]");
        }
        if (tmp->evolution != NULL) {
            printf(" --> ");
        }
        tmp = tmp->evolution;
    }
    printf("\n");
}
//Returns the ID of the pokemon the currently selected pokemon evolves into
int get_next_evolution(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        printf("The Pokedex is currently empty.\n");
        exit(1);
    } else if (pokedex->selected->evolution == NULL) {
        return DOES_NOT_EVOLVE;
    }
    return pokedex->selected->evolution->id;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

//Creates a pokedex filled only with pokemon of a certain type
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        printf("Type given is invalid");
        exit(1);
    }
    Pokedex typedex = new_pokedex();
    
    if (check_if_all_pokemon_unfound(pokedex)) {
        return typedex;
    }
    
    struct pokenode *pokedex_tmp = pokedex->head;
    while (pokedex_tmp != NULL) {
        if (compare_type(type,pokedex_tmp->pokemon) &&
            pokedex_tmp->found) {
            Pokemon pokemon = clone_pokemon(pokedex_tmp->pokemon);
            add_pokemon(typedex, pokemon);
        }
        pokedex_tmp = pokedex_tmp->next;
    }
    find_all_pokemon(typedex);
    return typedex;
}
//Creates a pokedex filled only with found pokemon in increasing ID order
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex foundex = new_pokedex();
    
    if (check_if_all_pokemon_unfound(pokedex)) {
        return foundex;
    }
    
    int prev_id = 0;
    int pokemon_added = 0;
    int tmp_selected_id = 1000;
    
    struct pokenode *tmp = pokedex->head;
    struct pokenode *tmp_selected;
    
    while (pokemon_added != count_found_pokemon(pokedex)) {
        tmp = pokedex->head;
        tmp_selected_id = 1000;
        while (tmp != NULL) {
            if ((tmp->id - prev_id < tmp_selected_id - prev_id) && 
                tmp->found && (tmp->id - prev_id > 0)) {
                tmp_selected_id = tmp->id;
                tmp_selected = tmp;
            }
            tmp = tmp->next;
        }
        Pokemon pokemon = clone_pokemon(tmp_selected->pokemon);
        prev_id = tmp_selected->id;
        add_pokemon(foundex, pokemon);
        pokemon_added++;
    }
    find_all_pokemon(foundex);
    return foundex;
}
//Creates a pokedex based off of whether the pokemon 
// features a substring within its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex searchdex = new_pokedex();
    
    if (check_if_all_pokemon_unfound(pokedex)) {
        return searchdex;
    }
    
    struct pokenode *tmp = pokedex->head;
    
    while (tmp != NULL) {
        if (tmp->found && substr_check(searchdex,tmp->pokemon,text)) {
            Pokemon pokemon = clone_pokemon(tmp->pokemon);
            add_pokemon(searchdex, pokemon);
        }
        tmp = tmp->next;
    }
    find_all_pokemon(searchdex);
    return searchdex;
}
// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

//Creates new pokenode
static Pokenode new_pokenode(Pokemon pokemon) {
    Pokenode new_pokenode = malloc(sizeof(struct pokenode));
    assert(new_pokenode != NULL);
    new_pokenode->pokemon = pokemon;
    new_pokenode->id = pokemon_id(pokemon);
    new_pokenode->found = 0;
    new_pokenode->next = NULL;
    new_pokenode->evolution = NULL;
    new_pokenode->prevolution = NULL;
    return new_pokenode;
}
//Prints out the id in the appropriate format
//Also allows for customisable text additions before and after the id
static void print_id(Pokemon pokemon, int suffix, int newline) {
    int id = pokemon_id(pokemon);
    printf("%03d",id);
    if (suffix) printf(": ");
    if (newline) printf("\n");
}
//Prints the correct amount of asterisks for an unfound pokemon
static void print_unfound(Pokemon pokemon) {
    for (int i = 0; pokemon_name(pokemon)[i] != '\0'; i++) {
        printf("*");
    }
}
//Compares the ids of two pokemon
static int compare_id(int first_id, int second_id) {
    if (first_id == second_id) return 1;
    return 0;
}
//Compares the types of two pokemon
static int compare_type(pokemon_type type, Pokemon pokemon) {
    if (type == pokemon_first_type(pokemon) || 
        type == pokemon_second_type(pokemon)) {
        return 1;
    }
    return 0;
}

static int manual_tolower (int input) {
    if (input >= 'A' && input <= 'Z') {
        return input + 32;
    }
    return input;
}
//Compares two strings to see if one string is a substring of the other
static int substr_check(Pokedex pokedex, Pokemon pokemon, char *sub) {
    int sub_len = 0;
    for (int i = 0; sub[i] != '\0';i++) {
        sub_len++;
    }
    int j = 0;
    for (int i = 0; pokemon_name(pokemon)[i] != '\0'; i++) {
        int c = manual_tolower(pokemon_name(pokemon)[i]);
        int d = manual_tolower(sub[j]);
        if (c == d) {
            j++;
            if (j == sub_len) return 1;
        } else {
            j = 0;
            d = manual_tolower(sub[j]);
            if (c == d) j++;
            if (j == sub_len) return 1;
        }
    }
    return 0;
}

//Pokedexs created in Stage 5 create new nodes which do not have each pokemon
// set as found, which they are in the original pokedex. This finds all pokemon.
static void find_all_pokemon(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        tmp->found = 1;
        tmp = tmp->next;
    }
}
//Sets the seed, generates a random number, 
// and sets the pokemon with ID to found
static void pokemon_rand_find(Pokedex pokedex, int seed, 
                                int factor, int how_many) {
    srand(seed);
    int id = rand()%factor;
    for (int i = 0;i < how_many;i++) {
        struct pokenode *tmp = pokedex->head;
        while (tmp != NULL) {
            if (tmp->id == id) tmp->found = 1;
            tmp = tmp->next;
        }
        id = rand()%factor;
    }
}
//Checks if all pokemon in the pokedex are not found
// to print an appropriate message
static int check_if_all_pokemon_unfound(Pokedex pokedex) {
    int pokemon_found = 0;
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        if (tmp->found) pokemon_found = 1;
        tmp = tmp->next;
    }
    if (pokemon_found) return 0;
    return 1;
}
