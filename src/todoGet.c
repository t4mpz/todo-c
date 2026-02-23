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

    if (argc < 2)
    {
        printf("Usage: %s get <chore_number>\n", argv[0]);
        return 0;
    }
    int chore = atoi(argv[1]);

    if (chore == 0 && strcmp(argv[1], "0") != 0)
    {
        printf("Invalid chore number %s for %s\n", argv[1], argv[0]);
        return 0;
    }

    if (chore >= lastAlloc || chore < 0)
    {
        printf("Chore number %d out of bounds for %s\n", chore, argv[0]);
        return 0;
    }

    printChore(chores[chore]);
    printf("--------------------------------\n");

    return 0;
}
