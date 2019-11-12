#include"stdio.h"//ver.2.5
#include <string.h>
#define CAPACITY 100
#define BUFFER_SIZE 20

#pragma warning (disable: 4996)

void add(void);
void find(void);
void status(void);
void remove_1(void);
void load(void);
void save(void);
int search(char *name);
void findall(void);
void deleteall(void);


char * Filename[CAPACITY];
char * names[CAPACITY];						/* names */
char * numbers[CAPACITY];				 /* phone numbers */
int n = 0;								/* number of people in phone directory */
int k = 0;

int main()// findall ,deleteall
{
	char buffer[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", buffer); //띄어쓰기 기준 구분을한다
		if (strcmp(buffer, "read") == 0)
			load();
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "find") == 0)
			find();
		else if (strcmp(buffer, "status") == 0)
			status();
		else if (strcmp(buffer, "delete") == 0)
			remove_1();
		else if (strcmp(buffer, "save") == 0)
			save();
		else if (strcmp(buffer, "findall") == 0)
			findall();
		else if (strcmp(buffer, "deleteall") == 0)
			deleteall();
		else if (strcmp(buffer, "exit") == 0)
			break;
	}
	system("pause");
	return 0;
}
void load(void) {
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	scanf("%s", fileName);
	FILE *fp = fopen(fileName, "r");

	for (int l = 0; l < k; l++)
	{
		if (strcmp(Filename[l], fileName) == 0)
		{
			printf("%s is already read\n", fileName);
			return;
		}
	}

	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	if (n == 0) {
		while ((fscanf(fp, "%s", buf1) != EOF)) {
			fscanf(fp, "%s", buf2);
			names[n] = strdup(buf1);
			numbers[n] = strdup(buf2);
			n++;
		}
	}
	else {
		while ((fscanf(fp, "%s", buf1) != EOF)) {
			int i = n - 1;
			fscanf(fp, "%s", buf2);
			while (i >= 0 && strcmp(names[i], buf1) > 0) { //strcmp 문자열비교 & 정렬
				names[i + 1] = names[i];
				numbers[i + 1] = numbers[i];
				i--;
			}
			names[i + 1] = strdup(buf1);
			numbers[i + 1] = strdup(buf2);
			n++;
		}
	}
	Filename[k++] = strdup(fileName);
	fclose(fp);
}
void save(void) {
	int i;
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];
	scanf("%s ", tmp); // which is "as", discarded
	scanf("%s", fileName);

	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (i = 0; i<n; i++) {
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	printf("saved successfully");
	fclose(fp);
}
void add(void) {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

	scanf("%s", buf1);
	scanf("%s", buf2);
	int i = n - 1;
	while (i >= 0 && strcmp(names[i], buf1) > 0) { //strcmp 문자열비교 & 정렬
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = strdup(buf1);
	numbers[i + 1] = strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);
}
void remove_1(void) {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf); /* returns -1 if not exists */
	if (index == -1) {
		printf("No person named '%s' exists.\n", buf);
		return;
	}
	int j = index;
	for (; j<n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully. \n", buf);
}
void find(void) {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf);
	if (index == -1)
		printf("No person named '%s' exists.\n", buf);
	else
		printf("%s\n", numbers[index]);
}
int search(char *name) { // find에서 쓰기위한 함수
	int i;
	for (i = 0; i<n; i++) {
		if (strcmp(name, names[i]) == 0) {
			return i;
		}
	}
	return -1;
}
void status(void) {
	int i;
	for (i = 0; i<n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
}

void findall(void)
{
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	for (int i = 0; i < n; i++)
	{
		if (strncmp(buf, names[i], strlen(buf)) == 0)
			printf("%s %s\n", names[i], numbers[i]);
	}
}
void deleteall(void) {

	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int count = 0;
	char check[BUFFER_SIZE];

	for (int i = 0; i < n; )
	{
		if (strncmp(buf, names[i], strlen(buf)) == 0)
		{
			printf("Do you want to delete '%s'? ", names[i]);
			scanf("%s", &check);
			if (strcmp(check, "yes") == 0)
			{
				printf("%s was delete\n", names[i]);
				count++;
				int j = i;
				for (; j<n - 1; j++) {
					names[j] = names[j + 1];
					numbers[j] = numbers[j + 1];
				}
				n--;
			}
			else
			{
				printf("%s was not deleted\n", names[i]);
				i++;
			}
		}
		else
			i++;
	}
	printf("%d persons deleted\n", count);
}
