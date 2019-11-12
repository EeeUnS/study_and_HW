#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

class Car
{
public:
	Car(string i_brand, string i_model, int i_price);
	~Car();
	void SetPrice(const int price); //가격 재지정을 위한  setter 그래서 setter가뭔데?
	int GetPrice() const;
	string GetBrand() const;
	string GetModel() const;
private:
	string brand;
	string model;
	int price;
};

/* **************************************************** */

class CarManager
{
public:
	CarManager(const string &Filename);
	~CarManager();
	void ChangePrice(const string &brand, const string &model,const int price) ; //brand,model 로 인스턴스찾아서 값변경
	void FindCarInfo(const string &brand, const string &model) const;
	void Menu()  ;
	void PrintCarList() const;
	void SaveChanges() const;
	void SortCarList(); //브랜드-model 순으로 정렬할것
private:
	vector<Car> carList;  //카의 인스턴스를 가지는 벡터		인스턴스가 뭐지?
	string fileName;
	int FindCarindex(const string &brand, const string &model) const;
};

bool SortCmp(Car &a, Car &b);

int getNumber();


#endif