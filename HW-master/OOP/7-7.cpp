#include <iostream>

class CPoint //7-7
{
public:

   CPoint& operator++();
   CPoint operator++(int);


   CPoint& operator--();
   CPoint operator--(int);


   CPoint() { _x = _y = 0; }


   int x() { return _x; }
   int y() { return _y; }
   void Print();
private:
   int _x, _y;
};


CPoint& CPoint::operator++()
{
   _x++;
   _y++;
   return *this;
}

void CPoint::Print()
{
    std::cout << _x<<" " <<_y  <<std::endl ;
}

CPoint CPoint::operator++(int)
{
   CPoint temp = *this;
   ++*this;
   return temp;
}

CPoint& CPoint::operator--()
{
   _x--;
   _y--;
   return *this;
}

CPoint CPoint::operator--(int)
{
   Point temp = *this;
   --*this;
   return temp;
}

int main()
{
    CPoint arr;
    arr.Print();
    (++arr)++;

    arr.Print();

    return 0;
}

