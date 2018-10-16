#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//4th card test tests great_hall

int main()
{
	printf("\n testing card4,great hall \n" );
struct gameState *g=malloc(sizeof(struct gameState));
int kingdomCards[10]={adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room},
handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0,
numPlayers=2,
seed=1000;
// initialize a game state and player cards
	initializeGame(numPlayers, kingdomCards, seed, g);

//first testing, nothing should go wrong here.
g->whoseTurn=0;
g->deckCount[0]=3; 
g->deck[0][0]=gold;
g->deck[0][1]=smithy;
g->deck[0][2]=village;

g->discardCount[0]=6;
g->discard[0][0]=village;
g->discard[0][1]=village;
g->discard[0][2]=village;
g->discard[0][3]=village;
g->discard[0][4]=estate;
g->discard[0][5]=estate;

g->handCount[0]=5;
g->hand[0][0]=smithy;
g->hand[0][1]=smithy;
g->hand[0][2]=smithy;
g->hand[0][3]=smithy;
g->hand[0][4]=smithy;

cardEffect(great_hall, choice1, choice2, choice3, g, handpos, &bonus);
if(g->handCount[0]==5 && g->deckCount[0]==2) //checks cards count in deck, hand, and discard
	{
		if(g->discardCount[0]==7)
		{
			printf("1st testing, are card counts correct? Yes \n");
		}
		else{printf("1st testing, are card counts correct? No\n");}
	}
else{printf("1st testing, are card counts correct? No\n");}

if(g->hand[0][4]==village){("1st testing,is the correct card drawn? Yes \n");}//check if the correct card is drawn
else{printf("1st testing, is the correct card drawn? No\n");}

if(g->numActions==1){("1st testing,is action correctly recalculated? Yes \n" );}//check if the action number is correctly added
else{printf("1st testing, is action correctly recalculated? No\n" );}

if(scoreFor(0,g)==3){("1st testing,is victory point correctly recalculated? Yes \n");}//check if the victory point is correctly calculated
else{printf("1st testing, is victory point correctly recalculated? No\n" );}

printf("\n testing card great hall completed. \n" );
free(g);
return 0;
}