#include <stdio.h>
#include <string.h>
#include "todolib.h"

int 
main (int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("Usage: %s <title> (optional)<description> (optional)<status>\n", argv[0]);
        return 1;
    }

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

    // TODO: handle multiple word titles and descriptions
    Chore chore;
    strcpy(chore.title, argv[1]);
    strcpy(chore.description, argv[2]);
    chore.status = Todo;
    if (argc > 3)
    {
        chore.status = stringToStatus(argv[3]);
    }

    addChore(chores, chore, &lastAlloc);

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
