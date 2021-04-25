
#include "vote.h"



void delete_vote()
{
	char voter_id[10] = "\0";
	int i=0, j=0;
	printf("Enter the valid id to remove their vote:");
	scanf("%s",voter_id);
	i=0;
	while(i<voter_count)
	{
		if(strcmp((voter_list+i)->id,voter_id) == 0)
		{
			break;
		}
		i++;
	}
	if((voter_list+i)->vnv != 1)
	{
		printf("Not yet voted");
		return;
	}
	(voter_list+i)->vnv = 0;
	j=((voter_list+i)->cand_choice);
	(cand_list+j)->vote_count--;
	printf("Deletion Successful.....");
}