#include"stdio.h" //1-1
#include"string.h"
#define MAX 100000
#define buffer_lenth 30
#pragma warning (disable: 4996)

typedef struct words
{
	char *word;
	int count;
}Words;

void sorting(char *buffer);

Words words[MAX] = { 0, };
int n = 0;  //words 의갯수

int main() {
	//char *word[MAX];
	char buffer[buffer_lenth];

	FILE  *fp = fopen("harry.txt", "r");
	if (fp == NULL)
	{
		puts("파일안열림");
		return 0;
	}
	while (fscanf(fp, "%s ", buffer) != EOF)//strlen ,strcmp -> a , b -> -1반환
	{
		if (strlen(buffer) > 5 )//정렬해서 저장한다.
		{
			sorting(buffer);
		}
	}
	fclose(fp);

	puts("------------------------------------------");

	FILE  *fpw = fopen("words1.txt", "w");
	for (int i = 0; i < n ; i++)
	{
			fprintf(fpw, "%s", words[i].word);
			fprintf(fpw, " %d \n", words[i].count);
	}
	fclose(fpw);
	puts("------------------------------------------");
	return 0;
}

void sorting(char *buffer)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(words[i].word, buffer) == 0)
		{
			words[i].count++;
			return;
		}
		else if (strcmp(words[i].word, buffer) > 0)// 양수면 바꾼다
		{
			for (int j = n-1; j>=0 && j >= i; j--)//삽입정렬
			{
				words[j + 1] = words[j];
			}
			words[i].count=1 ;
			words[i++].word = strdup(buffer);//n는 단어수
			n++;
			return;
		}
	}
	words[n].count=1;
	words[n++].word = strdup(buffer);//n는 단어수
}