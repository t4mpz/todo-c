#include <stdio.h>
#include <string.h>
#include "todolib.h"


int 
main(int argc, char** argv) {
	/*
	Chore chore;
	strcpy(chore.title, "Teste");
	strcpy(chore.description, "testing");
	chore.status = Todo;

	Chore chores[MAX_CHORES];
	reset(chores);
	chores[0] = chore;
	

	fclose(choreList);


	printf("Chores written\n");
	**/


	FILE* choreList = fopen("chores", "rb");
	Chore chores[MAX_CHORES];

	int lastChore = getChores(choreList, chores);
	
	fclose(choreList);
	Chore chore;
	strcpy(chore.title, "Teste");
	strcpy(chore.description, "testing");
	chore.status = Todo;

	allocChore(chores, chore, &lastChore);
	choreList = fopen("chores", "wb");
	writeChores(choreList, chores);
	fclose(choreList);

	char result[1024];
	int i = 0;
	int lastStatus;
	do {
		lastStatus = chores[i].status;
		choreToString(chores[i], result);
		printf("%s", result);
		++i;
	} while (i <= MAX_CHORES && lastStatus != NALLOC);
	return 0;
}
