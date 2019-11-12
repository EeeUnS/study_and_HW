#include <iostream>

class CDate//8-4
{
public:
	CDate(int a, int b, int c) : _Year(a), _Month(b), _Day(c)
	{}
	void Print() { std::cout << _Year << " " << _Month << " " << _Day << std::endl;  }
	int Year() { return _Year; }
	int Month() { return _Month; }
	int Day() { return _Day; }
private:
	int _Year, _Month, _Day;
};

class CTime 
{
public:
	CTime(int d, int e, int f) : _Hour(d) ,_Minute(e) , _Second(f)
	{}
	void Print() { std::cout << _Hour << " " << _Minute << " " << _Second << std::endl; }
	int Hour() {return _Hour;}
	int Minute() { return _Minute; }
	int Second() { return _Second;	}
private:
	int _Hour, _Minute, _Second;
};

class CDateTime : public CDate, CTime
{
public:
	CDateTime(int a, int b,int c, int d, int e,int f ,const char *arr ):CDate(a,b,c) 
		,CTime(d,e,f) 
	{ _ToDo = _strdup( arr); }
	void Print() { 
		std::cout << Year()<<" "<<Month()<<" "<< Day() << std::endl;
		std::cout << Hour() << " " << Minute() << " " << Second() << std::endl;
		std::cout << _ToDo << std::endl; }
	~CDateTime()
	{
		free(_ToDo);
		std::cout << "소멸자 " << std::endl;

		system("pause");


	}
private:
	char *_ToDo;
};

int main()
{
	CDateTime a(1,2,3,4,5,6, "Happy");
	a.Print();
	system("pause");

	return 0;
}
