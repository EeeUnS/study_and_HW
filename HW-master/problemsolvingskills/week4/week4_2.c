#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
#define MAX 100

int gcd1(int a, int b)
{
	return b ? gcd1(b, a%b) : a;
}

int main()
{

	int x = 2, y = 2, z = 2;//(x ,y,z)
	int count =0;

	while (x <= 100)
	{
		y = x;
		while (y <= 100) {
			z = y;
			if (gcd1(x,y) == 1 ) //x,y�� ���μ� �ϼ�������  �ִ������� 1�̴�.
			{
				while (z <= 100)
				{
					if (gcd1(x, z) == 1 && gcd1(y, z) == 1) { //xyz�� ���μ� �ϼ�������
						count++;
					}

					z++;
				}
			}
			y++;
		}
		x++;
	}
	printf("%d", count);
	getchar(); getchar();
	system("pause");
	return 0;
}
