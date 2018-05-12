/* -----------------------------------------------------------------------
 * RANDOM TEST: For callAdventurer()
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int assertEnd(int a, int b)
{
    if(a == b)
    {
        return 1;
    }
    return 0; 
}


int main() {
    int newCards = 0;
    int discarded = 1;
    int i;
    int j;
    int z;
    int xtraCoins = 0;
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
for(j=0;j<2000;j++)
{
  for(i=0; i < 10; i++)
  {
    repeat = 1;
     //Set random kingdom cards 
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
 	printf ( "TESTING adventurer:\n");
    printf ( "##############################################################\n");
    //Randomize total players
    numPlayers = rand() % (4 - 0 + 1) + 0;
  //Randomize seed value
   seed = rand() % (1000 + 1 -1) + 1;
	// initialize a game state and player cards
   initializeGame(numPlayers, k, seed, &G);
   memcpy(&testG, &G, sizeof(struct gameState));

   	  //CHANGE TO RANDOM HAND COUNT
   randNum = rand() % (10 + 1 - 0) + 0;
   G.handCount[thisPlayer] = G.handCount[thisPlayer] + randNum;
   testG.handCount[thisPlayer] = testG.handCount[thisPlayer] + randNum;

   	  //CHANGE TO RANDOM DECK COUNT
    randNum = rand() % (15 + 1 - 0) + 0;
    G.deckCount[thisPlayer] = G.deckCount[thisPlayer] + randNum;
   testG.deckCount[thisPlayer] = testG.deckCount[thisPlayer] + randNum;

   // CHANGE TO RANDOM HAND COUNT FOR OTHER PLAYER
   randNum = rand() % (10 + 1 - 0) + 0;
   G.handCount[otherPlayer] = G.handCount[otherPlayer] + randNum;
   testG.handCount[otherPlayer] = testG.handCount[otherPlayer] + randNum;


   // RANDOM START ACTIONS
    randNum = rand() % (5 + 1 - 0) + 0;
    G.numActions = G.numActions + randNum;
   testG.numActions = testG.numActions + randNum;

    randNum = rand() % (5 + 1 - 0) + 0;
    testG.discardCount[thisPlayer] = testG.discardCount[thisPlayer] + randNum;
    G.discardCount[thisPlayer] = G.discardCount[thisPlayer] + randNum;
 
   printf("RANDOM SEED: %d\n", seed);
  printf("RANDOM PLAYER AMOUNT: %d\n", numPlayers);
  printf("RANDOM START HAND COUNT (P1): %d\n", G.handCount[thisPlayer]);
  printf("RANDOM START DECK COUNT  (P1): %d\n", G.deckCount[thisPlayer]);
  printf("RANDOM START HAND COUNT (P2): %d\n", G.handCount[otherPlayer]);
  printf("RANDOM START DECK COUNT  (P2): %d\n", G.deckCount[otherPlayer]);
  printf("RANDOM TOTAL START ACTIONS (P1): %d\n", G.numActions);
  printf("RANDOM START DISCARDED (P1): %d\n", G.discardCount[thisPlayer]);

  printf("RANDOM KINGDOM CARDS:\n");


  for(i=0;i<9;i++)
  {
    printf("%s ",k[i] );
  }
  printf("\n");
	 printf ("----------------- Testing Card: %s ----------------\n", TESTCARD);


	 printf ("\nTEST 1: 2 Cards are gained\n");

	// copy the game state to a test case
	choice1 = 0;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	//adventurer will gain 2 cards
	newCards = 2;
	xtraCoins = 2;
	
	//Total cards in hand
	printf ("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	//Check if hand cards match
  if(!(assertEnd(testG.handCount[thisPlayer], (G.handCount[thisPlayer] + newCards - discarded))))
  {
    failed = 1;
  }
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
	  

	//Check if deck cards match
	if(!(assertEnd(testG.deckCount[thisPlayer], (G.deckCount[thisPlayer] - newCards + shuffledCards))))
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



	//Check discard amounts of each player
	printf ("\nTEST 4: Check discard amount for each player\n");
	printf ("Player 0 discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	printf ("Player 1 discard count = %d, expected = %d\n", testG.discardCount[otherPlayer], G.discardCount[otherPlayer]);
	  
	
	
	if(!(assertEnd(testG.discardCount[thisPlayer], (G.discardCount[thisPlayer] + discarded))))
	{
		failed = 1;
	}

    if(failed == 0)
    {
         printf( "Test 4 passed!\n");
    }
    else
    {
         printf( "Test 4 failed!\n");
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