#ifndef TERNARYSEARCH_HPP
#define TERNARYSEARCH_HPP

#include<vector>
#include<iostream>
using namespace std;

vector<int>::iterator ternary_search(vector<int> &arr, int number)
{
	int start = 0;
	int end = arr.size();

	while (!(end - start == 1))
	{
		if (number >=arr[start]  &&  number <= arr[start + (end - start) / 3])
			end = start + ( end -start)/ 3 + 1 ;
		else if (number > arr[start + (end - start) / 3] && number <= arr[start + (end - start) * 2 / 3])
		{
			start = start + (end - start) / 3 + 1 ;
			end = start + (end - start) * 2 / 3 + 1;
		}
		else if (number > arr[(start + end) * 2 / 3] && number < arr[end])
			start = start + (end - start) * 2 / 3 + 1 ;
		else//¹üÀ§ ¹þ¾î³²
			return arr.end();
	}
	return arr.begin()+start ;
}




#endif