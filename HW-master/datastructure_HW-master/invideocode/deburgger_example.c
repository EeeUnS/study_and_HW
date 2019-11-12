#pragma warning (disable: 4996) //visual studio debugger����
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE	 100
#define MAX 10000

int count_words(char buffer[]);

int words[MAX];
int n = 0;

int main()
{
	char buffer[BUFFER_SIZE];
	FILE *fp = fopen("hurry.txt", "r");
	FILE *fp2 = fopen("output.txt", "w");
	while (!feof(fp))
	{
		fgets(buffer, BUFFER_SIZE, fp);
		int nwords = count_words(buffer);
		fprintf(fp2, "%s: %d:%d\n", buffer, nwords, strlen(buffer));
	}
	fclose(fp);
	fclose(fp2);

	return 0;
}

int count_words(char buffer[])
{
	int count = 0;
	for (int i = 0; i < (int)strlen(buffer); i++)
	{
		if (!isspace(buffer[i]) && isspace(buffer[i - 1]))
			count++;
	}
	return count;
}