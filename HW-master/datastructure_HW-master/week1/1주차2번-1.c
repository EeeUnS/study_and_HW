#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define max 100
#include"time.h"

int last(void);

int main() {
	srand((unsigned int)time(null));
	char *arr[max];
	char buffer[max];
	int count = 1;
	int n = 0;

	file  *fp = fopen("harry.txt", "r");
	if (fp == null)
	{
		puts("파일안열림");
		return 0;
	}

	while (fscanf(fp, "%s ", buffer) != eof)//strlen ,strcmp -> a , b -> -1반환
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
			arr[n] = strdup(buffer);
			n++; //n는 단어수
		}
	}
	fclose(fp);
	//여기서부터 싹다 반복문
	while (1) {
		char *tmp;
		tmp = arr[rand() % n];
		int length = strlen(tmp);

		//printf("%s %s %s", *tmp, *(tmp + 1) , tmp);
		int *t;
		t = (int *)malloc(length * sizeof(int));
		for (int i = 0; i < length; i++) {
			t[i] = 0;
		}
		while (1)
		{
			int a;
			puts("guess an alphabet");

			a = getchar();
			getchar();
			//puts(" ");
			for (int i = 0; i < length; i++) {
				if (a == *(tmp + i))
					t[i] = 1;
			}
			for (int i = 0; i < length; i++) {  //출력
				if (t[i] == 0)
					putchar(42);
				else
					printf("%c", *(tmp + i));
			}

			int b = 0;
			for (int i = 0; i < length; i++) { //다 맞췄나 검사
				if (t[i] == 0)
					break;
				if (i == length - 1)
					b++;
			}
			if (b)
				break;

			printf("\n");


		}//맞추기

		printf("\n");
		if (last())//반복검사
			break;
	}

	return 0;
}
int last(void)
{
	int last;
	printf("try again (y/n) ?");
	last = getchar();
	if (last == 'y')
		return 0;
	else if (last == 'n')
		return 1;
	else
		last();
}



