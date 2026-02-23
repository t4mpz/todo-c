#pragma once
#include <stdlib.h>
#include <stdio.h>

#define MAX_PATH_SIZE 1024

#define MAX_CHORES 2050
#define MAX_TEXT_SIZE 64

typedef enum Status
{
	Todo,
	Done,
	NALLOC
} Status;

typedef struct Chore
{
	char title[MAX_TEXT_SIZE];
	char description[MAX_TEXT_SIZE];
	Status status;
} Chore;

void writeChores(FILE *choreList, Chore *chores);

int readChores(FILE *choreList, Chore *chores);

void removeChore(Chore *chores, int *lastAlloc, int chore);

void resetChores(Chore *chores, int *lastAlloc);

int lastChore(Chore *chores);

void addChore(Chore *chores, Chore chore, int *lastAlloc);

char *statusToString(Status status);

Status stringToStatus(char *status);

void choreToString(Chore chore, char *output);

void printChore(Chore chore);

void setChorePath(char *path);