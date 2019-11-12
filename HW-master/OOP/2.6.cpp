
#include<iostream>//2.6
using namespace std;
int *GetArray(int a= 5);

int main()
{
	int *pAry;

	pAry = GetArray(5);
	for (int i = 0; i < 5; i++)
		cout << pAry[i] << " ";
	cout << endl;
	delete[] pAry;

	getchar(); getchar();
}

int *GetArray(int a )
{
	int *p = new int[a];

	for (int i = 0; i < 5; i++)
		p[i] = i;
	return p;
}