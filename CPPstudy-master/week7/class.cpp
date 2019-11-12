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
	cout << "�귣��� : " << this->brand << "�𵨸� : " << this->model << endl;
}

Truck::Truck(const string &i_brand, const string &i_model, double i_weight)
	:Car(i_brand, i_model), weight(i_weight)
{}

Truck::~Truck() {}

void Truck::Printinfo() const
{
	cout << "�귣��� : " << this->GetBrand() << "�𵨸� : " << this->GetModel() << "�����߷� : " << this->weight << endl;
}

Bus::Bus(const string &i_brand, const string &i_model, const int i_seat)
	:Car(i_brand, i_model), seat(i_seat)
{}
Bus::~Bus() {}

void Bus::Printinfo() const
{
	cout << "�귣��� : " << this->GetBrand() << "�𵨸� : " << this->GetModel() << "ž�� �ο� : " << this->seat << endl;
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
		ifstream in_file(Filename); // ����ó��

		if (in_file.fail())//���Ͼ����� true��ȯ
		{
			throw fileName;
		}
		string i_model, i_brand;
		double item;
		string kind;

		while (!(in_file.eof())) //������ �������� ��쿡...
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
		cout << " ���� " << Filename << "�� �������� �ʰų� �ùٸ� ������ �ƴմϴ�.." << endl;
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
		cout << "�ش� �귣��, ���� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "�귣�� : " << carList.at(i)->GetBrand() << "�� : " << carList.at(i)->GetModel() << endl;
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
/* ���Ⱑ ����  */
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
