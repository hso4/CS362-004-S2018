/* -----------------------------------------------------------------------
 * TEST: numHandCards()
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
    int currentHand; 
    int currentP;
    int failed = 0; 
    int seed = 1000;
    int numPlayer = 2;
    srand ( time(NULL) );
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;


                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, k, seed, &G); // initialize a new game
                
                printf ( "TESTING numHandCards():\n");
                printf ( "##############################################################\n");
             
                currentHand =  G.handCount[ whoseTurn(&G) ];
                currentP = whoseTurn(&G) ;
                //Increment and decrement hand semi-randomly and see if the two hands match
                for(i=0;i<100;i++)
                {
                    if(i%3 == 0)
                    {
                    //Remove from hand
                     G.handCount[currentP]--;
                     currentHand--;
                    }
                    else
                    {
                     //Gain hand
                     G.handCount[currentP]++;
                     currentHand++;
                    }

                    //Check for equality
                    if(assertEnd(numHandCards(&G), currentHand))
                    {
                        printf("(Actual) Current cards: %d\n", currentHand);
                        printf("(Returned by function)Current cards: %d\n", numHandCards(&G));
                        printf("\n");
                    }
                    else
                    {
                        printf("(Actual) Current cards: %d\n", currentHand);
                        printf("(Returned by function)Current cards: %d\n", numHandCards(&G));
                        printf("\n");
                        failed = 1; 
                    }
              
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
    //fclose(results);

    return 0;
}