#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<boost/asio.hpp>
#include<memory>
// :https://gist.github.com/pazdera/1098119 

//using namespace std;
//using namespace boost::asio;

enum class menu : int
{
	printCarList = 1,
	findCarInfo = 2,
	saveChanges = 3,
};

class Car
{
public:
	Car(const std::string& i_brand, const std::string& i_model);
	virtual ~Car();
	std::string GetBrand() const;
	std::string GetModel() const;
	virtual void Printinfo(boost::asio::ip::tcp::socket& socket) const;
private:
	std::string brand;
	std::string model;

};

/* **************************************************** */

class Truck : public Car
{
private:
	double weight;
public:
	Truck(const std::string& i_brand = NULL, const std::string& i_model = NULL, double i_weight = 0);
	virtual ~Truck();
	virtual void Printinfo(boost::asio::ip::tcp::socket& socket) const final override;
};


class Bus : public Car
{
private:
	std::size_t seat;
public:
	explicit Bus(const std::string& i_brand = NULL, const std::string& i_model = NULL, std::size_t i_seat = 0);
	virtual ~Bus();
	virtual void Printinfo(boost::asio::ip::tcp::socket& socket) const final override;
};


//singleton
class CarManager
{
public:

	~CarManager();
	void FindCarInfo(const std::string& brand, const std::string& model, boost::asio::ip::tcp::socket& socket) const;
	void set(char number, std::size_t  id, boost::asio::ip::tcp::socket& socket);
	void PrintCarList(boost::asio::ip::tcp::socket& socket) const;

	static CarManager* getInstance(const std::string& Filename); //single ton

private:
	std::vector<std::shared_ptr<Car>> carList;
	std::string fileName;
	int FindCarindex(const std::string& brand, const std::string& model) const;
	CarManager(const std::string& Filename);
	static CarManager* instance; //single ton
};

#endif