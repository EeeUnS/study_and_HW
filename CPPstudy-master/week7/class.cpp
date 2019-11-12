#include"class.hpp"

Car::Car(const string &i_brand, const string &i_model)
	: brand(i_brand), model(i_model) {}

Car::~Car() {}

string Car::GetBrand() const
{
	return brand;
}

string Car::GetModel() const
{
	return model;
}

void Car::Printinfo() const
{
	cout << "브랜드명 : " << this->brand << "모델명 : " << this->model << endl;
}

Truck::Truck(const string &i_brand, const string &i_model, double i_weight)
	:Car(i_brand, i_model), weight(i_weight)
{}

Truck::~Truck() {}

void Truck::Printinfo() const
{
	cout << "브랜드명 : " << this->GetBrand() << "모델명 : " << this->GetModel() << "적재중량 : " << this->weight << endl;
}

Bus::Bus(const string &i_brand, const string &i_model, const int i_seat)
	:Car(i_brand, i_model), seat(i_seat)
{}
Bus::~Bus() {}

void Bus::Printinfo() const
{
	cout << "브랜드명 : " << this->GetBrand() << "모델명 : " << this->GetModel() << "탑승 인원 : " << this->seat << endl;
}


CarManager * CarManager::instance = nullptr;

CarManager* CarManager::getInstance(const string &Filename)
{
	if (instance == nullptr)
	{
		instance = new CarManager(Filename);
	}
	return instance;
}

CarManager::CarManager(const string &Filename) : fileName(Filename)
{
	try {
		ifstream in_file(Filename); // 예외처리

		if (in_file.fail())//파일없을때 true반환
		{
			throw fileName;
		}
		string i_model, i_brand;
		double item;
		string kind;

		while (!(in_file.eof())) //파일이 정상적인 경우에...
		{
			in_file >> kind;
			in_file >> i_brand;
			in_file >> i_model;
			in_file >> item;
			if (in_file.fail())
				throw fileName;
			else if (kind == "bus")
			{
				shared_ptr<Car> instance = make_shared<Bus>(i_brand, i_model, (int)item);
				carList.push_back(instance);
			}
			else //if(kind == "truck")
			{
				shared_ptr<Car> instance = make_shared<Truck>(i_brand, i_model, item);
				carList.push_back(instance);
			}
		}
		in_file.close();
	}
	catch (string Filename)
	{
		cout << " 파일 " << Filename << "이 존재하지 않거나 올바른 형식이 아닙니다.." << endl;
	}
}

CarManager::~CarManager()
{
	delete instance;
}

void CarManager::FindCarInfo(const string &brand, const string &model) const
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		cout << "해당 브랜드, 모델이 리스트에 존재하지 않습니다." << endl;
		return;
	}
	cout << "브랜드 : " << carList.at(i)->GetBrand() << "모델 : " << carList.at(i)->GetModel() << endl;
}

void CarManager::Menu() {
	enum menu {
		printCarList = 1,
		findCarInfo = 2,
		saveChanges = 3,
	};
	while (true) {
		int sel;
		cout << "Car Manager Menu" << endl;
		cout << "1. Print Car List" << endl;
		cout << "2. Find Car Info" << endl;
		cout << "3. exit" << endl;
		cout << "Input : ";

		sel = getNumber();

		string brand, model;
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
		case 3:
			exit(0);
		default:
			cout << "Input Val Error" << endl;
			break;
		}
		cout << endl << endl;
		cin.clear();
		sel = 0;
	}
}
/* 여기가 문제  */
void CarManager::PrintCarList()  const
{
	for (auto i : carList)
	{
		i->Printinfo();
	}
	//for_each(carList.begin(), carList.end(), Car::Printinfo);//?
}



int CarManager::FindCarindex(const string &brand, const string &model) const
{
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		if ((carList.at(i)->GetBrand() == brand) && (carList.at(i)->GetModel() == model))
			return i;
	}
	return -1;
}

int getNumber() { //긁어옴

	int retNum;

	cin >> retNum;

	// 잘못된 입력을 받았을 경우
	if (cin.fail()) {
		cout << "Input Val Error" << endl; // 에러 메시지 출력
		cin.clear(); // 오류스트림을 초기화
		cin.ignore(256, '\n'); // 입력버퍼를 비움
		return getNumber(); // 함수를 재호출한다
	}

	return retNum;
}
