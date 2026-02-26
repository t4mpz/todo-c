#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "todolib.h"

void 
writeChores (FILE *choreList, Chore *chores)
{
	size_t result = fwrite(chores, sizeof(Chore), MAX_CHORES, choreList);
	if (result != MAX_CHORES)
	{
		printf("Error writing chores to file, wrote %zu out of %d\n", result, MAX_CHORES);
		exit(1);
	}
	return;
}

int 
readChores (FILE *choreList, Chore *chores)
{
	int lastAlloc = 0;
	resetChores(chores, &lastAlloc);
	size_t result = fread(chores, sizeof(Chore), MAX_CHORES, choreList);
	if (result != MAX_CHORES)
	{
		printf("Error reading chores from file, read %zu out of %d\n", result, MAX_CHORES);
		exit(1);
	}
	return lastChore(chores);
}

void 
removeChore (Chore *chores, int *lastAlloc, int chore)
{
	if (chore >= MAX_CHORES - 1)
	{
		chores[chore].status = NALLOC;
		(*lastAlloc)--;
		return;
	}
	Chore *next = &chores[chore + 1], *current = &chores[chore];
	while (next->status != NALLOC)
	{
		strcpy(current->title, next->title);
		strcpy(current->description, next->description);
		current->status = next->status;
		current++;
		next++;
	}
	strcpy(current->title, "\0");
	strcpy(current->description, "\0");
	current->status = NALLOC;
	(*lastAlloc)--;
	return;
}

void 
resetChores (Chore *chores, int *lastAlloc)
{
	int counter = 0;
	for (Chore *chore = chores; counter < MAX_CHORES; chore++)
	{
		strcpy(chore->title, "\0");
		strcpy(chore->description, "\0");
		chore->status = NALLOC;
		counter++;
	}
	*lastAlloc = 0;
	return;
}

int 
lastChore (Chore *chores)
{
	int counter = 0;
	for (Chore *chore = chores; counter < MAX_CHORES && chore->status != NALLOC; ++chore)
	{
		char str[1024];
		choreToString(*chore, str);
		++counter;
	}
	return counter;
}

void 
addChore (Chore *chores, Chore chore, int *lastAlloc)
{
	if (*lastAlloc >= MAX_CHORES)
	{
		printf("MEMDUMP NIGGER\n");
		exit(1);
	}
	chores[*lastAlloc] = chore;
	(*lastAlloc)++;
}

char *
statusToString (Status status)
{
	switch (status)
	{
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

Status 
stringToStatus (char *status)
{
	if (strcasecmp(status, "todo") == 0)
	{
		return Todo;
	}
	else if (strcasecmp(status, "done") == 0)
	{
		return Done;
	}
	else
	{
		printf("Invalid status string received %s\n", status);
		exit(1);
	}
}

void 
choreToString (Chore chore, char *output)
{
	sprintf(output, "%s\n%s\n%s\n",
			chore.title,
			chore.description,
			statusToString(chore.status));
}

void 
printChore (Chore chore)
{
	printf("%s\n%s\n%s\n",
			chore.title,
			chore.description,
			statusToString(chore.status));
}

void 
setChorePath (char *path)
{
	const char *envPath = getenv("CHORE_PATH");
	if (envPath != NULL && strlen(envPath) < MAX_PATH_SIZE)
	{
		strcpy(path, envPath);
		return;
	}
	const char *home = getenv("HOME");
	if (home != NULL)
	{
		snprintf(path, MAX_PATH_SIZE, "%s/.config/chores", home);
		return;
	}
	strcpy(path, "./chores");
}
