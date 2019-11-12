#include "common.hpp"
#include "class.hpp"

using namespace std;

int main()
{
	CarManager carManager("CarListFile.txt");
	carManager.Menu();
}
