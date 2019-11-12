#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
#include"stdlib.h"
#include"time.h"
#define MAX 100


int main()
{
	int arr[MAX] = { 0 };
	int n;
	scanf("%d", &n);
	int a, b;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		a = i; //A^0
		for (int i = 0; i < n; i++)
		{
			b = arr[a];
			if (a == b)
			{
				printf("%d ", a);
				break;
			}
			if (i == n - 1)
				printf("-1 ");
			a = arr[b];

		}
	}

	system("pause");
	return 0;
}