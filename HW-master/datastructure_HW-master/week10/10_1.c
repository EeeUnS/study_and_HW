#include  <stdio.h>
#include<string.h>

int delom(char *array, int start, int end )
{
    if(start>end)
        return 1;
    else if(array[start] == array[end] )
        return delom(array, start+1,end-1);
    else
        return -1;
}


int main()
{
    FILE  *fp1 = fopen("hurry.txt", "r");
    char arr[40];
    int a= delom(arr, 0, strlen(arr)-1);
    if (fp1 == NULL)
    {
        puts("���Ͼȿ���");
        return 0;
    }

    int n = -1;
    while (fscanf(fp1, "%s",arr) != EOF )
    {
        int a= delom(arr, 0, strlen(arr)-1);
        switch(a)
        {
        case 1:
            printf("ȸ���Դϴ�.\n");
            break;
        case -1:
            printf("ȸ���� �ƴմϴ�.\n");
            break;
        default:
            break;
        }


    }
    fclose(fp1);

    return 0;
}
