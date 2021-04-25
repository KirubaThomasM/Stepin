

#include "vote.h"


void candname(CAND_t *cand_list)
{
	printf("Enter Candidate name:");
	scanf("%s",cand_list->cand_name);
	//puts(cand_list->cand_name);
	cand_list->vote_count=0;
}