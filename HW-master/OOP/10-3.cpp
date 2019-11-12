#include <iostream> //10-3 
using namespace std;

template <typename T>
class CPoint
{
	T x;
	T y;
public:
	CPoint(T a = 0, T b = 0) :x(a), y(b){}
	CPoint operator+(CPoint &arr)
	{
		return CPoint(x + arr.x, y + arr.y);
	}
	template <typename T> //code blocks에서 오류남
	friend ostream &operator<<(ostream &out, CPoint<T> &arr);
};

template <typename T>
ostream &operator<<(ostream &out, CPoint<T> &arr)
{
	out << "(" << arr.x << ", " << arr.y << ")";
	return out;
}

int main(void)
{
	CPoint<int> a(1, 2);
	CPoint<int> b(3, 4);
	CPoint<int> c = a + b;
	cout << a << " + " << b << " = " << c << endl;

	CPoint<double> d(1.2, 3.4);
	CPoint<double> e(5.6, 7.8);
	CPoint<double> f = d + e;
	cout << d << " + " << e << " = " << f << endl;
	system("pause");
	return 0;
}