

#include "vote.h"


void admin_panel()
{
	char admin_login[15],admin_password[15], ch;
	char str1[]="Admin";
	char str2[]="stepin";
	int i=0,j=0, win=0, max =0;
	float total=0;

	while(1)
	{
		//clrscr();
		printf("\nEnter adminname: ");
		scanf("%s",admin_login);
		if((strcmp(admin_login,str1))!= 0)
		{
			printf("Wrong adminname(press any key)");
			getch();
			continue;
		}
		else
		{   password:    
			printf("Enter Password (length = 7): ");
			scanf("%s",admin_password);
			if((strcmp(admin_password,str2)) != 0)
			{
				printf("\nWrong Password(press any key)\n");
				getch();
				goto password;
			}
			else
			{
			    printf("\n\nADMIN LOGIN SUCCESSFULL(Press Enter)");
			    getch();
			    while(1)
			    {
				    //clrscr();
				    printf("\n1.New Election\n2.Delete Illegal Vote\n3.Result\n4.Logout\nOption:");
				    scanf(" %c",&ch);
				    switch(ch)
				    {
					    //TO TAKE NEW ELECTION
				        case '1':
					    //clrscr();
						free(voter_list);
						free(cand_list);
					    printf("\nNew Election Initiation:\n");
					    printf("Enter the no. of candidates:");
					    scanf("%d",&cand_count);
					    cand_list =(CAND_t *)malloc(cand_count*sizeof(CAND_t));
				        i=0;
				        while(i<cand_count)
				        {
						    candname((cand_list+i));
						    i++;
					    }
					    printf("Enter the no. of voters:");
					    scanf("%d",&voter_count);
					    voter_list =(VOTER_t *)malloc(voter_count*sizeof(VOTER_t));
				        i=0;
				        while(i<voter_count)
				        {
						    votername((voter_list+i));
						    i++;
					    }
						break;
					    //TO DELETE VOTE FOR SELECTED PRN
					    case '2':
					    delete_vote();
				    	break;
					    //TO DISPLAY RESULT
					    case '3':
					    //clrscr();
					    i=0;win=0;
					    max = (cand_list+i)->vote_count;
					    while(i<cand_count)
					    {
						    if((cand_list+i)->vote_count>max)
						    {
							    max=(cand_list+i)->vote_count;
							    win = i;
                            }
						    i++;
					    }
					    i=0;j=0;
					    for(i=0;i<cand_count;i++)
					    {
						    if(max==(cand_list+i)->vote_count)
						    j++;
					    }
					    if(j>1)
				    	{
					    	printf("\n\n\n\t\tELECTION TIED");
					    }	
					    else
					    {
						    printf("\n\n\n\t\t__________________________________________________");
						    printf("\n\n\t\t      WINNER is %s with %d votes",(cand_list+win)->cand_name,(cand_list+win)->vote_count);
						    printf("\n\t\t__________________________________________________");
					    }
					    i=0;total=0;
					    for(i=0;i<cand_count;i++)
						{
						    total += ((cand_list+i)->vote_count);
							//printf("%d",total);
						}
					    printf("\n\n\n\t\t\t   Election statistics:\n");
					    i=0;
					    while(i<cand_count)
					    {
						    printf("\n\t\t\tVotes for %s= %d",(cand_list+i)->cand_name,(cand_list+i)->vote_count);
						    i++;
					    }
					    printf("\n\n\t\t\tVoting Percentage:%0.2f %% ",(total/voter_count)*100);
					    getch();
					    break;

					    case '4':
					    return;

					    default:
					    printf("Invalid Option");
					    getch();
                    }
				}
			}
		}
	}
}