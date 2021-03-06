// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by Aniket Chavan (z5265106)
// on 24/03/19

#include <stdio.h>
#include <assert.h>

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

// IF YOU NEED MORE #defines ADD THEM HERE

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);

//Arrays below

int hand[N_CARDS_INITIAL_HAND] = {0}; //Cards in hand
int prime_array[N_CARDS_INITIAL_HAND] = {0}; //Primes in hand
int info[3] = {0};
int c_played[3] = {0}; //Cards played this turn
int c_history[N_CARDS] = {0}; //Cards played in whole game

int douglasInHand = 0;
int card_played = 0;
int turn = -1;

int primeCheck(int number);

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE

int primeCheck(int number) {
    for (int k=2;k < number;k++) {
        if(number%k == 0) {
            return 1;
        }
    }
    return 0;
} // primeCheck checks whether an integer is a prime and returns 1 for true

void primeArray(int hand[N_CARDS_INITIAL_HAND]) {
    
    int factorFound = 0;
    int j = 0;
    for(int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        prime_array[i] = 0;
    }
    
    for (int i=0;i < N_CARDS_INITIAL_HAND;i++) {
        factorFound = 0;
        if (prime_array[j] == 0) {
            for (int k=2;k < hand[i];k++) {
                if(hand[i]%k == 0) {
                    factorFound = 1;
                }
            }
            if (!factorFound && prime_array[j] == 0) {
                prime_array[j] = hand[i];
            }
        } else {
            j++;
        }
    }
}

int cocoCheck(int numOne, int numTwo) {
    for (int i = 2; i < numOne && i < numTwo;i++) {
        if((i != numOne && i != numTwo) && (numOne%i == 0 && numTwo%i == 0)) {
            return 1;
        }
    }
    return 0;
} //Takes input of two integers, creates an array of all their prime factors and cross checks each prime factor to see if they are cocomposite

int douglas_played() {
    for (int i = 0;i < 3;i++) {
        if (c_played[i] == 42) {
            return 1;
        }
    }
    return 0;
} //douglas_played checks whether the douglas has been played this round

int douglas_passed() {
    for (int i = 0;i < N_CARDS;i++) {
        if (c_history[i] == 42) {
            return 1;
        }
    }
    return 0;
} //douglas_passed checks whether the douglas has been played in previous rounds

int primeAllowed() {
    for (int i = 0;i < N_CARDS; i++) {
        if (primeCheck(c_history[i]) && c_history[i] != 0) {
            return 1;
        }
    }
    return 0;
} //primeAllowed checks whether primes have been played before

void readArray(int array[], int len) {
    for (int i = 0;i < len;i++) {
        scanf("%d", &array[i]);
    }
    return;
} //readArray reads in the arrays: info, hand, c_played, c_history

int greatest_card(int array[]) {
    int num = 0;
    for (int i = 0;i<3; i++) {
        if (num<array[i]) {
            num = array[i];
        }
    }
    return num;
} //Checks the c_played for the largest card played

int cocompositeNoDouglas(int c_played[], int prime_array[], int card) {
    if (cocoCheck(card, c_played[0]) && card != 42) {
        return card;
    }
    return -1;
    // lookup ternary if you care, I wouldn't though
}

int forEachCard(int c_played[], int prime_array[], int hand[],
                int(*forEach)(int c_played[], int prime_array[], int card)) {
    for (int i = 0; i < N_CARDS_INITIAL_HAND; i++) {
        int c = forEach(c_played, prime_array, hand[i]);
        if (c != -1) {
            return c;
        }
    }
    return -1;
}

int play_legal_card() {
    if(!primeCheck(c_played[0])) {
        for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
            if(cocoCheck(hand[i],c_played[0]) && hand[i]<c_played[0] && 
                hand[i]!=42) {
                return hand[i];
            }
        }
        /*for(int i=0;i<N_CARDS_INITIAL_HAND;i++) {
            if(cocoCheck(hand[i],c_played[0]) && hand[i] != 42) {
                return hand[i];
            }
        }*/ 
        
        int c = forEachCard(c_played, prime_array, hand, &cocompositeNoDouglas);
        if (c != -1) {
            return c;
        } 
        for(int i=0;i<N_CARDS_INITIAL_HAND;i++) {
            if(cocoCheck(hand[i],c_played[0])) {
                return hand[i];
            }
        }
        for(int i=N_CARDS_INITIAL_HAND-1;i>=0;i--) {
            primeArray(hand);
            if(prime_array[i]!=0) {
                return prime_array[i];
            }
        }
    } else if (primeCheck(c_played[0])) {
        primeArray(hand);
        for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
            if(prime_array[i]<c_played[0] && prime_array[i]!=0) {
                return prime_array[i];
            }
        }
        for(int i=0; i<N_CARDS_INITIAL_HAND; i++) {
            if(prime_array[i]!=0) {
                return prime_array[i];
            }
        }
        for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
            if(hand[i]!=0) {
                return hand[i];
            }
        }
    }
    // I should never get here
    assert(0);
}


// You should not need to change this main function
//----------------------------------------------------------------------------
int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}
//----------------------------------------------------------------------------
void print_player_name(void) {
    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME
    printf("Xx_Duel~Master_xX");
}

void choose_discards() {
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    for(int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        scanf("%d", &hand[i]);
    }
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
    primeArray(hand);
    int primeNum = 0;
    int discarded = 0;
    for (int i = 0;i<N_CARDS_INITIAL_HAND;i++) {
        if(prime_array[i] !=0) {
            primeNum++;
        }
        if(prime_array[i] > 20) {
            printf("%d ", prime_array[i]);
            discarded++;
        }
    }
    for (int i = N_CARDS_INITIAL_HAND-1; i >=0;i--) {
        if (discarded < 3 && hand[i] != 42 && !primeCheck(hand[i])) {
            printf("%d", hand[i]);
            discarded++;
        }
    }
}

// LINE 300: make sure they sync
void playCard...(int hand[], int c_played[]) {
    //Second case handles if the douglas has been played this round
    //printf("Douglas has been played code entered\n");
    for (int i = 0;i < N_CARDS_INITIAL_HAND; i++) {
        if (cocoCheck(hand[i],c_played[0]) && hand[i] != 0) {
            printf("%d\n",hand[i]);
            return;
        }
    }
    printf("%d\n",hand[0]);
}

//----------------------------------------------------------------------------
void choose_card_to_play(void) {
    turn++;
    readArray(info,3);
    for (int i = 0;i < info[0];i++) {
        if(hand[i] == 42) {
            douglasInHand = 1;
        } else {
            douglasInHand = 0;
        }
    }
    readArray(hand,info[0]);
    readArray(c_played,info[1]);
    readArray(c_history,N_CARDS);
    
    if (info[1] == 0) {
        //First case handles if the player is first
        //printf("First player code entered\n");
        if ((douglasInHand || douglas_passed()) && primeAllowed()) { 
        //This checks if the douglas is a threat or not
            card_played = 0;
            for (int i = N_CARDS_INITIAL_HAND - 1;i >= 0; i--) {
                if (!primeCheck(hand[i]) && hand[i] != 0 && hand[i] != 42) {
                    printf("%d\n",hand[i]);
                    card_played = 1;
                    break;
                }
            }
        } else if (card_played==0) { //If the douglas is a threat, we need to avoid it
            card_played = 0;
            for (int i = N_CARDS_INITIAL_HAND - 1;i >= 0; i--) {
                if (!primeCheck(hand[i]) && hand[i]!=0 && hand[i]<42) {
                    printf("%d\n",hand[i]);
                    card_played = 1;
                    break;
                }
            }
        }
        if (card_played == 0) {
            printf("%d",play_legal_card());
        }
    } else if(douglas_played() && card_played == 0) {
        playCardDouglasHasBeenPlayed(hand, c_played);
    //} else if(info[1]==3 && card_played == 0) {
        //Third case handles if we are the last player

    } else if(primeCheck(c_played[0]) && card_played==0) {
        //Fourth case handles whether a prime was played as the first card
        //printf("Prime card code entered\n");
        primeArray(hand);
        for (int i = 0;i < N_CARDS_INITIAL_HAND; i++) {
            primeArray(hand);
            if(prime_array[i] == 0) {
                printf("%d\n", hand[i]);
                break;
            } else {
                printf("%d\n",prime_array[i]);
                break;
            }
        }
    } else {
        //Last case handles if a normal card has been played requiring cocomposites to be played
        //printf("Cocomposite required code entered\n");
        printf("%d",play_legal_card());
    }
}
// ADD YOUR FUNCTIONS HERE
