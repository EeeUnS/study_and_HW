#include"class.hpp"

Car::Car(const std::string& i_brand, const std::string& i_model)
	: brand(i_brand), model(i_model) {}

Car::~Car() {}

std::string Car::GetBrand() const
{
	return brand;
}

std::string Car::GetModel() const
{
	return model;
}

void Car::Printinfo(boost::asio::ip::tcp::socket& socket) const
{
	boost::system::error_code error;
	std::string line = "Brand : " + this->brand + "모델명 : " + this->model;
	socket.write_some(boost::asio::buffer(line, 80), error);
	Sleep(1);
}

Truck::Truck(const std::string& i_brand, const std::string& i_model, double i_weight)
	:Car(i_brand, i_model), weight(i_weight)
{}

Truck::~Truck() {}

void Truck::Printinfo(boost::asio::ip::tcp::socket& socket) const
{
	boost::system::error_code error;
	std::string line = "Brand : " + this->GetBrand() + "모델명 : " + this->GetModel() + " 적재중량 : " + std::to_string(this->weight);
	socket.write_some(boost::asio::buffer(line, 80), error);
	Sleep(1);
}

Bus::Bus(const std::string& i_brand, const std::string& i_model, std::size_t i_seat)
	:Car(i_brand, i_model), seat(i_seat)
{}
Bus::~Bus() {}

void Bus::Printinfo(boost::asio::ip::tcp::socket& socket) const
{
	boost::system::error_code error;
	std::string line = "Brand : " + this->GetBrand() + " 모델명 :  " + this->GetModel() + " 탑승인원 : " +  std::to_string(this->seat);
	socket.write_some(boost::asio::buffer(line, 80), error);
	Sleep(1);
}


CarManager* CarManager::instance = nullptr;

CarManager* CarManager::getInstance(const std::string& Filename)
{
	if (instance == nullptr)
	{
		instance = new CarManager(Filename);
	}
	return instance;
}

CarManager::CarManager(const std::string& Filename) : fileName(Filename)
{
	try {
		std::ifstream in_file(Filename); // 예외처리

		if (in_file.fail())//파일없을때 true반환
		{
			throw fileName;
		}
		std::string i_model, i_brand;
		double item;
		std::string kind;

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
				std::shared_ptr<Car> instance = std::make_shared<Bus>(i_brand, i_model, (int)item);
				carList.push_back(instance);
			}
			else //if(kind == "truck")
			{
				std::shared_ptr<Car> instance = std::make_shared<Truck>(i_brand, i_model, item);
				carList.push_back(instance);
			}
		}
		in_file.close();
	}
	catch (std::string Filename)
	{
		std::cout << " 파일 " << Filename << "이 존재하지 않거나 올바른 형식이 아닙니다.." << std::endl;
	}
}

CarManager::~CarManager()
{
	delete instance;
}

void CarManager::FindCarInfo(const std::string& brand, const std::string& model, boost::asio::ip::tcp::socket& socket) const
{
	boost::system::error_code error;
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		std::string line = "해당 브랜드, 모델이 리스트에 존재하지 않습니다.\n";
		socket.write_some(boost::asio::buffer(line, 80), error);
		return;
	}
	carList[i]->Printinfo(socket);
}

void CarManager::set(char sel, std::size_t id, boost::asio::ip::tcp::socket& socket)
{
	char brand[80] = { 0 };
	char model[80] = { 0 };
	boost::system::error_code error;
	std::string line;
	unsigned char number;
	switch (sel)
	{
	case static_cast<int>(menu::printCarList):
		number = static_cast<char>(carList.size());
		socket.write_some(boost::asio::buffer(&number, 1), error);
		std::cout << "user" << std::to_string(id) << " call printCarList " << std::endl;
		PrintCarList(socket);
		break;
	case static_cast<int>(menu::findCarInfo):
		std::cout << "user" << std::to_string(id) << " call findCarInfo" << std::endl;
		Sleep(1);
		socket.read_some(boost::asio::buffer(brand, 80), error);
		Sleep(1);
		socket.read_some(boost::asio::buffer(model, 80), error);
		FindCarInfo(brand, model, socket);
		break;
	case 3:
		std::cout << "user" << std::to_string(id) << " call exit" << std::endl;
		//exit(0);
		break;
	default:
		std::cout << "user" << std::to_string(id) << " Input Val Error" << std::endl;
		break;
	}
}

/* 여기가 문제  */
void CarManager::PrintCarList(boost::asio::ip::tcp::socket& socket)  const
{
	for (auto i : carList)
	{
		i->Printinfo(socket);
	}
}

int CarManager::FindCarindex(const std::string& brand, const std::string& model) const
{
	std::size_t n = carList.size();
	for (int i = 0; i < n; i++)
	{
		if ((carList.at(i)->GetBrand() == brand) && (carList.at(i)->GetModel() == model))
			return i;
	}
	return -1;
}