
#ifndef COMMON_HPP
#define COMMON_HPP
#include"class.hpp"

template<class T>
string merge_brand_model(T &t)
{
	string a = t.GetBrand() + t.GetModel();
	return a;
}

template<class T, class R>
string merge_brand_model(T &a, R &b)
{
	string c = a.GetBrand() + a.GetModel() + b.GetBrand() + b.GetModel();
	return  c;
}
#endif