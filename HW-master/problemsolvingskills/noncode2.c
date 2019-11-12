#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
int main()////newtons method
{
	int x;
	long double ny = 1, y = 1;
	long double e = 0;
	scanf("%d", &x);
	do
	{
		y = ny;
		ny = (y + x / y) / 2;
		e = 0.00001*ny;
		printf("ny : %llf y : %llf e : %llf \n", ny, y, e);

	} while (ny - y > e | y - ny > e);
	printf("결과 %llf", ny);
	getchar(); getchar();
	return 0;
}
