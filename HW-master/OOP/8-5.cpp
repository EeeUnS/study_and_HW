#include <iostream>

using namespace std;

class CPointX {

protected :
	int x;
public:
	CPointX(int a) : x(a) { cout << "CPointX ������" << endl; }
	~CPointX() { cout << "CPointX �Ҹ���" << endl; system("pause");
	}
	void Print( ) { cout << "CPointX" << endl; } 
};

class CPointXY : public CPointX
{
protected:
	int y;
public:
	CPointXY(int a, int b) : CPointX(a), y(b) { cout << "CPointXY ������" << endl; }
	~CPointXY() { cout << "CPointXY �Ҹ���" << endl; system("pause");
	}
	void Print() { cout << "CPointXY" << endl; }
};

class CPointXZ : public CPointX
{
protected:
	int z;
public:
	CPointXZ(int a, int c) : CPointX(a), z(c) { cout << "CPointXZ ������" << endl; }
	~CPointXZ() { cout << "CPointXZ �Ҹ���" << endl; system("pause");
	}
	void Print() { cout << "CPointXZ" << endl; }
};

class CPointXYZ : public CPointXY, public CPointXZ
{
protected:
	int xyz;
public:
	CPointXYZ(int a,int b, int c) : CPointXY(a ,b), CPointXZ(a,c) ,xyz(0) { cout << "CPointXYZ ������" << endl; }
	~CPointXYZ() { cout << "CPointXYZ �Ҹ��� " << endl; system("pause");}
	void Print() { 
		CPointX::Print();
		CPointXY::Print();
		CPointXZ::Print();		
		cout << "CPointXYZ" << endl; }
};

int main()
{
	CPointXYZ Pxyz(1, 2, 3);
	Pxyz.Print();

	system("pause");

	return 0;
	system("pause");
}
