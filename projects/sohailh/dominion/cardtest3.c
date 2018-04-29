
/* -----------------------------------------------------------------------
 * TEST: callSeaHag()
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "sea_hag"

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
    int i;
    int shuffledCards = 0;
    int failed = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int x[3] = {estate, duchy, province};
	const char *strings[] = {"adventurer", "embargo", "village", "minion", "mine", "cutpurse",
			"sea_hag", "tribute", "smithy", "council_room"};
	const char *names[] = {"estate", "duchy", "province"};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
    printf ( "\nTESTING sea_hag:\n");
    printf ( "##############################################################\n");
 

	 printf ("----------------- Testing Card: %s ----------------\n", TESTCARD);


	 printf ("\nTEST 1: Top deck card is discarded\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 0;
	cardEffect(sea_hag, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	
	//Player 0 should lose no cards, other players should lose 1
	printf ("Player 0 deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 0);
	printf ("Player 1 deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - 1);
	  
	
	//Check if deck counts match
	if(!(assertEnd(testG.deckCount[thisPlayer], (G.deckCount[thisPlayer] - newCards + shuffledCards))))
	{
		failed = 1;
	}
	if(!(assertEnd(testG.deckCount[otherPlayer], (G.deckCount[otherPlayer] - 1))))
	{
		failed = 1;
	}

	//All players aside from current should have 1 card in their discard pile
	printf ("\nTEST 2: Check discard amount for each player\n");
	printf ("Player 0 discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	printf ("Player 1 discard count = %d, expected = %d\n", testG.discardCount[otherPlayer], G.discardCount[otherPlayer] +1);
	  
	if(!(assertEnd(testG.discardCount[thisPlayer], (G.discardCount[thisPlayer] +1))))
	{
		failed = 1;
	}


	//Check state changes in victory and kingdom piles
	printf ("\nTEST 3: No state change for victory card and kingdom card piles\n");

	for(i=0;i<10;i++)
	{
	 	printf ("Current supply for card %s = %d, expected  supply= %d\n",strings[i], testG.supplyCount[k[i]], G.supplyCount[k[i]]);
		if(!(assertEnd(testG.supplyCount[k[i]], G.supplyCount[k[i]])))
		{
			failed = 1;
		}
	}

	for(i=0;i<3;i++)
	{
		printf ("Current supply for card %s = %d, expected  supply= %d\n",names[i], testG.supplyCount[x[i]], G.supplyCount[x[i]]);
		if(!(assertEnd(testG.supplyCount[x[i]], G.supplyCount[x[i]])))
		{
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
  

	return 0;
}