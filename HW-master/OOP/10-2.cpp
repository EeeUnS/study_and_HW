#include <iostream>//10-2
using namespace std;
template <typename T>

T Max(T *arr, int len)
{
        T max = arr[0];
        for (int i = 1; i < len; i++)
        {
               if (max < arr[i])
                       max = arr[i];
        }
        return max;
}

int main(void)
{
        int ary1[4] = { 4, 5, 2, 7 };
        double ary2[5] = { 1.1, 4.4, 8.8, 4.2, 5.5 };
        cout << Max(ary1, 4) << endl;
        cout << Max(ary2, 5) << endl;
        return 0;
}
