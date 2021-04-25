

#include "vote.h"


void student_panel()
{
	char voter_id[10];
	int i=0;
	printf("\n\n\t\t\tWelcome to Voting System\n");
	printf("Enter your id:");
	again:
	scanf("%s",voter_id);
	i=0;
	while(i<voter_count)
	{
		if(strcmp((voter_list+i)->id,voter_id) == 0)
			break;
		i++;
	}	
		if(i >= voter_count)
		{
			printf("Enter a valid id:");
			goto again;
		}
		else
		{
			voter = i;
			voteconfig(voter);
		}
}