#include"ternarysearch.hpp"
#include <iostream>
//#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
	vector<int> varr;
	for (int i = 0; i < 100; i++)
	{
		varr.push_back(rand()); //seed�ʱ�ȭ ����
	}
	sort(varr.begin(), varr.end()); // ����
	vector<int>::iterator itr;
	itr = ternary_search(varr, 16827);
	if (itr != varr.end())
	{
		cout << *itr << endl;
		cout << distance(varr.begin(), itr) << endl;
	}
}