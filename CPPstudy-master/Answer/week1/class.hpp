#ifndef _CLASS_HPP
#define _CLASS_HPP
#include "common.hpp"

using namespace std;

class Car
{
private:
	string brand;
	string model;
	int price;
public:
	explicit Car(const string & brand, const string & model, const int price);
	const string & GetBrand() const;
	const string & GetModel() const;
	int GetPrice() const;
	void SetPrice(const int price);
};

class CarManager
{
private:
	vector<Car> carList;
	string fileName;
public:
	explicit CarManager(const string & fileName);
	void Menu();
	void PrintCarList() const;
	void FindCarInfo(const string & brand, const string & model) const;
	void ChangePrice(const string & brand, const string & model, const int price);
	void SortCarList();
	void SaveChanges();
private:
	static bool SortCmp(const Car &car1, const Car &car2);
};

#endif
