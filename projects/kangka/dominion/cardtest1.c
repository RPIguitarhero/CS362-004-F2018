#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//1st card test tests adventurer;

int main()
{
printf("\n testing card1, adventurer \n" );
struct gameState *g=malloc(sizeof(struct gameState));
int currentPlayer=0,
kingdomCards[10]={adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room},
handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0,
numPlayers=3,
seed=1000;
// initialize a game state and player cards
	initializeGame(numPlayers, kingdomCards, seed, g);


//1st testing scenario will check a very standard card setting and all its following function
//nothing should go wrong in this case
g->whoseTurn=2;
g->deckCount[2]=5;
g->deck[2][0]=smithy;
g->deck[2][1]=smithy;
g->deck[2][2]=copper;
g->deck[2][3]=village;
g->deck[2][4]=silver;

g->discardCount[2]=6;
g->discard[2][0]=village;
g->discard[2][1]=village;
g->discard[2][2]=village;
g->discard[2][3]=village;
g->discard[2][4]=village;
g->discard[2][5]=village;

g->handCount[2]=5;
g->hand[0][0]=smithy;
g->hand[0][1]=smithy;
g->hand[0][2]=smithy;
g->hand[0][3]=smithy;
g->hand[0][4]=smithy;

cardEffect(adventurer, choice1, choice2, choice3, g, handpos, &bonus);
if(g->handCount[2]==6 && g->deckCount[2]==2)
	{
		if(g->discardCount[2]==8)
		{
			printf("1st testing, are card counts correct? Yes \n");
		}
		else{printf("1st testing, are card counts correct? No\n");}
	}
else{printf("1st testing, are card counts correct? No\n");}

//2nd testing scenario will check what happens when there are fewer than 2 treasure cards from deck & discard
//although unlikely to happen in a real game, it is still possible some treausre cards are removed from a player.
g->whoseTurn=1;//reset counter, pointer, array
g->deckCount[1]=3; 
g->deck[1][0]=gold;
g->deck[1][1]=smithy;
g->deck[1][2]=village;

g->discardCount[1]=6;
g->discard[1][0]=village;
g->discard[1][1]=village;
g->discard[1][2]=village;
g->discard[1][3]=village;
g->discard[1][4]=village;
g->discard[1][5]=village;

g->handCount[1]=5;
g->hand[1][0]=smithy;
g->hand[1][1]=smithy;
g->hand[1][2]=smithy;
g->hand[1][3]=smithy;
g->hand[1][4]=smithy;

cardEffect(adventurer, choice1, choice2, choice3, g, handpos, &bonus);
printf("2nd testing, only 1 treasure in deck.\n handCount: %d, original:5,\n deckCount: %d, original:3,\ndiscardCount: %d original:6,\n",g->handCount[1], g->deckCount[1],g->discardCount[1]);
if(g->handCount[2]==6 && g->deckCount[2]==2)
	{
		if(g->discardCount[2]==8)
		{
			printf("2nd testing, are card counts correct? Yes \n");
		}
		else{printf("2nd testing, are card counts correct? No\n");}
	}
else{printf("2nd testing, are card counts correct? No\n");}


//3rd testing scenario will check what happens when the deck is empty
//NOTE:This is supposed to be bugged since in assignment 2 a bug was intentionally introducted to prevent deck checking
g->whoseTurn=0; //reset counter, pointer, array
g->deckCount[0]=1; 
g->deck[0][0]=gold;

g->discardCount[0]=6;
g->discard[0][0]=village;
g->discard[0][1]=village;
g->discard[0][2]=silver;
g->discard[0][3]=village;
g->discard[0][4]=village;
g->discard[0][5]=village;

g->handCount[0]=0;

cardEffect(adventurer, choice1, choice2, choice3, g, handpos, &bonus);
if(g->hand[currentPlayer][1]==silver || g->hand[currentPlayer][1]==gold )
	{
		if(g->hand[currentPlayer][0]==silver || g->hand[currentPlayer][0]==gold)
		{
			printf("3rd testing, are both treasure drawn? Yes \n");
		}
		else{printf("3rd testing, are both treasure drawn? No \n" );}
	}
else printf("3rd testing, are both treasure drawn? No \n " );

free(g);
printf("\n testing card adventurer completed. \n");
}