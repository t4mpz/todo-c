#pragma once
#include <stdlib.h>
#include <stdio.h>

#define MAX_CHORES 2050
#define DEFAULT_CHORES_PATH "~/.config/chores"

typedef enum Status {
	Todo,
	Done,
	NALLOC
} Status;

typedef struct Chore {
	char title[64];
	char description[64];
	Status status;
} Chore;


void 
writeChores (FILE* choreList, Chore* chores);

int
getChores (FILE* choreList, Chore* chores);

void
removeChore (Chore* chores, int chore);

void
reset (Chore* chores);

int
lastChore (Chore* chores);

void
allocChore (Chore* chores, Chore chore, int* lastAlloc);

char*
statusToString (Status status);

void
choreToString (Chore chore, char* output);
