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
#define DOUGLAS              42

#define DIVISIBLE_BY_TWO
// IF YOU NEED MORE #defines ADD THEM HERE

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE

int primeCheck(int number); // Checks if the number input is a prime
int cocoCheck(int numOne, int numTwo);// Checks if two numbers are coco's
void primeFilter(int hand[], int primeArray[]); 
// Filters all primes in the hand to the primeArray array
int douglasPlayed(int cardsPlayedThisRound[]);
// Checks if the Douglas has been played this round
int douglasPassed(int cardsInHistory[]);
// Checks if the Douglas has been played in the history
int primeAllowed(int cardsInHistory[]);
// Checks if any prime has been played before
void readArray(int array[], int len);// Reads streams of numbers into arrays
int greatestPrime(int cardsPlayedThisRound[],int len);
// Checks for the greatest prime played
int greatestCoco(int cardsPlayedThisRound[],int len);
// Checks for the greatest coco played
// Cardplay Functions
void discardFunction();
int playLegalCard(int hand[], int primeArray[],int firstCard);
int handleFirstPlayer(int douglasInHand, int cardsInHistory[], 
                      int hand[], int primeArray[], int firstCard);
int handleDouglasPlayed(int hand[], int primeArray[], int firstCard);
int handleLastPlayer(int hand[], int primeArray[], int firstCard, 
                     int cardsPlayedThisRound[]);
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
    printf("DuelMaster");
}

void choose_discards() {
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    int hand[N_CARDS_INITIAL_HAND] = {0}; // Cards in hand
    readArray(hand,N_CARDS_INITIAL_HAND);
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
    int primeArray[N_CARDS_INITIAL_HAND] = {0}; // Primes in hand
    discardFunction(hand,primeArray);
}

//----------------------------------------------------------------------------
void choose_card_to_play(void) {
    int douglasInHand = 0;
    int cardPlayed = 0;
    int turn = -1;
    turn++;
    int hand[N_CARDS_INITIAL_HAND] = {0}; // Cards in hand
    //int hand[N_CARDS_INITIAL_HAND] = {0}; // Cards in hand
    int primeArray[N_CARDS_INITIAL_HAND] = {0}; // Primes in hand
    int info[3] = {0};
    // Cards in hand, cards played this round, table position
    int cPlayed[3] = {0}; // Cards played this turn
    int cHistory[N_CARDS] = {0}; // Cards played in whole game
    int factorArray[N_CARDS_INITIAL_HAND] = {0};
    //Hand is sorted in order of the number of factors each number has
    
    readArray(info,3); /*info[0] is number of cards in hand, 
    info[1] is number of cards played this round, info[2] table position*/
    for (int i = 0;i < info[0];i++) {
        if(hand[i] == DOUGLAS) {
            douglasInHand = 1;
        } else {
            douglasInHand = 0;
        }
    }
    int cardsPlayedSoFar = (turn)*4 + info[1];
    readArray(hand,info[0]);
    readArray(cPlayed,info[1]);
    readArray(cHistory,cardsPlayedSoFar);
    
    if (info[1] == 0) {
        //First case handles if the player is first
        //printf("First player code entered\n");
        printf("%d\n",handleFirstPlayer(douglasInHand,cHistory,
                                        hand,primeArray,cPlayed[0]));
        cardPlayed = 1;
    } else if(douglasPlayed(cPlayed) && cardPlayed == 0) {
        //Second case handles if the Douglas has been played so far
        printf("%d\n",handleDouglasPlayed(hand, primeArray, cPlayed[0]));
        cardPlayed = 1;
    } else if (info[1] == 3) {
        //Third case handles if the player is last
        printf("%d\n",handleLastPlayer(hand, primeArray,cPlayed[0],cPlayed));
        cardPlayed = 1;
    }
    if (!cardPlayed) {
        /*Last case handles if a normal card has been played requiring 
        cocomposites to be played*/
        //printf("Cocomposite required code entered\n");
        printf("%d\n",playLegalCard(hand,primeArray,cPlayed[0]));
    }
}
//-------------------------------------------------------------------------
// FUNCTIONS BELOW
int primeCheck(int number) {
    for (int k = 2;k < number;k++) {
        if(number % k == 0) {
            return 0;
        }
    }
    return 1;
} // primeCheck checks whether an integer is a prime and returns 1 for true

void primeFilter(int hand[], int primeArray[]) {
    int prev = 0;
    for (int i = 0;i < N_CARDS_INITIAL_HAND;i++) {
        for (int j = 0;j < N_CARDS_INITIAL_HAND;j++) {
            if(primeCheck(hand[j]) && hand[j] > prev) {
                primeArray[i] = hand[j];
                prev = hand[j];
                break;
            }
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
} /*Takes input of two integers, creates an array of all their prime factors 
    and cross checks each prime factor to see if they are cocomposite*/

int douglasPlayed(int cardsPlayedThisRound[]) {
    for (int i = 0;i < 3;i++) {
        if (cardsPlayedThisRound[i] == DOUGLAS) {
            return 1;
        }
    }
    return 0;
} //douglasPlayed checks whether the douglas has been played this round

int douglasPassed(int cardsInHistory[]) {
    for (int i = 0;i < N_CARDS;i++) {
        if (cardsInHistory[i] == DOUGLAS) {
            return 1;
        }
    }
    return 0;
} //douglasPassed checks whether the douglas has been played in previous rounds

int primeAllowed(int cardsInHistory[]) {
    for (int i = 0;i < N_CARDS; i++) {
        if (primeCheck(cardsInHistory[i]) && cardsInHistory[i] != 0) {
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
} //readArray reads in the arrays: info, hand, cPlayed, cHistory

int greatestPrime(int cardsPlayedThisRound[],int len) {
    int num = 0;
    for (int i = 0;i < len; i++) {
        if (num < cardsPlayedThisRound[i] && 
            primeCheck(cardsPlayedThisRound[i])) {
            num = cardsPlayedThisRound[i];
        }
    }
    return num;
} //Checks the cPlayed for the largest Prime card played

int greatestCoco(int cardsPlayedThisRound[],int len) {
    int num = 0;
    for (int i = 0;i < len; i++) {
        if (num < cardsPlayedThisRound[i] && 
            cocoCheck(cardsPlayedThisRound[i],cardsPlayedThisRound[0])) {
            num = cardsPlayedThisRound[i];
        }
    }
    return num;
} //Checks the cPlayed for the largest Coco played

int playLegalCard(int hand[], int primeArray[],int firstCard) {
    if(!primeCheck(firstCard)) {
        for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
            if(cocoCheck(hand[i],firstCard) && hand[i]<firstCard && 
                hand[i]!=DOUGLAS) {
                return hand[i];
            }
        }
        for(int i=0;i<N_CARDS_INITIAL_HAND;i++) {
            if(cocoCheck(hand[i],firstCard) && hand[i] != DOUGLAS) {
                return hand[i];
            }
        }
        for(int i=0;i<N_CARDS_INITIAL_HAND;i++) {
            if(cocoCheck(hand[i],firstCard)) {
                return hand[i];
            }
        }
        for(int i=N_CARDS_INITIAL_HAND-1;i>=0;i--) {
            primeFilter(hand,primeArray);
            if(primeArray[i]!=0) {
                return primeArray[i];
            }
        }
        return hand[0];
    } else if (primeCheck(firstCard)) {
        primeFilter(hand,primeArray);
        for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
            if(primeArray[i]<firstCard && primeArray[i]!=0) {
                return primeArray[i];
            }
        }
        for(int i=0; i<N_CARDS_INITIAL_HAND; i++) {
            if(primeArray[i]!=0) {
                return primeArray[i];
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

int handleFirstPlayer (int douglasInHand, int cardsInHistory[], 
                       int hand[], int primeArray[], int firstCard) {
    primeFilter(hand,primeArray);
    if (primeAllowed(cardsInHistory)) {
        //If the douglas isn't a threat we can rest easy
        for(int i = 0; i < N_CARDS_INITIAL_HAND; i++) {
            if(primeArray[i]!=0) {
                return primeArray[i];
            }
        }
    } else {
        if(douglasInHand || douglasPassed(cardsInHistory)){
            return playLegalCard(hand,primeArray,firstCard);
        } else {
            for(int i=N_CARDS_INITIAL_HAND-1; i>=0; i--) {
                if(!primeCheck(hand[i]) && hand[i]!=0 && hand[i] < DOUGLAS) {
                    return hand[i];
                }
            }
        }
    }
    return playLegalCard(hand,primeArray,firstCard);
}

int handleDouglasPlayed (int hand[], int primeArray[], int firstCard) {
    for (int i = 0;i < N_CARDS_INITIAL_HAND; i++) {
        if (cocoCheck(hand[i],firstCard) && hand[i] != 0) {
            return hand[i];
        }
    }
    return playLegalCard(hand,primeArray,firstCard);
}

int handleLastPlayer (int hand[], int primeArray[], int firstCard, 
                      int cardsPlayedThisRound[]) {
    if (!primeCheck(firstCard)) {
        for (int i = N_CARDS_INITIAL_HAND-1;i >= 0;i--) {
            if (hand[i] < greatestCoco(cardsPlayedThisRound,3) &&
                cocoCheck(hand[i],firstCard)) {
                return hand[i];
            }
        }
    } else {
        primeFilter(hand,primeArray);
        for (int i = N_CARDS_INITIAL_HAND-1;i >= 0;i--) {
            if (primeArray[i] < greatestPrime(cardsPlayedThisRound,3) &&
                primeArray[i] != 0) {
                return primeArray[i];
            }
        }
    }
    return playLegalCard(hand,primeArray,firstCard);
}

void discardFunction(int hand[], int primeArray[]) {
    primeFilter(hand,primeArray);
    int discarded = 0;
    for (int i = N_CARDS_INITIAL_HAND-1; i >=0;i--) {
        if (hand[i] == DOUGLAS) {
            printf("%d\n", hand[i]);
            discarded++;
        }
    }
    for (int i = N_CARDS_INITIAL_HAND-1; i >=0;i--) {
        if (discarded < N_CARDS_DISCARDED && !primeCheck(hand[i]) && 
            hand[i] > DOUGLAS) {
            printf("%d\n", hand[i]);
            discarded++;
        }
    }
    for (int i = N_CARDS_INITIAL_HAND-1; i >=0;i--) {
        if(primeArray[i] > 20 && discarded < N_CARDS_DISCARDED) {
            printf("%d\n", primeArray[i]);
            discarded++;
        }
    }
    for (int i = N_CARDS_INITIAL_HAND-1; i >=0;i--) {
        if (discarded < N_CARDS_DISCARDED && !primeCheck(hand[i]) && 
            hand[i] < DOUGLAS) {
            printf("%d\n", hand[i]);
            discarded++;
        }
    }
    return;
}
