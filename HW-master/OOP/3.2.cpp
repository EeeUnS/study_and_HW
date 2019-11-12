
#include<iostream>//3.2
using namespace std;
int main()
{
	int var1 = 2, var2 = 3;
	int &ref1 = var1;
	int &ref2 = var2;

	int var3 = ref1;
	ref1 = ref2;
	ref2 = var3;

	cout << "var1 :" << var1 << endl;
	cout << "var2 :" << var2 << endl;


	getchar(); getchar();
}