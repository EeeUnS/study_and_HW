#pragma warning (disable: 4996)
#include  <stdio.h>
#include  <stdlib.h>
#include <math.h>
#include <limits.h> 

typedef struct gouping
{
	int number;
	int index;
}Gouping;

int arr[10000];
Gouping brr[100];

int check(int N);

int main()
{
	FILE *fp = fopen("data.txt", "r");
	if ((int)fp == -1)	{
		printf("���� �ȿ���");
		return -1;
	}

	int N;
	fscanf(fp, "%d ", &N);
	int M = (int)sqrt(N);
	int brr_index = 0; //��������


	for (int i = 0; i < N; ) {
		int small = INT_MAX;
		int index = 0;
		for (int j = 0; j < M && i < N; i++, j++) {// M�׷����� �׷�ȭ�Ѱ��� ��Ÿ����
			fscanf(fp, "%d ", &arr[i]); //j,i ++
			if (arr[i] < small) {
				small = arr[i];
				index = i;
			}
		}
		brr[brr_index].number = small;
		brr[brr_index++].index = index;
	}
	fclose(fp);  //������� �ּڰ���, ��ü �迭�� �����Ѵ�. �ð����⵵ N
	printf("N : %d\n", N);

	while (1)  //���� ����
	{
		//�� ����Ŭ
		int a = check(N); // ����������  i , j 
		int b = check(N);
		if (a > b) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		// ���ԵǴ� brr �ε����� ã��
		if (b - a < M-1)//M-1 �̸��� ������������ ������ �ټ������Ѵ�
		{
			int min = INT_MAX;
			int index = 0;
			for (int j = a; j < b; j++) {
				if (min > arr[j])
				{
					min = arr[j];
					index = j;
				}
			}
			printf("data[%d] = %d\n", index, min);
		}
		else {
			int first_index;
			if (a == 0){ //-1/10~ ���� 0�̳����⶧���� ����ó��
				first_index = 0;
			}
			else{   //�Ϲ����ΰ��
				first_index = ((a - 1) / M) + 1;
			}
			int last_index= ((b+1) / M) - 1 ; // ���ڸ� 99�϶� ó�� 
			int min = INT_MAX;
			int index = 0;
			for (int j = a; j < first_index*M; j++) {
				if (min > arr[j]){
					min = arr[j];
					index = j;
				}
			}
			for (int j = first_index; j <= last_index; j++) {
				if (min > brr[j].number) {
					min = brr[j].number;
					index = brr[j].index;
				}
			}
			if (((b + 1) % M))// ���ڸ� 99������ ���� ó��
			{
				for (int j = last_index * M; j <= b; j++) { //0~99�϶� ���°� ó���ؾ��Ѵ�.
					if (min > arr[j]) {
						min = arr[j];
						index = j;
					}
				}
			}
			printf("data[%d] = %d\n", index, min);
		}
	}
	return 0;
}

int check(int N)
{
	int a;
	while (1)
	{
		scanf("%d", &a);
		if (a > -1 && a < N)
			return a;
		else if (a == -1)
			exit(-1);
		printf("-1 �̻��� %d �̸��� ���� �Է��ϼ��� \n", N);
	}
}


/*
�߰��� �� �������̽��� 
test case
1 5
0 99
0 201

1. 0~N-1�� ������ �־����ٸ� 0~N-1�� ��� ��ȸ�ؾ��ؼ� O(N)
2. 1,N-2�� �־������� data���� ��� ���������϶�
3. �ݸ� ����Ã���� �������� O(99 + 98  + 99 )

*/