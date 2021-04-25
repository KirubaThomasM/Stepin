/*
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int cand_count, voter_count, max = 0, voter;
//Structure that holds candidate name and count of vote
typedef struct candidate
{
	char cand_name[20];
	int vote_count;
}CAND_t;
CAND_t *cand_list;

typedef struct voters
{
	char id[10];
	int vnv;
	int cand_choice;
}VOTER_t;
VOTER_t *voter_list;


void student_panel();
void admin_panel();
void candname(CAND_t *cand_list);
void votername(VOTER_t *voter_list);
void voteconfig(int voter);
void delete_vote();
//fn to store names of candidates standing for election

void candname(CAND_t *cand_list)
{
	printf("Enter Candidate name:");
	scanf("%s",cand_list->cand_name);
	//puts(cand_list->cand_name);
	cand_list->vote_count=0;
}

void votername(VOTER_t *voter_list)
{
	printf("Enter Voter ID:");
	scanf("%s",voter_list->id);
	voter_list->vnv=0;
}

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

void delete_vote()
{
	char voter_id[10];
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
	(voter_list+i)->vnv = 0;
	j=((voter_list+i)->cand_choice);
	(cand_list+j)->vote_count--;
	printf("Deletion Successful.....");
}
//Admin Panel
void admin_panel()
{
	char admin_login[15],admin_password[15], ch, sp;
	char str1[]="Admin";
	char str2[]="stepin";
	int i=0,j=0, win=0;
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

void student_panel()
{
	char voter_id[10];
	int i=0,j=0;
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
*/
#include "vote.h"
int main()
{
	char n;
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
	return 0;
}
