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
		printf("파일 안열림");
		return -1;
	}

	int N;
	fscanf(fp, "%d ", &N);
	int M = (int)sqrt(N);
	int brr_index = 0; //후위증가


	for (int i = 0; i < N; ) {
		int small = INT_MAX;
		int index = 0;
		for (int j = 0; j < M && i < N; i++, j++) {// M그룹으로 그룹화한것을 나타낸다
			fscanf(fp, "%d ", &arr[i]); //j,i ++
			if (arr[i] < small) {
				small = arr[i];
				index = i;
			}
		}
		brr[brr_index].number = small;
		brr[brr_index++].index = index;
	}
	fclose(fp);  //여기까지 최솟값들, 전체 배열을 저장한다. 시간복잡도 N
	printf("N : %d\n", N);

	while (1)  //실제 실행
	{
		//한 사이클
		int a = check(N); // 문제에서의  i , j 
		int b = check(N);
		if (a > b) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		// 포함되는 brr 인덱스를 찾자
		if (b - a < M-1)//M-1 미만의 값범위에서는 일일이 다세도록한다
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
			if (a == 0){ //-1/10~ 값이 0이나오기때문에 따로처리
				first_index = 0;
			}
			else{   //일반적인경우
				first_index = ((a - 1) / M) + 1;
			}
			int last_index= ((b+1) / M) - 1 ; // 끝자리 99일때 처리 
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
			if (((b + 1) % M))// 끝자리 99에서의 예외 처리
			{
				for (int j = last_index * M; j <= b; j++) { //0~99일때 도는걸 처리해야한다.
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
		printf("-1 이상의 %d 미만의 값을 입력하세요 \n", N);
	}
}


/*
추가로 난 오류케이스들 
test case
1 5
0 99
0 201

1. 0~N-1이 값으로 주어진다면 0~N-1번 모두 순회해야해서 O(N)
2. 1,N-2가 주어지고모두 data값이 모두 내림차순일때
3. 반목문 실행횄수만 따졌을때 O(99 + 98  + 99 )

*/