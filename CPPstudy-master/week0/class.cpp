#pragma once
#include"class.hpp"

Car::Car(string a, string b ): brand(a), model(b) {  }

Car::~Car() {  }

void Car::Printinfo() const
{
	cout << "브랜드명 : " << this->brand << endl;
	cout << "모델명 : "<< this->model << endl;
}
string Car::GetBrand()  const
{
	return this->brand;
}

string Car::GetModel() const
{
	return this->model;
}




Truck::Truck(string a, string b , double c ) : Car(a,b)
{ weight = new double(c); }

Truck::~Truck() { delete weight; }

void Truck::Printinfo() const
{
	cout << "브랜드명 : " << this->GetBrand() << endl;
	cout << "모델명 : " << this->GetModel() << endl;
	cout << "무게 : " << *(this->weight) << endl;
}




Bus::Bus(string a, string b, int c ) : Car(a, b) 
{ seat = new int(c); }

Bus::~Bus() { delete seat; }

void Bus::Printinfo() const
{

	cout << "브랜드명 : " << this->GetBrand() << endl;
	cout << "모델명 : " << this->GetModel() << endl;
	cout << "좌석수 : " << *(this->seat) << endl;
}