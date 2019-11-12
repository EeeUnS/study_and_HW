#include"stdio.h"//1.9
#include<Windows.h>
#pragma warning (disable: 4996) 
int pow(int a, int n)
{
	if (n == 0)
		return 1;

	return (pow(a,n-1)*a);//????
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", pow(a,b));
	system("pause");
	return 0;
}