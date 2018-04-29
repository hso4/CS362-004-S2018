
/* -----------------------------------------------------------------------
 * TEST: callSmithy()
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

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
	
    printf ( "\nTESTING smithy:\n");
    printf ( "##############################################################\n");
 

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
	 printf ("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
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
	
	//Check state changes in victory and kingdom piles
	printf ("\nTEST 4: No state change for victory card and kingdom card piles\n");

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