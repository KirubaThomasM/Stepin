

#include "vote.h"


void votername(VOTER_t *voter_list)
{
	printf("Enter Voter ID:");
	scanf("%s",voter_list->id);
	voter_list->vnv = 0;
	voter_list->cand_choice = 0;
}