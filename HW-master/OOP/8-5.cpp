#include <iostream>

using namespace std;

class CPointX {

protected :
	int x;
public:
	CPointX(int a) : x(a) { cout << "CPointX 持失切" << endl; }
	~CPointX() { cout << "CPointX 社瑚切" << endl; system("pause");
	}
	void Print( ) { cout << "CPointX" << endl; } 
};

class CPointXY : public CPointX
{
protected:
	int y;
public:
	CPointXY(int a, int b) : CPointX(a), y(b) { cout << "CPointXY 持失切" << endl; }
	~CPointXY() { cout << "CPointXY 社瑚切" << endl; system("pause");
	}
	void Print() { cout << "CPointXY" << endl; }
};

class CPointXZ : public CPointX
{
protected:
	int z;
public:
	CPointXZ(int a, int c) : CPointX(a), z(c) { cout << "CPointXZ 持失切" << endl; }
	~CPointXZ() { cout << "CPointXZ 社瑚切" << endl; system("pause");
	}
	void Print() { cout << "CPointXZ" << endl; }
};

class CPointXYZ : public CPointXY, public CPointXZ
{
protected:
	int xyz;
public:
	CPointXYZ(int a,int b, int c) : CPointXY(a ,b), CPointXZ(a,c) ,xyz(0) { cout << "CPointXYZ 持失切" << endl; }
	~CPointXYZ() { cout << "CPointXYZ 社瑚切 " << endl; system("pause");}
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
