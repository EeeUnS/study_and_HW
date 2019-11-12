#include "class.hpp"


Car::Car(const string & brand, const string & model, const int price)
	:brand(brand), model(model), price(price)
{	}

const string & Car::GetBrand() const
{
	return brand;
}

const string & Car::GetModel() const
{
	return model;
}

int Car::GetPrice() const
{
	return price;
}

void Car::SetPrice(const int price)
{
	this->price = price;
}


CarManager::CarManager(const string & fileName)
	:fileName(fileName)
{
	try
	{
		fstream inputFile(fileName, fstream::in);

		if (inputFile.is_open() == false)
		{
			string error = "File Error";
			throw error;
		}
		
		while (!inputFile.eof())
		{
			string brand, model;
			int price;
			
			inputFile >> brand >> model >> price;
			carList.push_back(Car(brand, model, price));
		}

		inputFile.close();
	}
	catch (string exception)
	{
		cout << exception << endl;
		return;
	}
}

void CarManager::Menu()
{
	enum menu { printCarList = 1, findCarInfo = 2, changePrice = 3, sortCarList = 4, saveChanges = 5 };
	while (true)
	{
		int sel;
		cout << "Car Manager Menu" << endl;
		cout << "1. Print Car List" << endl;
		cout << "2. Find Car Info" << endl;
		cout << "3. Change Price" << endl;
		cout << "4. Sort Car List" << endl;
		cout << "5. Save Changes" << endl;
		cout << "Input : ";
		cin >> sel;

		string brand, model;
		int price;
		switch (sel)
		{
		case printCarList:
			cout << endl;
			PrintCarList();
			break;
		case findCarInfo:
			cout << "Brand : ";
			cin >> brand;
			cout << "Model : ";
			cin >> model;
			cout << endl;
			FindCarInfo(brand, model);
			break;
		case changePrice:
			cout << "Brand : ";
			cin >> brand;
			cout << "Model : ";
			cin >> model;
			cout << "Price : ";
			cin >> price;
			cout << endl;
			ChangePrice(brand, model, price);
			break;
		case sortCarList:
			SortCarList();
			break;
		case saveChanges:
			SaveChanges();
			break;
		default:
			cout << "Input Val Error" << endl;
			break;
		}
		cout << endl << endl;
	}
}

void CarManager::PrintCarList() const
{
	for (vector<Car>::const_iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		cout << itr->GetBrand() << " " << itr->GetModel() << " " << itr->GetPrice() << endl;
	}
}

void CarManager::FindCarInfo(const string & brand, const string & model) const
{
	bool isFind = false;
	for (vector<Car>::const_iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		if (itr->GetBrand() == brand && itr->GetModel() == model)
		{
			cout << itr->GetBrand() << " " << itr->GetModel() << " " << itr->GetPrice() << endl;
			isFind = true;
			break;
		}
	}
	if (isFind == false)
	{
		cout << "Can Not Find Car Info" << endl;
	}
}

void CarManager::ChangePrice(const string & brand, const string & model, const int price)
{
	bool isFind = false;
	for (vector<Car>::iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		if (itr->GetBrand() == brand && itr->GetModel() == model)
		{
			itr->SetPrice(price);
			isFind = true;
			cout << "Price Changed" << endl;
			break;
		}
	}
	if (isFind == false)
	{
		cout << "Can Not Find Car Info" << endl;
	}
}

void CarManager::SortCarList()
{
	sort(carList.begin(), carList.end(), SortCmp);
}

bool CarManager::SortCmp(const Car &car1, const Car &car2)
{
	if (car1.GetBrand() == car2.GetBrand())
	{
		return car1.GetModel() < car2.GetModel();
	}
	else
	{
		return car1.GetBrand() < car2.GetBrand();
	}
}

void CarManager::SaveChanges()
{
	fstream outputFile(fileName, fstream::out | fstream::trunc);

	for (vector<Car>::iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		outputFile << itr->GetBrand() << " " << itr->GetModel() << " " << itr->GetPrice();
	}

	outputFile.close();
}
