#include"stdio.h" //기본
#include"string.h" //문자열
#include"stdlib.h" //rand
#define MAX 100
#include"time.h" //time

int Last(void);
int pick_strimg(char *array[], int number);
int guess_game(char *tmp, int t[], int length);

int main()
{
	srand((unsigned int)time(NULL));
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
		if (strlen(buffer) > 6)
		{
			int a = 0;
			for (int i = 0; i < n; i++)
			{
				if (strcmp(arr[i], buffer) == 0)
					a++;
			}
			if (a > 0)
				break;
			arr[n++] = strdup(buffer); //n은 자연수
		}
	}
	fclose(fp);
	여기서부터 싹다 반복문
		pick_strimg(arr, n);
	return 0;
}
int pick_strimg(char *array[], int number) //새로생성
{
	char *tmp;
	tmp = array[rand() % number]; //랜덤한 문자열 선
	int length = strlen(tmp); //문자열 길이반환
	int *t;
	t = (int *)malloc(length * sizeof(int));//맞춘것에 대한 검사요인
	for (int i = 0; i < length; i++)//초기화
		t[i] = 0;
	guess_game(tmp, t, length);

	if (Last())//반복검사
		pick_strimg(array, number);
	return 0;
}
int guess_game(char *tmp, int t[], int length)
{
	char a;
	puts("Guess an alphabet");

	a = getchar();
	getchar();
	for (int i = 0; i < length; i++)
	{
		if (a == *(tmp + i))
			t[i] = 1;
	}
	for (int i = 0; i < length; i++)    //출력
	{
		if (*(t + i) == 0)
			putchar(42);
		else
			printf("%c", *(tmp + i));
	}
	printf("\n");

	int b = 0; //탈출조건 검사
	for (int i = 0; i < length; i++)   //탈출조건 검사
	{
		if (t[i] == 0)
			break;
		if (i == length - 1)
			b++;
	}
	if (b)
		return 0;
	guess_game(tmp, t, length);
}
int Last(void)
{
	int last;
	printf("Try again (y/n) ?");
	last = getchar();
	if (last == 'y') //반복
		return 1;
	else if (last == 'n')
		return 0;
	else
		return Last();
}
