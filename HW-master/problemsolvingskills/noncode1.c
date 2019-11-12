#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
#define MAX 100
int main()//5번
{
	int num;
	int	tot = 0;
	scanf("%d", &num);
	while (num != 0)
	{
		tot = num % 10 + tot * 10;
		num /= 10;
	}
	printf("%d", tot);
	getchar(); getchar();
	return 0;
}
