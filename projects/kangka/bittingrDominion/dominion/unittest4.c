#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//4th test tests isGameOver(struct gameState *state)
int main()
{
printf("\n testing 4, function isGameOver() \n" );

struct gameState * g=malloc(sizeof(struct gameState));

//set the testing scenario 1, province ran out, trigger 1st winning condition
g->supplyCount[province]=0;
for(int i=0; i<25; i++)
	{
	g->supplyCount[i]=3;
	}

int triggered=isGameOver(g);
printf("is the game ended for scenario 1, expected: 1 actual:%d \n", triggered);
if(triggered==1){printf("passed \n");}else{printf("failed \n" );};

//set the testing scenario 2,  cards other than province ran out, trigger 2nd winning conditon
g->supplyCount[province]=3;
for(int i=0; i<25; i++)
	{
	g->supplyCount[i]=3;
	if(i==2){g->supplyCount[i]=0;}
	if(i==20){g->supplyCount[i]=0;}
	if(i==12){g->supplyCount[i]=0;}
	}

triggered=isGameOver(g);
printf("is the game ended for scenario 2, expected: 1 actual:%d \n", triggered);
if(triggered==1){printf("passed \n");}else{printf("failed \n" );};

//set the testing scenario 3, nothing ran out.
g->supplyCount[province]=5;
for(int i=0; i<25; i++)
	{
	g->supplyCount[i]=3;
	}

triggered=isGameOver(g);
printf("is the game ended for scenario 3, expected: 0 actual:%d \n", triggered);
if(triggered==0){printf("passed \n");}else{printf("failed \n" );};

 //set the testing scenarios 4, we set province stock as -1, 
 //this should trigger a "bug" where game still doesn't end

g->supplyCount[province]=-1;
for(int i=0; i<25; i++)
	{
	g->supplyCount[i]=3;
	}

triggered=isGameOver(g);
printf("is the game ended for scenario 4, expected: 1 actual:%d \n", triggered);
if(triggered==1){printf("passed \n");}else{printf("failed \n" );};


free(g);
printf("testing 4 completed. \n");
return 0;
}