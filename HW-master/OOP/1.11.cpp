
#include"stdio.h"//1.11
#pragma warning (disable: 4996) 
typedef struct a
{
	int x, y;
}point;

void swap (point *x, point *y)
{
	point tot;
	tot = *x;
	*x = *y;
	*y = tot;

}

int main() {
	int x, y;
	point a, b;
	scanf("%d %d" , &x, &y);

	a.x = x; a.y = y;
	b.x = y; b.y = x;

	printf("a %d %d  b  %d %d\n", a.x, a.y, b.x, b.y);

	swap(&a, &b);

	printf("a %d %d  b  %d %d", a.x, a.y, b.x, b.y);
	system("pause");
	getchar(); getchar();
}