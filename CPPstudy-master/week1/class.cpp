#include"class.hpp"

Car::Car(const std::string i_brand, const  std::string i_model, int i_price) : brand(i_brand), model(i_model), price(i_price) {}

Car::~Car() {}

void Car::SetPrice(const int price) //가격 재지정을 위한  setter 그래서 setter가뭔데?
{
	this->price = price;
}


int Car::GetPrice() const
{
	return price;
}
std::string Car::GetBrand() const
{
	return brand;
}

std::string Car::GetModel() const
{
	return model;
}


CarManager::CarManager(const std::string &Filename) : fileName(Filename)
{
	try {
		std::ifstream in_file(Filename); // 예외처리

		if (in_file.fail())//파일없을때 true반환
		{
			throw fileName;
		}
		std::string i_model, i_brand;
		int i_price;
		while (!(in_file.eof())) //파일이 정상적인 경우에...
		{
			in_file >> i_brand;
			in_file >> i_model;
			in_file >> i_price;
			if (in_file.fail())
				throw fileName;
			else
				carList.push_back(Car(i_brand, i_model, i_price));
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
}

void CarManager::ChangePrice(const std::string &brand, const std::string &model, const int price) //brand,model 로 인스턴스찾아서 값변경
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		std::cout << "해당 브랜드, 모델이 리스트에 존재하지 않습니다." << std::endl;
		return;
	}
	carList.at(i).SetPrice(price);

}

void CarManager::FindCarInfo(const std::string &brand, const std::string &model) const
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		std::cout << "해당 브랜드, 모델이 리스트에 존재하지 않습니다." << std::endl;
		return;
	}
	std::cout << "브랜드 : " << carList.at(i).GetBrand() << "모델 : " << carList.at(i).GetModel() << " 가격 : " << carList.at(i).GetPrice() << std::endl;
}

void CarManager::Menu()  {
	enum menu {
		printCarList = 1, 
		findCarInfo = 2,
		changePrice = 3, 
		sortCarList = 4, 
		saveChanges = 5 ,
	};
	while (true) {
		int sel;
		std::cout << "Car Manager Menu" << std::endl;
		std::cout << "1. Print Car List" << std::endl;
		std::cout << "2. Find Car Info" << std::endl;
		std::cout << "3. Change Price" << std::endl;
		std::cout << "4. Sort Car List" << std::endl;
		std::cout << "5. Save Changes" << std::endl;
		std::cout << "6. exit" << std::endl;
		std::cout << "Input : ";

		sel = getNumber();

		std::string brand, model;
		int price;
		switch (sel)
		{
		case printCarList:
			std::cout << std::endl;
			PrintCarList();
			break;
		case findCarInfo:
			std::cout << "Brand : ";
			std::cin >> brand;
			std::cout << "Model : ";
			std::cin >> model;
			std::cout << std::endl;
			FindCarInfo(brand, model);
			break;
		case changePrice:      // price 에 aa 넣을시에 무한반복 에러
			std::cout << "Brand : ";
			std::cin >> brand;
			std::cout << "Model : ";
			std::cin >> model;
			std::cout << "Price : ";
			price = getNumber();
			std::cout << std::endl;
			ChangePrice(brand, model, price);
			break;
		case sortCarList:
			SortCarList();
			break;
		case saveChanges:
			SaveChanges();
			break;
		case 6:
			exit(0);
		default:
			std::cout << "Input Val Error" << std::endl;
			break;
		}
		std::cout << std::endl << std::endl;
		std::cin.clear();
		sel = 0;
	}
}

void CarManager::PrintCarList()  const
{
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		std::cout << "브랜드 : " << carList.at(i).GetBrand() << "모델 : " << carList.at(i).GetModel() << " 가격 : " << carList.at(i).GetPrice() << std::endl;
	}
}

void CarManager::SaveChanges() const
{
	std::ofstream out_file(fileName);
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		out_file << carList.at(i).GetBrand() << " ";;
		out_file << carList.at(i).GetModel() << " ";
		out_file << carList.at(i).GetPrice() << std::endl;
	}
	out_file.close();
}


void CarManager::SortCarList()
{
	std::sort(carList.begin(), carList.end(), SortCmp);
}

bool SortCmp(const Car &a,const Car &b)
{
	if(a.GetBrand() == b.GetBrand())
		return a.GetModel() < b.GetModel();
	return a.GetBrand() < b.GetBrand();
}



int CarManager::FindCarindex(const std::string &brand, const std::string &model) const
{
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		if ((carList.at(i).GetBrand() == brand) && (carList.at(i).GetModel() == model))
			return i;
	}
	return -1;
}

int getNumber() { //긁어옴

	int retNum;

	std::cin >> retNum;

	// 잘못된 입력을 받았을 경우
	if (std::cin.fail()) {
		std::cout << "Input Val Error" << std::endl; // 에러 메시지 출력
		std::cin.clear(); // 오류스트림을 초기화
		std::cin.ignore(256, '\n'); // 입력버퍼를 비움
		return getNumber(); // 함수를 재호출한다
	}

	return retNum;
}