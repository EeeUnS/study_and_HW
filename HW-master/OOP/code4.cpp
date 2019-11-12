#include <iostream>
#pragma warning(disable:4996)
using namespace std;


template<typename T ,int a>
class CPoint
{
	T x;
	T y;

public:
	CPoint(T a = 0, T b= 0 ) : x(a) ,y(b)
	{
	}
	void Print()
	{
		std::cout << '(' << x << ", " << y <<')' << std::endl;
		std::cout << " : " << a << std::endl;
	}
	
};

int main()
{
	CPoint<int, 15> P1(3, 4);
	P1.Print();
	system("pause");
	return 0;

}
