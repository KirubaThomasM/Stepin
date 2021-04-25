#ifndef __VOTE_H__
#define __VOTE_H__


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int cand_count, voter_count, voter;
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

#endif