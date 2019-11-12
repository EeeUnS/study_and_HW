#include <iostream>
#pragma warning(disable:4996)

class CString
{
	int len;
	char *str;
public:
	CString(const char *s = "unkown")
	{
		len = strlen(s);
		str = new char[len + 1]	;
		strcpy(str ,s );
	}
	~CString() { delete[]str; }
	void Print() { std::cout << str << std::endl; }

};


CString *GetString()
{
	CString *str = new CString("Current STring");
	return str;
}


int main()
{


	CString *str1 = GetString();
	str1->Print();
}