
#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
//using namespace std;

class Car
{
private:
	std::string brand;
	std::string model;
public:
	explicit Car(const std::string a, const std::string b);
	virtual~Car();
	virtual void Printinfo() const =0;
	std::string GetBrand() const;
	std::string GetModel() const;
};


class Truck : public Car
{
private:
	double *weight;
public:
	explicit Truck(const std::string a = NULL, const std::string b = NULL,const double c = 0);
	~Truck();
	void Printinfo() const final;
};


class Bus : public Car
{
private:
	int *seat;
public:
	explicit Bus(const std::string a = NULL, const std::string b = NULL, const int c = 0);
	~Bus();
	void Printinfo() const final;
};

#endif
