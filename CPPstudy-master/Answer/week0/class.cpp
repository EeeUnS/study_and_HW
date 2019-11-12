#include "class.hpp"

Car::Car(const string brand, const string model)
	:brand(brand), model(model)
{	}

string Car::GetBrand() const
{
	return brand;
}

string Car::GetModel() const
{
	return model;
}

Car::~Car()
{	}

Bus::Bus(const string brand, const string model, const int seat)
	: Car(brand, model)
{
	this->seat = new int(seat);
}

void Bus::PrintInfo() const
{
	string tmp = GetBrand();
	cout << GetBrand() << " " << GetModel() << " " << *seat << endl;
}

Bus::~Bus()
{
	delete seat;
}

Truck::Truck(const string brand, const string model, const double weight)
	: Car(brand, model)
{
	this->weight = new double(weight);
}

void Truck::PrintInfo() const
{
	cout << GetBrand() << " " << GetModel() << " " << *weight << endl;
}

Truck::~Truck()
{
	delete weight;
}
