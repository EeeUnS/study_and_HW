#include "common.hpp"
#include "class.hpp"

using namespace std;

int main()
{
	vector<Car*> carList; //������ ����
	carList.push_back(new Bus("hyundai", "universe", 45));
	carList.push_back(new Bus("kia", "granbird", 45));
	carList.push_back(new Truck("hyundai", "porter", 1));
	carList.push_back(new Truck("hyundai", "mighty", 2.5));

	for (vector<Car*>::iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		(*itr)->PrintInfo();
	}
	cout << endl;

	//���ø� �Լ� �׽�Ʈ
	string name1 = MergeName(carList[0]);
	string name2 = MergeName(dynamic_cast<Truck*>(carList[2]));
	cout << name1 << endl;
	cout << name2 << endl;
	cout << endl;

	string name3 = MergeName(dynamic_cast<Bus*>(carList[1]), carList[3]);
	cout << name3 << endl;

	//�ڿ� ����
	for (vector<Car*>::iterator itr = carList.begin(); itr != carList.end(); itr++)
	{
		delete (*itr);
	}
	carList.clear();
	//system("pause");
}
