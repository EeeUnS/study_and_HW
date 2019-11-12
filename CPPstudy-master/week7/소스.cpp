#include"class.hpp"

int main()
{
	CarManager *carManager = CarManager::getInstance("CarListFile.txt");
	carManager->Menu();
}