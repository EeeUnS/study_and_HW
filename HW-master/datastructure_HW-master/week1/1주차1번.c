
#include"stdio.h" //1-1
#include"string.h"
#include"stdlib.h"
#define MAX 100000
#pragma warning (disable: 4996)

int main() {
	char *arr[MAX];
	char buffer[MAX];
	int count = 1;
	int n = 0;

	FILE  *fp = fopen("harry.txt", "r");
	if (fp == NULL)
	{
		puts("파일안열림");
		return 0;
	}

	while (fscanf(fp, "%s ", buffer) != EOF)//strlen ,strcmp -> a , b -> -1반환
	{
		if (strlen(buffer) > 5)
		{
			arr[n++] = strdup(buffer);//n는 단어수
		}
	}

	fclose(fp);
	char *tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)// 양수면 바꾼다
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	FILE  *fpw = fopen("words.txt", "w");

	puts("------------------------------------------");

	for (int i = 0; i < n - 1; i++)
	{
		if (strcmp(arr[i], arr[i + 1]) < 0)//다르면 출력
		{
			fprintf(fpw, "%s", arr[i]);
			fprintf(fpw, " %d \n", count);
			count = 1;
		}
		else
			count++;
	}
	fclose(fpw);
	puts("------------------------------------------");
	return 0;
}
