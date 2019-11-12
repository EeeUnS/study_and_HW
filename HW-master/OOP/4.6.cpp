
#pragma warning (disable: 4996) 
#include<iostream> //4-6
#include<cstring>
using namespace std;

class CPoint
{
private:


public:
	int x;
	int y;

	CPoint()
	{
		x = 0;
		y = 0;
	}
	CPoint(int n)
	{
		x = n;
		y = n;
	}
	CPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	CPoint(int a, int b, int c)
	{
		x = a + b + c;
		y = a * b*c;
	}
	void Print()
	{
		cout << "{" << x << "," << y << "}" << endl;
	}
};

int main()
{
	CPoint P1;
	CPoint P2(1);
	CPoint P3(2, 3);
	CPoint P4(4, 5, 6);

	P1.Print();
	P2.Print();
	P3.Print();
	P4.Print();
	getchar(); getchar();
	return 0;
}