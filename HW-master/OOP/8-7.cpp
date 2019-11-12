#include <iostream>


class CPoint //8-7
{
    private:
	int _x, _y;
	CPoint(int a , int b): _x(a) , _y(b) {}
	 static CPoint *OnlyPoint;

public:
    void Print(){ std::cout<< _x <<" "<< _y <<std::endl ; }
	int x() { return _x; }
	int y() { return _y; }
      static CPoint GetPoint(int a, int b)
        {
               if (OnlyPoint != NULL)
               {
                       delete OnlyPoint; //존재할경우 delete를 해야한다
                       OnlyPoint = new CPoint(a, b);
               }
               else
                       OnlyPoint = new CPoint(a, b);
               return *OnlyPoint;
        }

};
CPoint *CPoint::OnlyPoint = NULL;

int main()
{
    CPoint P1 = CPoint::GetPoint(1,2);
    CPoint P2 = CPoint::GetPoint(3,4);
    P1.Print();
    P2.Print();
	return 0;
}
