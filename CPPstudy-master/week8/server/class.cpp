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

void Car::Printinfo(ip::tcp::socket &socket) const
{
	boost::system::error_code error;
	string line = "Brand : " + this->brand + "모델명 : " + this->model ;
	socket.write_some(buffer(line, 80), error);
	Sleep(1);
}

Truck::Truck(const string &i_brand, const string &i_model, double i_weight)
	:Car(i_brand, i_model), weight(i_weight)
{}

Truck::~Truck() {}

void Truck::Printinfo(ip::tcp::socket &socket) const
{
	boost::system::error_code error;
	string line = "Brand : " + this->GetBrand() + "모델명 : " + this->GetModel() + "적재중량 : " + to_string(this->weight) ;
	socket.write_some(buffer(line, 80), error);
	Sleep(1);
}

Bus::Bus(const string &i_brand, const string &i_model, const int i_seat)
	:Car(i_brand, i_model), seat(i_seat)
{}
Bus::~Bus() {}

void Bus::Printinfo(ip::tcp::socket &socket) const
{
	boost::system::error_code error;
	string line = "Brand : " + this->GetBrand() + " 모델명 :  " + this->GetModel() + " 탑승인원 : " + to_string(this->seat) ;
	socket.write_some(buffer(line, 80), error);
	Sleep(1);
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

void CarManager::FindCarInfo(const string &brand, const string &model, ip::tcp::socket &socket) const
{
	boost::system::error_code error;
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		string line = "해당 브랜드, 모델이 리스트에 존재하지 않습니다.\n";
		socket.write_some(buffer(line, 80), error);
		return;
	}
	carList[i]->Printinfo(socket);
}

void CarManager::set(char sel, int id, ip::tcp::socket &socket)
{
	char brand[80] = { 0 };
	char model[80] = { 0 };
	boost::system::error_code error;
	string line;
	char number;
	switch (sel)
	{
	case printCarList:
		number = carList.size();
		socket.write_some(buffer(&number, 1), error);
		cout << "user" << to_string(id) << " call printCarList " << endl;
		PrintCarList(socket);
		break;
	case findCarInfo:
		cout << "user" << to_string(id) << " call findCarInfo" << endl;
		Sleep(1);
		socket.read_some(buffer(brand, 80), error);
		Sleep(1);
		socket.read_some(buffer(model, 80), error);
		FindCarInfo(brand, model, socket);
		break;
	case 3:
		exit(0);
	default:
		cout << "user" << to_string(id) << " Input Val Error" << endl;
		break;
	}
}

/* 여기가 문제  */
void CarManager::PrintCarList(ip::tcp::socket &socket)  const
{
	for (auto i : carList)
	{
		i->Printinfo(socket);
	}
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