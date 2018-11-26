#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1st test tests whoseTurn(struct gameState *state)
int main()
{
printf("\n testing 2, function whoseTurn() \n" );

struct gameState * g=malloc(sizeof(struct gameState));
g->whoseTurn=0;

//identify the player, test the funtion
for(int i=0; i<11;i++)//technically only 10 players are allowed
	{
	g->whoseTurn=i;
	int count=whoseTurn(g);
	printf("whose turn now? expected:player %d actual:plater %d \n",i,count);
	if(count==i){printf("passed \n");}else{printf("failed \n" );};
	}	
free(g);
printf("\n testing 2 completed. \n");
return 0;
}