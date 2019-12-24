#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

//using namespace std;

class Car
{
public:
	explicit Car(const std::string i_brand,const  std::string i_model, int i_price);
	~Car();
	void SetPrice(const int price); //가격 재지정을 위한  setter 그래서 setter가뭔데?
	int GetPrice() const;
	std::string GetBrand() const;
	std::string GetModel() const;
private:
	std::string brand;
	std::string model;
	int price;
};

/* **************************************************** */

class CarManager
{
public:
	explicit CarManager(const std::string &Filename);
	~CarManager();
	void ChangePrice(const std::string &brand, const std::string &model,const int price) ; //brand,model 로 인스턴스찾아서 값변경
	void FindCarInfo(const std::string &brand, const std::string &model) const;
	void Menu() ;
	void PrintCarList() const;
	void SaveChanges() const;
	void SortCarList(); //브랜드-model 순으로 정렬할것
private:
	std::vector<Car> carList;  //카의 인스턴스를 가지는 벡터		인스턴스가 뭐지?
	std::string fileName;
	int FindCarindex(const std::string &brand, const std::string &model) const;
};

bool SortCmp(const Car &a,const  Car &b);

int getNumber();


#endif