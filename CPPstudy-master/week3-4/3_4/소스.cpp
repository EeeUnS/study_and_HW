//#include"class.hpp"
#include"class.h"


#include<string>

int main()
{
	linked_list<int> arrint(0);   // 아무 인수도 넣지않고 생성할시에 arrint.add_back(i);에 식에 클래스형식이 있어야한다며 에러가 뜸  슈발
	for (int i = 0; i < 10; i++)
	{
		arrint.add_back(i);
	}
	arrint.print_all();

	linked_list<double> arrdouble(0);
	for (double i = 0; i < 10; i++)
	{
		arrdouble.add_back(i);
	}
	arrdouble.print_all();
	linked_list<char> arrchar(0);
	for (char i = 0; i < 10; i++)
	{
		arrchar.add_back(i);
	}
	//arrchar.print_all();  //
	/*
	char 형이 아스키형식으로 인식 함
	명시적특수화해야함 정상작동은 함 
	계속 경고소리내보내서 시끄러움
	*/
	linked_list<string> arrstring("hey");
	arrstring.add_back("holy");
	arrstring.add_back("shit");
	arrstring.add_back("template");
	arrstring.add_back("class");
	arrstring.print_all();



	return 0;
}