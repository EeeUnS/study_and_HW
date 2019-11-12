#include <iostream>

class CPoint//8-3
{
public:
	CPoint(int a = 0, int b = 0) : _x(a) ,_y(b)
	{}
	void Move(int a, int b) { _x += a; _y += b; }
	void Draw() { std::cout << _x << " " << _y << std::endl;  };

	int x(){ return _x; }
	int y() { return _y; }
private:
	int _x, _y;

};

class CCircle :public CPoint //7-10
{
public:
	CCircle(int x = 0, int y = 0 , double r = 0) : CPoint(x,y), _radius(r)
	{}
	double radius() { return _radius; }
	void GetArea() { std::cout << _radius * _radius*3.14 << std::endl; }
	void Draw() {   std::cout << x() << " " << y() <<" " << _radius <<std::endl; };

private:
	double _radius;
};

int main()
{
	CPoint a(1 , 2);
	CCircle b(2, 2, 3);
	a.Draw();
	a.Move(1, 2);
	a.Draw();
	b.Draw();
	b.Move(1, 2);
	b.Draw();
	b.GetArea();

	system("pause");
	return 0;
}
