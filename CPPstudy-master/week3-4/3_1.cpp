#include<iostream>

using namespace std;

void gugu(int a, int b);


int main()
{
    int a,b;
    cin >> a >> b;
    gugu(a,b);

    return 0;
}

void gugu(int a, int b)
{
    if(a<0)
    {
        cout << "Invalid input"<<endl;
        return ;
    }
    for(int i = 1 ; i<=a ; i++)
    {
        for(int j = 1; j<=b ;j++)
        {
            cout <<  i << " X " << j<< " = " <<i*j <<"   " ;

        }
        cout<<endl;
    }
}
