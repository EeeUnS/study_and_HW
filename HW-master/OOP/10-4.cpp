#include <iostream> //10-4

using namespace std;

template <typename T1, typename T2>
class CArray
{
private:
	T1 arr1[10]; //각각의 자료형에 대한 배열 선언
	T2 arr2[10];
	int len; //배열 길이
public:
	CArray() :len(0){}
	void Put(T1 a, T2 b)
	{
		arr1[len] = a;
		arr2[len] = b;
		len++;
	}
	template <typename T1, typename T2>
	friend ostream &operator<<(ostream &out, CArray<T1, T2> &Copy);
};

template <typename T1, typename T2>
ostream &operator<<(ostream &out, CArray<T1, T2> &Copy)
{
	for (int i = 0; i < Copy.len; i++)
	{
		out << "(" << Copy.arr1[i] << ", " << Copy.arr2[i] << ")" << endl;
	}
	return out;
}

int main(void)
{
	CArray<int, char> Obj;
	Obj.Put(1, 'a');
	cout << Obj;
	system("pause");
	return 0;

}

