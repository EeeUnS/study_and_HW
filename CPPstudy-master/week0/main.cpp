#include"class.hpp"
#include"common.hpp"

int main()
{
	Car **arrayTruck = new Car*[2];
	Car **arrayBus = new Car*[2];
	
	arrayTruck[0] = new Truck("hyundai", "porter", 1);
	arrayTruck[1] = new Truck("hyundai", "mighty", 2.5);
	arrayBus[0] = new Bus("kia", "grandbird", 45);
	arrayBus[1] = new Bus("hyundai", "universe", 45);

	arrayTruck[0]->Printinfo();
	arrayTruck[1]->Printinfo();
	arrayBus[0]->Printinfo();
	arrayBus[1]->Printinfo();

	cout << merge_brand_model<Car>(**arrayTruck)<<endl;
	cout << merge_brand_model<Car>(**arrayBus) << endl;
	cout << merge_brand_model<Car,Car>(**arrayBus, **arrayTruck) << endl;


	for (int i = 0; i < 2; i++)
	{
		delete arrayTruck[i];
		delete arrayBus[i];
	}
		delete []arrayTruck;
		delete[]arrayBus;
		system("pause");
	return 0;
}