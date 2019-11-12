#include <iostream>

using namespace std;

template <typename T>
T Sum(T a, T b)
{
	T c = a + b;
	return c;
}

template <>
int Sum(int a, int b)
{
	int c = a * b;
	return c;
}

int Sum(double a, double b)
{
	int c = a - b;
	return c;
}

int main(void)
{
	int x = Sum(3, 4);
	double y = Sum(1.1, 2.2);
	cout << x << endl;
	cout << y << endl;
	return 0;
}