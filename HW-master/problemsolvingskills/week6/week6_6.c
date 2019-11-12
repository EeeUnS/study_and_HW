#include "stdio.h"
#include"stdlib.h"
#include"time.h"
#define MAX 100

int main()
{
    int num = 0;
    int arr[MAX] = { 0 };
    int brr[MAX] = { 0 };
    int count = 0;
    printf("입력할수: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("인덱스 %d에서의  값", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < num ; i++)
    {

        int k = i;
        if (brr[k] == -1)
            continue;
        for (int j = 0; j <= num; j++)
        {
            brr[k] = -1;
            if (i == arr[k])
            {
                count ++ ;
                break;
            }
            k = arr[k];
        }


    }

    printf("%d", count);
    getchar();
    getchar();
    system("pause");
    return 0;
}
