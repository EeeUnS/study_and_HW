#include"class.hpp"

Car::Car(string i_brand, string i_model, int i_price) : brand(i_brand), model(i_model), price(i_price) {}

Car::~Car() {}

void Car::SetPrice(const int price) //���� �������� ����  setter �׷��� setter������?
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
		ifstream in_file(Filename); // ����ó��

		if (in_file.fail())//���Ͼ����� true��ȯ
		{
			throw fileName;
		}
		string i_model, i_brand;
		int i_price;
		while (!(in_file.eof())) //������ �������� ��쿡...
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
		cout << " ���� " << Filename << "�� �������� �ʰų� �ùٸ� ������ �ƴմϴ�.." << endl;
	}
}

CarManager::~CarManager()
{
}

void CarManager::ChangePrice(const string &brand, const string &model, const int price) //brand,model �� �ν��Ͻ�ã�Ƽ� ������
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		cout << "�ش� �귣��, ���� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	carList.at(i).SetPrice(price);

}

void CarManager::FindCarInfo(const string &brand, const string &model) const
{
	int i = FindCarindex(brand, model);
	if (i == -1)
	{
		cout << "�ش� �귣��, ���� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "�귣�� : " << carList.at(i).GetBrand() << "�� : " << carList.at(i).GetModel() << " ���� : " << carList.at(i).GetPrice() << endl;
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
		case changePrice:      // price �� aa �����ÿ� ���ѹݺ� ����
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
		cout << "�귣�� : " << carList.at(i).GetBrand() << "�� : " << carList.at(i).GetModel() << " ���� : " << carList.at(i).GetPrice() << endl;
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

int getNumber() { //�ܾ��

	int retNum;

	cin >> retNum;

	// �߸��� �Է��� �޾��� ���
	if (cin.fail()) {
		cout << "Input Val Error" << endl; // ���� �޽��� ���
		cin.clear(); // ������Ʈ���� �ʱ�ȭ
		cin.ignore(256, '\n'); // �Է¹��۸� ���
		return getNumber(); // �Լ��� ��ȣ���Ѵ�
	}

	return retNum;
}