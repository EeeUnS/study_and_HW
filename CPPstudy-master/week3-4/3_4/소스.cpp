//#include"class.hpp"
#include"class.h"


#include<string>

int main()
{
	linked_list<int> arrint(0);   // �ƹ� �μ��� �����ʰ� �����ҽÿ� arrint.add_back(i);�� �Ŀ� Ŭ���������� �־���Ѵٸ� ������ ��  ����
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
	char ���� �ƽ�Ű�������� �ν� ��
	�����Ư��ȭ�ؾ��� �����۵��� �� 
	��� ���Ҹ��������� �ò�����
	*/
	linked_list<string> arrstring("hey");
	arrstring.add_back("holy");
	arrstring.add_back("shit");
	arrstring.add_back("template");
	arrstring.add_back("class");
	arrstring.print_all();



	return 0;
}