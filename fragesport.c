#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)

void main()
{
	FILE * fPointer;
	fPointer = fopen("Frågor.txt", "r");
	char text[100];


//	while (!feof(fPointer))
//	{
//		fgets(text, 50, fPointer);
//		puts(text);
//	}
//	fclose(fPointer);

	int count = 0;
	while (fgets(text, 100, fPointer)!= NULL)
	{
		char *p = strchr(text, '\n');
		if (p != NULL) {
			assert(*p == '\n');
			*p = '\0'; // trim the newline
		}
		else { // haven't reached EOL yet. Read & discard the rest of the line.
#define TRASH_LENGTH 1024
			char trash[TRASH_LENGTH];
			while ((p = fgets(trash, TRASH_LENGTH, fPointer)) != NULL) {
				if ((p = strchr(trash, '\n')) != NULL) // reached EOL
					break;
			}
		}
		assert(strchr(text, '\n') == NULL); // `text` does not contain a newline
		count++;
		// ...
	}

	int r = rand() % count;
	printf("%d\n", count);
	printf("%d\n", r);


	system("pause");
}
