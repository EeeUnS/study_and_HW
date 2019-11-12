#pragma warnig (disable: 4996)
#include "stdio.h"
#define MAX 100
int main()
{
	int data[MAX];
	int n = 0, value;


	while (1) {
		scanf("%d", &value);
		if (value == -1)
			break;
		int i = n - 1;
		while (i >= 0 && data[i] > value) {
			/*	여기 조건을 보면 처음 i=-1인데 배열 인덱스값에서 -1은 오류가난다 그런데
				첫 조건인 i>=0인 조건을 애초에 만족을 하지않기에 뒤의 코드를 확인조
					차 하지않고 넘어가기 때문에 오류가 나오지않는것*/
			data[i + 1] = data[i];
			i--;
		}
		data[i + 1] = value;
		n++;

		for (int i = 0; i < n; i++)
			printf("%d   ", data[i]);
		printf("\n");
	}
	getchar(); getchar();
	return 0;
}