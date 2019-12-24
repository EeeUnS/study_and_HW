#pragma once
#include"class.hpp"

Car::Car(const std::string a, const std::string b ): brand(a), model(b) {  }

Car::~Car() {  }

void Car::Printinfo() const
{
	std::cout << "브랜드명 : " << this->brand << std::endl;
	std::cout << "모델명 : "<< this->model << std::endl;
}


std::string Car::GetBrand()  const
{
	return this->brand;
}

std::string Car::GetModel() const
{
	return this->model;
}




Truck::Truck(const std::string a, const std::string b , const double c ) : Car(a,b)
{ weight = new double(c); }

Truck::~Truck() { delete weight; }

void Truck::Printinfo() const
{
	std::cout << "브랜드명 : " << this->GetBrand() << std::endl;
	std::cout << "모델명 : " << this->GetModel() << std::endl;
	std::cout << "무게 : " << *(this->weight) << std::endl;
}




Bus::Bus(const std::string a, const std::string b,const int c ) : Car(a, b) 
{ seat = new int(c); }

Bus::~Bus() { delete seat; }

void Bus::Printinfo() const
{

	std::cout << "브랜드명 : " << this->GetBrand() << std::endl;
	std::cout << "모델명 : " << this->GetModel() << std::endl;
	std::cout << "좌석수 : " << *(this->seat) << std::endl;
}