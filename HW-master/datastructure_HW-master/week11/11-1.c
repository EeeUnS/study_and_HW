#pragma warning (disable: 4996)
#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

void queens(int);
bool promising(int);
int n;
int col[16] = { 0 , };

int count;
int main()
{
	for (int i = 2; i < 17; i++)
	{
		count = 0;
		n = i;
		queens(0);
		printf("%d \n", count);
	}
	system("pause");
	return 0;
}

void queens(int i)
{
	if (i == n)
	{
		count++;
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			col[i] = j;
			if (promising(i))
			{
				queens(i + 1);
			}
		}
	}
}

bool promising(int i)
{
	for (int j = 0; j<i; j++)
	{
		// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있는지 검사
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}