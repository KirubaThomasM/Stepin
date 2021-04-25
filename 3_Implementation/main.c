
#include "vote.h"
int main()
{
	char n = '3';
	//clrscr();
	while(1)
	{
		//clrscr();
		printf("\n\n\t\t\tWelcome to Voting System\n");
		printf("\n\t\t\t   1.Student panel \n\t\t\t   2.Admin panel \n\t\t\t   3.Exit \n\t\t\t   Option:");
		scanf(" %c",&n);
		if(n=='1')
			student_panel();
		else
		{	if(n=='2')
				admin_panel();
			else
			{
				if(n=='3')
				{
					free(voter_list);
					free(cand_list);
					return 0;
				}
				else
				{
					printf("\nInvalid option");
					continue;
				}
			}
		}
	}
	free(voter_list);
	free(cand_list);
	return 0;
}
