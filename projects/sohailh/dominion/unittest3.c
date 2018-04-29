/* -----------------------------------------------------------------------
 * TEST: whoseTurn()
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int assertEnd(int a, int b)
{
    if(a == b)
    {
        return 1;
    }
    return 0; 
}


int main() {
    int i;
    int temp;
    int current;
    int last; 
    int failed = 0;
    int seed = 1000;
    int numPlayer = 2;
    srand ( time(NULL) );
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;


    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    printf ( "TESTING whoseTurn():\n");
    printf ( "##############################################################\n");
    

    current = whoseTurn(&G);
    last = 1; 
    //Alternate turns and see if the function returns the proper value
    for (i=0; i<10; i++)
    {
        temp = whoseTurn(&G);
        if(assertEnd(temp, current))
        {
            //Print true and pass
            printf("Current turn: %d\n", current);
            printf("Expected current turn: %d\n", current);
            printf("Actual current turn: %d\n", temp);
            printf("\n");
        }
        else
        {
             printf("Current turn: %d\n", current);
            printf("Expected current turn: %d\n", current);
            printf("Actual current turn: %d\n", temp);
            printf("\n");
            failed = 1;
            //Print false and fail
        }

        //Swap turns
        G.whoseTurn = last;
        temp = last;
        last = current;
        current = temp; 
    }
    


    if(failed == 0)
    {
         printf( "All tests passed!\n");
    }
    else
    {
         printf( "Some failed tests!\n");
    }
   
    printf ( "##############################################################\n");
    
    return 0;
}