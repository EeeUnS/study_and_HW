#include  <stdio.h>
#include<string.h>
#include <stdlib.h>
int floor(int *arr, int K, int n , int r)
{
	if (n == r)
		return *arr;
	if (*arr > K)
		return *(arr - 1);
	return floor(arr + 1, K ,n,r+1);
}

int celling(int *arr, int K, int n, int r)
{
	if (n == r && *arr < K)
		return -1;
	if (*arr >= K)
		return *(arr);
	return celling(arr + 1, K,n,r+1);
}

int main()
{
	int arr[9] = { 1,2,3,4,5,6,8,9,10 };
	int floorr = floor(arr, 7,9,0);
	int cellingg = celling(arr, 7,9,0);
	printf("%d %d", floorr, cellingg);
	system("pause");
	return 0;
}