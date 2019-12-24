
#ifndef COMMON_HPP
#define COMMON_HPP
//#include"class.hpp"
#include<string>


template<class T>
std::string merge_brand_model(T &t)
{
	std::string a = t.GetBrand() + t.GetModel();
	return a;
}

template<class T, class R>
std::string merge_brand_model(T &a, R &b)
{
	std::string c = a.GetBrand() + a.GetModel() + b.GetBrand() + b.GetModel();
	return  c;
}
#endif