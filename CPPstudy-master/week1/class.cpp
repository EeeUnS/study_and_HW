#include"class.hpp"

Car::Car(string i_brand, string i_model, int i_price) : brand(i_brand), model(i_model), price(i_price) {}

Car::~Car() {}

void Car::SetPrice(const int price) //가격 재지정을 위한  setter 그래서 setter가뭔데?
{
	this->price = price;
}


int Car::GetPrice() const
{
	return price;
}
string Car::GetBrand() const
{
	return brand;
}

string Car::GetModel() const
{
	return model;
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
	catch (string Filename)
	{
		cout << " 파일 " << Filename << "이 존재하지 않거나 올바른 형식이 아닙니다.." << endl;
	}
}

CarManager::~CarManager()
{
}

void CarManager::ChangePrice(const string &brand, const string &model, const int price) //brand,model 로 인스턴스찾아서 값변경
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		cout << "해당 브랜드, 모델이 리스트에 존재하지 않습니다." << endl;
		return;
	}
	carList.at(i).SetPrice(price);

}

void CarManager::FindCarInfo(const string &brand, const string &model) const
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		cout << "해당 브랜드, 모델이 리스트에 존재하지 않습니다." << endl;
		return;
	}
	cout << "브랜드 : " << carList.at(i).GetBrand() << "모델 : " << carList.at(i).GetModel() << " 가격 : " << carList.at(i).GetPrice() << endl;
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
		cout << "Car Manager Menu" << endl;
		cout << "1. Print Car List" << endl;
		cout << "2. Find Car Info" << endl;
		cout << "3. Change Price" << endl;
		cout << "4. Sort Car List" << endl;
		cout << "5. Save Changes" << endl;
		cout << "6. exit" << endl;
		cout << "Input : ";

		sel = getNumber();

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
		case changePrice:      // price 에 aa 넣을시에 무한반복 에러
			cout << "Brand : ";
			cin >> brand;
			cout << "Model : ";
			cin >> model;
			cout << "Price : ";
			price = getNumber();
			cout << endl;
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
			cout << "Input Val Error" << endl;
			break;
		}
		cout << endl << endl;
		cin.clear();
		sel = 0;
	}
}

void CarManager::PrintCarList()  const
{
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		cout << "브랜드 : " << carList.at(i).GetBrand() << "모델 : " << carList.at(i).GetModel() << " 가격 : " << carList.at(i).GetPrice() << endl;
	}
}

void CarManager::SaveChanges() const
{
	ofstream out_file(fileName);
	int n = carList.size();
	for (int i = 0; i < n; i++)
	{
		out_file << carList.at(i).GetBrand() << " ";;
		out_file << carList.at(i).GetModel() << " ";
		out_file << carList.at(i).GetPrice() << endl;
	}
	out_file.close();
}


void CarManager::SortCarList()
{
	sort(carList.begin(), carList.end(), SortCmp);
}

bool SortCmp(Car &a, Car &b)
{
	if(a.GetBrand() == b.GetBrand())
		return a.GetModel() < b.GetModel();
	return a.GetBrand() < b.GetBrand();
}



int CarManager::FindCarindex(const string &brand, const string &model) const
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