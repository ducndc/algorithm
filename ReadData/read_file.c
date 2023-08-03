#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_IN_LINE	64
#define MAX_LINES_IN_FILE	16
#define MAX_MEMBER_IN_LINE	2

int check(char* name_of_process);

int main(void)
{
	char arrayOfLines[MAX_LINES_IN_FILE][MAX_MEMBER_IN_LINE][MAX_CHAR_IN_LINE];

	FILE *fptr = NULL;
	int i = 0;
	int tot = 0;
	fptr = fopen("file.txt", "r");

	char line[MAX_CHAR_IN_LINE];
	while (fgets(line, sizeof(line) / sizeof(line[0]), fptr) != NULL) {
		if (strchr(line, '\n') == NULL) {
			printf("Line too long...");
			return EXIT_FAILURE;
		}

		char *ptr1 = strtok(line, " ");
		strcpy(arrayOfLines[i][0], ptr1);
		char *ptr2 = strtok(NULL, "\n");
		strcpy(arrayOfLines[i][1], ptr2);
		i++;
	}

	tot = i;

	for (int i = 0;i < tot; i++) {
		printf("%s\n", arrayOfLines[i][0]);
		char name_of_process[64] = {0};
		memcpy(name_of_process, arrayOfLines[i][0], strlen(arrayOfLines[i][0]));
		check(name_of_process);
	}

	return 0;
}

int check(char* name_of_process)
{
	printf("Name of process %s\n", name_of_process);

	return 0;
}
