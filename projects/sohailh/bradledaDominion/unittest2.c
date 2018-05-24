/* -----------------------------------------------------------------------
 * TEST: isGameOver()
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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

int assertEnd(int endGame, int comp)
{
    if(endGame == comp)
    {
        return 1;
    }
    return 0; 
}


int main() {
    int i;
    int j;
    int x;
    int n;
    int failed = 0;
    int randInt[3];
    int seed = 1000;
    int numPlayer = 2;
    int maxProvince = 8;
    srand ( time(NULL) );
    
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;


                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, k, seed, &G); // initialize a new game
                
                printf ( "TESTING isGameOver():\n");
                printf ( "##############################################################\n");
                //Check that game doesn't end while province cards remain
                for(i=maxProvince; i>=0; i--)
                {
                    G.supplyCount[province] = i;
                    if(i!=0)
                    {
                        assert(isGameOver(&G) == 0);
                        printf("Province card(s) left: %d\n", i);
                         printf("Expected: Is the game over?: %s\n", "No.");
                        printf("Returned: Is the game over?: %s\n", "No.");
                        printf("\n");
                    }

                    else
                    {
                        assert(isGameOver(&G) == 1);
                        printf("Province(s) left: %d\n", i);
                         printf("Expected: Is the game over?: %s\n", "Yes.");
                        printf("Returned: Is the game over?: %s\n", "Yes.");
                        printf("\n");
                    }
                    
                }
            G.supplyCount[province] = maxProvince;

            //First check control for all piles full
            j=0; 
            for (i = 0; i < 25; i++)
            {
                  if (G.supplyCount[i] == 0)
                {
                  j++;
                }
            }
            if ( j < 3)
            {
                 assert(isGameOver(&G) == 0);
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "No.");
                 printf("Returned: Is the game over?: %s\n", "No.");
                 printf("\n");
            }
            else
            {
                assert(isGameOver(&G) == 1);
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "Yes.");
                 printf("Returned: Is the game over?: %s\n", "Yes.");
                 printf("\n");
            }
            
          //Set 3 random piles to 0 and check for game over
          for (n=0;n<25;n++)
          {
            
            for(x=0;x<3;x++)
            {
                 randInt[x] = rand() % (25 + 1 - 0) + 0;
                 G.supplyCount[randInt[x]] = 0;
            }

            for (i = 0; i < 25; i++)
            {
                    if (G.supplyCount[i] == 0)
                    {
                        j++;
                    }
            }
            
            if ( j < 3)
            {

                 if(assertEnd(isGameOver(&G), 0))
                {
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "No.");
                 printf("Returned: Is the game over?: %s\n", "No.");
                 printf("\n");
                }
                else
                {
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "No.");
                 printf("Returned: Is the game over?: %s\n", "Yes.");
                 printf("\n");
                 failed = 1;
                }
            }
            else
            {
                if(assertEnd(isGameOver(&G), 1))
                {
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "Yes.");
                 printf("Returned: Is the game over?: %s\n", "Yes.");
                 printf("\n");
                }
                else
                {
                 printf("Number of supply piles that = 0?: %d\n", j);
                 printf("Expected: Is the game over?: %s\n", "Yes.");
                 printf("Returned: Is the game over?: %s\n", "No.");
                 printf("\n");
                 failed = 1;
                }
            }
            
            //Reset supply counts
            for(x=0;x<3;x++)
            {
                 G.supplyCount[randInt[x]] = 10;
            }
            j = 0;
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