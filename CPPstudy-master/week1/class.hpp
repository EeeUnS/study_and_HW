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
	void SetPrice(const int price); //���� �������� ����  setter �׷��� setter������?
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
	void ChangePrice(const string &brand, const string &model,const int price) ; //brand,model �� �ν��Ͻ�ã�Ƽ� ������
	void FindCarInfo(const string &brand, const string &model) const;
	void Menu()  ;
	void PrintCarList() const;
	void SaveChanges() const;
	void SortCarList(); //�귣��-model ������ �����Ұ�
private:
	vector<Car> carList;  //ī�� �ν��Ͻ��� ������ ����		�ν��Ͻ��� ����?
	string fileName;
	int FindCarindex(const string &brand, const string &model) const;
};

bool SortCmp(Car &a, Car &b);

int getNumber();


#endif