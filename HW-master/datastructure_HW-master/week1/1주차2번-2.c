#include"stdio.h" //�⺻
#include"string.h" //���ڿ�
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
		puts("���Ͼȿ���");
		return 0;
	}

	while (fscanf(fp, "%s ", buffer) != EOF)//strlen ,strcmp -> a , b -> -1��ȯ
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
			arr[n++] = strdup(buffer); //n�� �ڿ���
		}
	}
	fclose(fp);
	���⼭���� �ϴ� �ݺ���
		pick_strimg(arr, n);
	return 0;
}
int pick_strimg(char *array[], int number) //���λ���
{
	char *tmp;
	tmp = array[rand() % number]; //������ ���ڿ� ��
	int length = strlen(tmp); //���ڿ� ���̹�ȯ
	int *t;
	t = (int *)malloc(length * sizeof(int));//����Ϳ� ���� �˻����
	for (int i = 0; i < length; i++)//�ʱ�ȭ
		t[i] = 0;
	guess_game(tmp, t, length);

	if (Last())//�ݺ��˻�
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
	for (int i = 0; i < length; i++)    //���
	{
		if (*(t + i) == 0)
			putchar(42);
		else
			printf("%c", *(tmp + i));
	}
	printf("\n");

	int b = 0; //Ż������ �˻�
	for (int i = 0; i < length; i++)   //Ż������ �˻�
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
	if (last == 'y') //�ݺ�
		return 1;
	else if (last == 'n')
		return 0;
	else
		return Last();
}
