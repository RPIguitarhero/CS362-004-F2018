#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1st test tests fullDeckCount(int player, int card, struct gameState *state)
int main()
{
printf("\n testing 1, function fullDeckCount() \n" );

struct gameState * g=malloc(sizeof(struct gameState));

//set the testing hand/deck/dis cards
g->handCount[0]=4;
g->hand[0][0]=village;
g->hand[0][1]=village;
g->hand[0][2]=village;
g->hand[0][3]=copper;

g->deckCount[0]=7;
g->deck[0][0]=village;
g->deck[0][1]=village;
g->deck[0][2]=copper;
g->deck[0][3]=copper;
g->deck[0][4]=copper;
g->deck[0][5]=copper;
g->deck[0][6]=copper;	

g->discardCount[0]=2;
g->discard[0][0]=curse;
g->discard[0][1]=curse;

//count the cards, test the funtion
int count=0;
count=fullDeckCount(0,village,g);
printf("card village count, expected:5 actual:%d \n", count);
if(count==5){printf("passed \n");}else{printf("failed \n" );};

count=fullDeckCount(0,copper,g);
printf("card copper count, expected:6 actual:%d \n", count);
if(count==6){printf("passed \n");}else{printf("failed \n" );};

count=fullDeckCount(0,curse,g);
printf("card curse count, expected:2 actual:%d \n", count);
if(count==2){printf("passed \n");}else{printf("failed \n" );};

free(g);
printf("\n testing 1 completed. \n");
return 0;
}