#include <iostream>


class CComplex //7-10
{
public:
	CComplex(double x = 0, double y = 0) : _x(x), _y(y)
	{}
	CComplex operator+(double x){ return CComplex(_x + x,  _y);  }
	CComplex operator-(double x){ return CComplex(_x- x,  _y);  }
	CComplex operator+(CComplex &arr) {	return CComplex(_x + arr.x(), _y+arr.y()); }
	CComplex operator-(CComplex &arr) {	return CComplex(_x - arr.x(), _y-arr.y()); }
	int x() { return _x; }
	int y() { return _y; }

private:
	int _x, _y;
};

CComplex operator+(int a , CComplex &arr)
{
	return CComplex(a + arr.x(), arr.y());
}

CComplex operator-(int a , CComplex &arr)
{
	return CComplex(a - arr.x(), arr.y());
}
void Print(CComplex arr)
{
    std::cout << arr.x() << " " << arr.y() << std::endl;
}
int main()
{
	CComplex C1(1, 2), C2(3, 4);
	double a = 2;

	CComplex C3 = C1 + C2;
	CComplex C4 = C1 - C2;
	CComplex C5 = C1 - a;
	CComplex C6 = a - C1;
	Print(C3);
	Print(C4);
	Print(C5);
	Print(C6);

	return 0;
}
