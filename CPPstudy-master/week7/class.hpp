#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

//참고 :https://gist.github.com/pazdera/1098119 
using namespace std;

class Car
{
public:
	Car(const string &i_brand,const string &i_model);
	virtual ~Car();
	string GetBrand() const;
	string GetModel() const;
	virtual void Printinfo() const;
private:
	string brand;
	string model;
	
};

/* **************************************************** */

class Truck : public Car
{
private:
	double weight;
public:
	Truck(const string &i_brand = NULL,const string &i_model = NULL, double i_weight = 0);
	virtual ~Truck();
	virtual void Printinfo() const;
};


class Bus : public Car
{
private:
	int seat;
public:
	Bus(const string &i_brand = NULL,const string &i_model = NULL,const int i_seat = 0);
	virtual ~Bus();
	virtual void Printinfo() const;
};


//singleton
class CarManager
{
public:
	
	~CarManager();
	void FindCarInfo(const string &brand, const string &model) const;
	void Menu();
	void PrintCarList() const;

    static CarManager* getInstance(const string &Filename);
    
private:
	vector<shared_ptr<Car>> carList;
	string fileName;
	int FindCarindex(const string &brand, const string &model) const;
    CarManager(const string &Filename);
    static CarManager* instance;
};



int getNumber();


#endif
