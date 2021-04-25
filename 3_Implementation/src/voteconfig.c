


#include "vote.h"

void voteconfig(int voter)
{
	int i=0, selected;
	printf("%d",(voter_list+voter)->vnv);
	if((voter_list+voter)->vnv == 1)
	{
		printf("\n\t\t\tYou have already voted...");
		return;
	}
	printf("choose the number -> candidate to cast your vote:\n");
	while(i<cand_count)
	{
		printf("%d -> %s \n",i,(cand_list+i)->cand_name);
		i++;
	}
	scanf("%d",&selected);
	(cand_list+selected)->vote_count++;
	(voter_list+voter)->vnv = 1;
	(voter_list+voter)->cand_choice = selected;
	printf("\n\nThanks for your precious vote...");
}