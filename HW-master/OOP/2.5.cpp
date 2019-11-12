
#include<iostream>//2.5
using namespace std;
void Sum(int a=0 , int b = 0, int c = 0, int d = 0, int e=0);
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	Sum();
	Sum(a);
	Sum(a, b);
	Sum(a, b, c);
	Sum(a, b,c, d);
	Sum(a, b,c, d,e);

	getchar(); getchar();
}

void Sum(int a , int b , int c , int d , int e )
{
	cout << a + b + c + d + e << endl;
}