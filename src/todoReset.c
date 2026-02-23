#include <stdio.h>
#include <string.h>
#include "todolib.h"

int main()
{
    char path[MAX_PATH_SIZE];
    setChorePath(path);

    Chore chores[MAX_CHORES];
    int lastAlloc = 0;
    resetChores(chores, &lastAlloc);

    FILE *choreList = fopen(path, "wb");
    if (choreList == NULL)
    {
        printf("Could not open chores at path %s\n", path);
        return 1;
    }
    writeChores(choreList, chores);
    fclose(choreList);

    return 0;
}
