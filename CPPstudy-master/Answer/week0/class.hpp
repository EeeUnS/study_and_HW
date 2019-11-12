#ifndef _CLASS_HPP
#define _CLASS_HPP
#include "common.hpp"

using namespace std;

class Car
{
private:
	string brand;
	string model;
public:
	explicit Car(const string brand, const string model);
	virtual void PrintInfo() const = 0;
	string GetBrand() const;
	string GetModel() const;
	virtual ~Car();
};

class Bus : public Car
{
private:
	int *seat;
public:
	explicit Bus(const string brand, const string model, const int seat);
	virtual void PrintInfo() const;
	virtual ~Bus();
};

class Truck :public Car
{
private:
	double *weight;
public:
	explicit Truck(const string brand, const string model, const double weight);
	virtual void PrintInfo() const;
	virtual ~Truck();
};

#endif
