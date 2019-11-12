#include <iostream>
#pragma warning(disable:4996)
using namespace std;
class CPoint
{
	int x;
	int y;
public:
	CPoint(int a, int b) : x(a) , y(b)
	{}
	friend ostream & operator<<(ostream& os, const CPoint&);
	friend istream & operator>>( istream& is, CPoint& point);
};

ostream & operator<<(ostream& os, const CPoint& point)
{
	os << '(' << point.x << ', ' << point.y << ')' << endl;
	return os;
}

void Print_set()
{
	std::cout << "ÁÂÇ¥ÀÔ·Â  : ";
}


istream & operator>>(istream& is,  CPoint& point)
{
	Print_set();
	is >>point.x >> point.y ;
	return is;
}

int main()
{
	CPoint P1(3, 4);
	cout << P1;
	cin >> P1;
	cout << P1;

}
