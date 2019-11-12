
#include<iostream>//3.5
using namespace std;


void function(int* arr, int n , int &tot, int &gop)
{
	for (int i = 0; i < n; i++)
	{
		tot += arr[i];
		gop *= arr[i];
	}
}
int main()
{

	int tot=0;
	int gop=1;
	int arr[] = { 1,1,2,3,4,5,6,7,8,9 };


	function(arr, 10, tot, gop);
	printf("%d , %d" , tot, gop);
	getchar(); getchar();
}