
#pragma warning (disable: 4996) 
#include<iostream> //4-4
#include<cstring>
using namespace std;

class CStudent
{
private:


public:
	char name[20];
	int number;
	int age;
	CStudent()
	{
		strcpy(name, "nonname");
		number = 0;
		age = 0;
	}
	CStudent(const char name1[], int a, int b)
	{
		strcpy(name, name1);
		number = a;
		age = b;
	}
	void Print()
	{
		cout << "�̸� : "<< name << endl;
		cout << "�й� : " << number << endl;
		cout << "���� : " << age << endl;
	}
	void SetName(const char *name1)
	{
		strcpy(name, name1);

	}

	void SetNumber(int a)
	{
		number = a;
	}
	void SetAge(int b)
	{
		age = b;
	}
};

int main()
{
	CStudent St1("ȫ�浿", 11111111, 25);
	CStudent St2;
	St1.Print();
	St2.Print();

	St2.SetName("�̼���");
	St2.SetNumber(22222222);
	St2.SetAge(30);

	St2.Print();

	getchar(); getchar();
}