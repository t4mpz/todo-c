#include <stdio.h>
#include <string.h>
#include "todolib.h"

int 
main (int argc, char **argv)
{
    char path[MAX_PATH_SIZE];
    setChorePath(path);

    Chore chores[MAX_CHORES];

    FILE *choreList = fopen(path, "rb");
    if (choreList == NULL)
    {
        printf("Could not open chores at path %s\n", path);
        return 1;
    }
    readChores(choreList, chores);
    fclose(choreList);

    int lastAlloc = lastChore(chores);

    if (argc < 4)
    {
        printf("Usage: %s <chore number> <update flags> <update values>\n", argv[0]);
        return 1;
    }

    int chore = atoi(argv[1]);
    if (chore == 0 && strcmp(argv[1], "0") != 0)
    {
        printf("Invalid number %s for chore update\n", argv[1]);
        return 1;
    }

    if (chore >= lastAlloc || chore < 0)
    {
        printf("Chore number %d out of bounds\n", chore);
        return 1;
    }


    int updateFlagCount = strlen(argv[2]);
    if (updateFlagCount > 4 || updateFlagCount == 0)
    {
        printf("Invalid argument %s for status in update\n", argv[2]);
        return 1;
    }
    char updateFlags[5] = "";
    strcpy(updateFlags, argv[2]);
    if (updateFlags[0] == '-') {
	    strcpy(updateFlags, &updateFlags[1]);
    }
    updateFlagCount = strlen(updateFlags);
    if (updateFlagCount == 0) {
	    printf("Invalid argument %s for status in update\n", argv[2]);
	    exit(1);
    }
    if (updateFlagCount + 2 >= argc)
    {
        printf("Missing arguments for %s %s\n", argv[0], argv[2]);
        printf("Usage: %s <chore number> <update flags> <update values>\n", argv[0]);
        return 1;
    }

    // TODO: handle multiple word titles and descriptions
    char title[MAX_TEXT_SIZE];
    strcpy(title, chores[chore].title);

    char description[MAX_TEXT_SIZE];
    strcpy(description, chores[chore].description);

    Status status = chores[chore].status;

    for (int statusArg = 0; statusArg < updateFlagCount; statusArg++)
    {
        switch (updateFlags[statusArg])
        {
        case 'T':
            strcpy(title, argv[statusArg + 3]);
            break;
        case 'D':
            strcpy(description, argv[statusArg + 3]);
            break;
        case 'S':
            status = stringToStatus(argv[statusArg + 3]);
            break;
        default:
            printf("Unknown update flag %c (expected T | D | S) for %s\n", updateFlags[statusArg], argv[0]);
            break;
        }
    }

    strcpy(chores[chore].title, title);
    strcpy(chores[chore].description, description);
    chores[chore].status = status;

    printChore(chores[chore]);

    choreList = fopen(path, "wb");
    if (choreList == NULL)
    {
        printf("Could not open chores at path %s\n", path);
        return 1;
    }
    writeChores(choreList, chores);
    fclose(choreList);

    return 0;
}
