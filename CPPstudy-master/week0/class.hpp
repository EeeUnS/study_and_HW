
#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
using namespace std;

class Car
{
private:
	string brand;
	string model;
public:
	Car(string a = NULL, string b = NULL);
	virtual~Car();
	virtual void Printinfo() const;
	string GetBrand() const;
	string GetModel() const;
};


class Truck : public Car
{
private:
	double *weight;
public:
	Truck(string a = NULL, string b = NULL, double c = 0);
	~Truck();
	void Printinfo() const;
};


class Bus : public Car
{
private:
	int *seat;
public:
	Bus(string a = NULL, string b = NULL, int c = 0);
	~Bus();
	void Printinfo() const;
};

#endif
