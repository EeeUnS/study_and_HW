#include<iostream>//7.5

class  CArray
{

private:
	int arr[5];

public:
	CArray()
	{
		for (int i = 0; i < 5; i++)
		{
			arr[i] = i;
		}
	}

	//	~ CArray();

	void Print();
	friend CArray operator+(const CArray &arr1);
};

void CArray::Print()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

}
CArray operator+(const CArray &arr1)
{
	CArray arr2;
	for (int i = 0; i < 5; i++)
	{
		arr2.arr[i] = arr1.arr[i] + 1;
	}
	return arr2;
}


int main()
{
	CArray arr;
	arr.Print();
	CArray arr2 = +arr;

	arr2.Print();
	system("pause");
	return 0;
}

