#define _USE_MATH_DEFINES//2.4
#include<iostream>
#include <cmath>
using namespace std;
void GetArea(double a, double b);
void GetArea(double a);
int main()
{
	
	double x, y;
	int n;
	bool a;
	cout<< "���簢���� �ƹ����� �� 0�� "<<endl;
	cin >> a;
	if (a)
	{
		cin >> x >> y;
		GetArea(x, y);
	}
	else
	{
		cin >> x;
		GetArea(x);
	}

	getchar(); getchar();
}


void GetArea(double a, double b)
{
	cout << a * b << endl;
}
void GetArea(double r)
{
	cout << r * r* M_PI << endl;
}