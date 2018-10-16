#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//3rd test tests scoreFor (int player, struct gameState *state)
int main()
{
printf("\n testing 3, function scoreFor() \n" );

struct gameState * g=malloc(sizeof(struct gameState));

//set the testing hand/deck/dis cards for player 1, 8 points
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
g->deck[0][5]=province;
g->deck[0][6]=copper;	

g->discardCount[0]=2;
g->discard[0][0]=estate;
g->discard[0][1]=estate;

//set the testing hand/deck/dis cards for player 2, he has 2 cures cards, 11 points
g->handCount[1]=7;
g->hand[1][0]=estate;
g->hand[1][1]=province;
g->hand[1][2]=smithy;
g->hand[1][3]=feast;
g->hand[1][4]=silver;
g->hand[1][5]=copper;
g->hand[1][6]=feast;

g->deckCount[1]=3;
g->deck[1][0]=gold;
g->deck[1][1]=gold;
g->deck[1][2]=gold;

g->discardCount[1]=5;
g->discard[1][0]=curse;
g->discard[1][1]=curse;
g->discard[1][2]=smithy;
g->discard[1][3]=duchy;
g->discard[1][4]=duchy;


//set the testing hand/deck/dis cards for player 3, he has 11 cures cards, -5 points
g->handCount[2]=7;
g->hand[2][0]=curse;
g->hand[2][1]=curse;
g->hand[2][2]=curse;
g->hand[2][3]=curse;
g->hand[2][4]=curse;
g->hand[2][5]=curse;
g->hand[2][6]=curse;

g->deckCount[2]=3;
g->deck[2][0]=curse;
g->deck[2][1]=curse;
g->deck[2][2]=gold;

g->discardCount[2]=5;
g->discard[2][0]=curse;
g->discard[2][1]=curse;
g->discard[2][2]=smithy;
g->discard[2][3]=duchy;
g->discard[2][4]=duchy;



//calculate the scores for players, test the funtion
int score=scoreFor(0,g);
printf("Score for player 1, expected: 8 actual:%d \n",score);
if(score==8){printf("passed \n");}else{printf("failed \n" );};

score=scoreFor(1,g);
printf("Score for player 2, expected: 11 actual:%d \n",score);
if(score==11){printf("passed \n");}else{printf("failed \n" );};

score=scoreFor(2,g);
printf("Score for player 3, expected: -5 actual:%d \n",score);
if(score==-5){printf("passed \n");}else{printf("failed \n" );};

free(g);
printf("\n testing 3 completed. \n");
return 0;
}