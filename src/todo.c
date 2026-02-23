#include <stdio.h>

int main()
{
	printf("Help for todo commands\n");
	printf("Options:\n");
	printf("  todo                                 Show this help message and exit\n");
	printf("  todoRs                               Reset all chores\n");
	printf("  todoCount                            Count the number of chores\n");
	printf("  todoAdd <title> <description>        Add a new chore with the given title and description\n");
	printf("  todoRm <chore>                       Remove the chore with the given number\n");
	printf("  todoGet <chore>                      Get the details of the chore with the given number\n");
	printf("  todoUpdate <chore> <flags> <values>  Update the chore with the given number. Flags can be any combination of T (title), D (description) and S (status). Values should be in the same order as the flags.\n");
	return 0;
}
