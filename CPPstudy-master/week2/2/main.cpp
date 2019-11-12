#include"class.hpp"



#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <stdlib.h> 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	linked_list car("huyndai");
	car.add_back("kia");
	car.add_back("alex");
	car.print_all();
	cout << endl;
	car.insert(1, "asdf");
	car.print_all();
	cout << endl; 
	car.remove("alex");
	
	car.print_all();
	system("pause");
	return  0;
}