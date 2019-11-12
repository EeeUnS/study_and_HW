#include<iostream>

using namespace std;

void funtion(const double &num1,const double  &num2) ;
int main()
{
	double num1, num2;
	cin >> num1 >> num2;
	funtion(num1, num2);
	system("pause");
}

void funtion(const double &num1, const double  &num2)
{
	cout << num1 << " +  " << num2 << " =  " << num1 + num2 << endl;
	cout << num1 << " -  " << num2 << " =  " << num1 - num2 << endl;
	cout << num1 << " *  " << num2 << " =  " << num1 * num2 << endl;
	cout << num1 << " /  " << num2 << " =  " << num1 / num2 << endl;
}