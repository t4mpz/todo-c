#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todolib.h"



void 
writeChores(FILE* choreList, Chore* chores) {
	printf("%ld / %ld \n", sizeof(chores), sizeof(Chore));
	size_t result = fwrite(chores, sizeof(Chore), MAX_CHORES, choreList);
	printf("%ld\n", result);
	return;
}

int
getChores (FILE* choreList, Chore* chores) {
	reset(chores);
	fread(chores, sizeof(Chore), MAX_CHORES, choreList);
	printf("last nalloc status b4 reading %s\n", statusToString(chores[0].status));
	return lastChore(chores);
}

void 
removeChore(Chore* chores, int chore) {
	if (chore >= MAX_CHORES-1) {
		chores[chore].status = NALLOC;
		return;
	}
	Chore* next = &chores[chore+1], *current = &chores[chore];
	while (next->status != NALLOC) {
		strcpy(current->title, next->title);
		strcpy(current->description, next->description);
		current->status = next->status;
		current++;
		next++;
	}
	strcpy(current->title, "\0");
	strcpy(current->description, "\0");
	current->status = NALLOC;
	return;
}

void
reset(Chore* chores) {
	int counter = 0;
	for(Chore* chore = chores; counter < MAX_CHORES; chore++){
		strcpy(chore->title, "\0");
		strcpy(chore->description, "\0");
		chore->status = NALLOC;
		counter++;
	}
	return;
}

int
lastChore (Chore* chores) {
	int counter = 0;
	for(Chore* chore = chores; counter < MAX_CHORES && chore->status != NALLOC; ++chore) {
		char str[1024];
		choreToString(*chore, str);
		printf("bomboclat %s\n", str);
		++counter;
	}
	return counter;
}

void
allocChore (Chore* chores, Chore chore, int* lastAlloc) {
	printf("last alloc %d\n", *lastAlloc);
	if (*lastAlloc >= MAX_CHORES) {
		printf("MEMDUMP NIGGER\n");
		exit(1);
	}
	chores[*lastAlloc] = chore;	
	(*lastAlloc)++;
}

char*
statusToString (Status status) {
	switch (status) {
		case Todo:
			return "Todo";
		case NALLOC:
			return "Not allocated";
		case Done:
			return "Done";
		default:
			printf("Invalid status received %d\n", status);
			exit(1);
	}
}

void
choreToString (Chore chore, char* output) {
	sprintf(output,  "%s\n%s\n%s\n", 
			chore.title, 
			chore.description, 
			statusToString(chore.status));
}

