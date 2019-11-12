#include <iostream>
#pragma warning(disable:4996)
using namespace std;
class CString
{
	char *pStr;
	int len;

public:
	CString(const char *str)
	{
		len = strlen(str);
		pStr = new char[len + 1];
		strcpy(pStr, str);
		cout << "CSting 생성자 " << endl;
	}

	~CString()
	{
		delete[]pStr; cout << "CSting 소멸자 " << endl;
	}
};

class CMyString : public CString
{
	char *pMyStr;
	int MyLen;
public:
	CMyString(const char *str1,const char *str2) :CString(str1)
	{
		MyLen = strlen(str2);
		pMyStr = new char[MyLen + 1];
		strcpy(pMyStr, str2);
		cout << "CMySting 생성자 " << endl;
	}

	~CMyString()
	{
		delete[]pMyStr; cout << "CMySting 소멸자" << endl;
	}
};

int main()
{
	CString *pStr = new CMyString("CString", "Cmystring");
	delete pStr;

}
