/* -----------------------------------------------------------------------
 * TEST: getCost()
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	int i;
  int failed = 0;
  int cards[28] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost
           		,salvager, sea_hag, treasure_map, 30};
           		//27
  int cardCosts[28] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4,-1};
           
 
    printf ( "\n##############################################################\n");
    printf ( "TESTING getCoins():\n");
 	  printf ( "##############################################################\n");
    int cost;

    //Check that each input returns the correct output
    for(i=0;i<28;i++)
    {
    	cost = getCost(cards[i]);
    	assert(cost == cardCosts[i]);
    	printf("Testing card: %d\n",cards[i] );
    	printf("Returned Cost: %d\n", cost);
    	printf("Expected Cost: %d\n", cardCosts[i]);
    	printf("\n");

    }
   
    if(failed == 0)
    {
    printf("All tests passed!\n");
    }
    else
    {
      printf("Some tests failed!\n");
    }
    printf ( "##############################################################\n");

    return 0;
}