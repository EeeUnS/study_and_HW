#pragma warning (disable: 4996)
//#pragma warning(suppress : 4996)
#include "stdio.h"
#define MAX 100

int main()
{
	int x = 0, y = 0 , count = 0;

	while (x < 100 )
	{
		y = (x/3)  ;
		while (y < 100) {

			if (3 * y - 2 * x > 0)
				break;
			if ( x*x +y*y <=10000 && (3 * y - x >= 0))//(3*y-2*x <= 0)  &&( 3*y-x>=0) &&
				count++;
			y++;
		}
		x++;
	}


	printf("%d", count);

	getchar(); getchar();
	system("pause");
	return 0;
}
