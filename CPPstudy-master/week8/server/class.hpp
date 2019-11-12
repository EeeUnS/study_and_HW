#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<boost/asio.hpp>

//½Ì±ÛÅÏ Âü°í :https://gist.github.com/pazdera/1098119 

using namespace std;
using namespace boost::asio;

enum menu {
	printCarList = 1,
	findCarInfo = 2,
	saveChanges = 3,
};

class Car
{
public:
	Car(const string &i_brand, const string &i_model);
	virtual ~Car();
	string GetBrand() const;
	string GetModel() const;
	virtual void Printinfo(ip::tcp::socket &socket) const;
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
	Truck(const string &i_brand = NULL, const string &i_model = NULL, double i_weight = 0);
	virtual ~Truck();
	virtual void Printinfo(ip::tcp::socket &socket) const;
};


class Bus : public Car
{
private:
	int seat;
public:
	Bus(const string &i_brand = NULL, const string &i_model = NULL, const int i_seat = 0);
	virtual ~Bus();
	virtual void Printinfo(ip::tcp::socket &socket) const;
};


//singleton
class CarManager
{
public:

	~CarManager();
	void FindCarInfo(const string &brand, const string &model, ip::tcp::socket &socket) const;
	void set(char number, int id, ip::tcp::socket &socket);
	void PrintCarList(ip::tcp::socket &socket) const;

	static CarManager* getInstance(const string &Filename);

private:
	vector<shared_ptr<Car>> carList;
	string fileName;
	int FindCarindex(const string &brand, const string &model) const;
	CarManager(const string &Filename);
	static CarManager* instance;
};
#endif