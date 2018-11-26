#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2nd card test tests smithy

int main()
{
	printf("\n testing card2, smithy \n" );
struct gameState *g=malloc(sizeof(struct gameState));
int kingdomCards[10]={adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room},
handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0,
numPlayers=2,
seed=1000;
// initialize a game state and player cards
	initializeGame(numPlayers, kingdomCards, seed, g);

//testing case 1, a standard test.
//nothing should go wrong here, even with the introduced bug.
g->whoseTurn=0;
g->deckCount[0]=16; 
g->deck[0][0]=gold;
g->deck[0][1]=smithy;
g->deck[0][2]=village;
g->deck[0][3]=gold;
g->deck[0][4]=smithy;
g->deck[0][5]=village;
g->deck[0][6]=gold;
g->deck[0][7]=smithy;
g->deck[0][8]=village;
g->deck[0][9]=gold;
g->deck[0][10]=smithy;
g->deck[0][11]=village;
g->deck[0][12]=gold;
g->deck[0][13]=smithy;
g->deck[0][14]=village;
g->deck[0][15]=village;

g->discardCount[1]=6;
g->discard[0][0]=village;
g->discard[0][1]=village;
g->discard[0][2]=village;
g->discard[0][3]=village;
g->discard[0][4]=village;
g->discard[0][5]=village;

g->handCount[0]=5;
g->hand[0][0]=smithy;
g->hand[0][1]=smithy;
g->hand[0][2]=smithy;
g->hand[0][3]=smithy;
g->hand[0][4]=smithy;

//
cardEffect(smithy, choice1, choice2, choice3, g, handpos, &bonus);
if(g->handCount[0]==19 && g->deckCount[0]==1) //checks cards count in deck, hand, and discard
	{
		if(g->discardCount[0]==8)
		{
			printf("1st testing, are card counts correct? Yes \n");
		}
		else{printf("1st testing, are card counts correct? No\n");}
	}
else{printf("1st testing, are card counts correct? No\n");}

int correctAddCards=0;
for(int i=0;i<g->handCount[0];i++)
	{	
		if(g->hand[0][i]==gold){correctAddCards++;}
		if(g->hand[0][i]==smithy){correctAddCards++;}
		if(g->hand[0][i]==village){correctAddCards++;}
	}
if(correctAddCards==15){printf("1st testing, are cards added from the correct pile? Yes \n" );}
else{printf("1st testing, are cards added from the correct pile? No\n" );}


//testing case 2, the deck only has 3 cards in deck, 6 cards in discard
//a bug was introduced where it draws 15 cards instead of 3 

g->whoseTurn=1;
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
cardEffect(smithy, choice1, choice2, choice3, g, handpos, &bonus);
if(g->handCount[0]==13 && g->deckCount[0]==0) //checks cards count in deck, hand, and discard
	{
		if(g->discardCount[0]==1)
		{
			printf("1st testing, are card counts correct? Yes \n");
		}
		else{printf("1st testing, are card counts correct? No\n");}
	}
else{printf("1st testing, are card counts correct? No\n");}

correctAddCards=0;
for(int i=0;i<g->handCount[0];i++)
	{	
		if(g->hand[0][i]==gold){correctAddCards++;}
		if(g->hand[0][i]==smithy){correctAddCards++;}
		if(g->hand[0][i]==village){correctAddCards++;}
	}
if(correctAddCards==9){printf("2nd testing, are cards added from the correct pile? Yes \n" );}
else{printf("2nd testing, are cards added from the correct pile? No\n" );}

printf("\n testing card smithy completed. \n" );
free(g);
return 0;
}