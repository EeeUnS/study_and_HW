#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
#include"stdlib.h"
#include"time.h"
#define MAX 100

typedef struct line {

	int f_x;
	int f_y;
	int e_x;
	int e_y;
}Line;

int main()
{
	Line arr[MAX];
	FILE  *fp = fopen("input.txt", "r");

	int N = 0;
	fscanf(fp, "%d ", &N);
	for (int i = 0; i < N; i++)
	{
		fscanf(fp, "%d ", &arr[i].f_x);
		fscanf(fp, "%d ", &arr[i].f_y);
		fscanf(fp, "%d ", &arr[i].e_x);
		fscanf(fp, "%d ", &arr[i].e_y);
		/*if (fscanf(fp, "%d", &arr[n].f_x) == EOF)
			break;*/
	}
	fclose(fp);

	//for (int i = 0; i<N; i++)//테스트용 출력
	//{
	//	printf("%d %d %d %d \n", arr[i].f_x, arr[i].f_y, arr[i].e_x, arr[i].e_y);
	//}


	for (int i = 0; i < N; i++) {

		if (arr[i].f_x == arr[i].e_x)//수직선  교점은 수평선의 와이좌표,수직선의 x좌표
		{
			for (int j = 0; j < N; j++)
			{
				//j는 수평선
				if (arr[j].f_y == arr[j].e_y &&  //일치조건
					arr[j].f_x <= arr[i].e_x && arr[i].e_x <= arr[j].e_x  //x범위 통과
					&& arr[i].f_y <= arr[j].f_y && arr[j].e_y <= arr[i].e_y)//y범위
							//수직선일조건과 교점이 형성되었을때
				{
					printf("[ %d ,%d ] \n", arr[i].e_x, arr[j].e_y);
				}
			}
		}

	}
	system("pause");
	return 0;
}