#include  <stdio.h>
#include<string.h>

int tup_sum(int *arr, int start, int end, int k)
{
    if (start >end)
        return 0;
    int sum = *(arr+start) + *(arr+end);

    if(sum > k)
        return tup_sum(arr, start,  end-1,  k);
    else if (sum < k)
         return tup_sum(arr, start+1,  end,  k);
    else
       return 1 + tup_sum(arr, start+1,  end-1,  k);
}

int main()
{
  	int arr[10] = {1,2,3,4,5,6,7,8,9,10} ;

  	printf("%d", tup_sum(arr,0 , 9 , 13));
    return 0;
}
