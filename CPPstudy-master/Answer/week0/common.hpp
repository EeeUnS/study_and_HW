#ifndef _COMMON_HPP
#define _COMMON_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
string MergeName(const T& car)
{
	string name = car->GetBrand() + " " + car->GetModel();
	return name;
}

template<typename T1, typename T2>
string MergeName(const T1& car1, const T2& car2)
{
	string name = car1->GetBrand() + " " + car1->GetModel() + "\n" +
		car2->GetBrand() + " " + car2->GetModel();
	return name;
}

#endif
