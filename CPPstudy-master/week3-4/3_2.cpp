#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> arr;
    for(int i=1; i <= 10; i++)
    {
        arr.push_back(i);
    }
    for(unsigned int i=0; i < arr.size() ; i++)
    {
        cout << arr[i] <<endl;
    }

    cout << endl;
    arr.pop_back();

    for(vector<int>::iterator itr = arr.begin() ; itr != arr.end() ; itr++)
    {
        cout << *itr << endl;
    }

    arr.clear();
    return 0;
}
