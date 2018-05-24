// VILLAGE CARD
// SMITHY CARD
//ADVENTURER CARD


/* -----------------------------------------------------------------------
 * RANDOM TEST: For callSmithy()
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 *      gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
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


#define TESTCARD "Smithy"

int assertEnd(int a, int b)
{
    if(a == b)
    {
        return 1;
    }
    return 0; 
}

int main() {
    srand(time(NULL));

    int newCards = 0;
    int discarded = 1;
    int i;
    int j;
    int z;
    int shuffledCards = 0;
    int failed = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, testG;
    int k[10];
    const char *strings[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
        "sea_hag", "tribute", "smithy", "council_room"};
    int randNum;
    int repeat = 1;


  //Run random tests 2000
  for(j=0;j < 2000; j++)
  {
  
    //Reset failed
    failed = 0;
    //Set random kingdom cards 
    for(i=0; i < 10; i++)
    {
      repeat = 1;
      while(repeat == 1)
      {
        repeat = 0; 
        randNum = rand() % (9 + 1 - 0) + 0;

        for(z=0;z<10;z++)
        {
          if(k[z] == strings[randNum])
          {
            repeat = 1; 
            break;
          }
        }
      }
      k[i] = strings[randNum]; 
    }
     
    //Randomize total players
    numPlayers = rand() % (4 - 0 + 1) + 0;
    //Randomize seed value
    seed = rand() % (1000 + 1 -1) + 1;

    printf ( "\nTESTING Smithy:\n");
    printf ( "##############################################################\n");
    printf("RANDOM SEED: %d\n", seed);
    printf("RANDOM START HAND COUNT (P1): %d\n", G.handCount[thisPlayer]);
    printf("RANDOM PLAYER AMOUNT: %d\n", numPlayers);
    printf("RANDOM KINGDOM CARDS:\n");
    for(i=0;i<9;i++)
    {
      printf("%s ",k[i] );
    }
    printf("\n");

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
     
   //CHANGE TO RANDOM HAND COUNT
    randNum = rand() % (10 + 1 - 0) + 0;
    G.handCount[thisPlayer] = G.handCount[thisPlayer] + randNum;
    testG.handCount[thisPlayer] = testG.handCount[thisPlayer] + randNum;

     printf ("----------------- Testing Card: %s ----------------\n", TESTCARD);


    // ----------- TEST 1: Check for + 3 cards --------------
     printf ("\nTEST 1: 3 Cards are gained\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    //Smithy will gain 3 cards
    newCards = 3;
      
    //Total cards in hand
    if((testG.handCount[thisPlayer]) != (G.handCount[thisPlayer] + newCards - discarded))
    {
      failed = 1; 
    }
    printf ("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);

    if(failed == 0)
    {
         printf( "Test 1 passed!\n");
    }
    else
    {
         printf( "Test 1 failed!\n");
    }
    failed = 0; 
    
    printf ("\nTEST 2: Cards come from players deck\n");
      //Total cards in deck
    printf ("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
      
    //Check if hand cards match
    if(!(assertEnd(testG.handCount[thisPlayer], (G.handCount[thisPlayer] + newCards - discarded))))
    {
      failed = 1;
    }
    //Check if deck cards match
    if(!(assertEnd(testG.deckCount[thisPlayer], (G.deckCount[thisPlayer] - newCards + shuffledCards))))
    {
      failed = 1;
    }
    if(failed == 0)
      {
      failed = 1;
      }
      else
      {
      failed = 1;
      }
      if(failed == 0)
      {
           printf( "Test 2 passed!\n");
      }
      else
      {
           printf( "Test 2 failed!\n");
      }

      failed = 0; 
    //Check other player's hand and deck
    printf ("\nTEST 3: No state change for other players\n");
     printf ("hand count for other player = %d, expected count for other player= %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
     printf ("deck count for other player = %d, expected count for other player= %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] );
      
    
    if(!(assertEnd(testG.handCount[otherPlayer], (G.handCount[otherPlayer]))))
    {
      failed = 1;
    }
    if(!(assertEnd(testG.deckCount[otherPlayer], (G.deckCount[otherPlayer]))))
    {
      failed = 1;
    }
    if(failed == 0)
      {
           printf( "Test 3 passed!\n");
      }
      else
      {
           printf( "Test 3 failed!\n");
      }
    failed = 0; 
     
      printf ( "##############################################################\n");

      //RESET K
       for(z=0;z<10;z++)
        {
          k[z] = z+10;
       
        }
   }
  return 0;
}
