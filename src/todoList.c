#include <stdio.h>
#include "todolib.h"

int 
main()
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

    for (int chore = 0; chore < lastAlloc; chore++)
    {
        printChore(chores[chore]);
        printf("--------------------------------\n");
    }

    return 0;
}
