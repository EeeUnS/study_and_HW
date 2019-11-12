#include  <stdio.h>  //paren_checker.c
//#include  <string.h>
//#include  "stackADT.h"
#include <stdlib.h>
#pragma warning (disable: 4996)
//#define  MAX_LENGTH  100

int array[1100000] = { 0, };

int  main()
{
	int number = 0;
	FILE *fp = fopen("input08_01.txt", "r");
	fscanf(fp, "%d", &number);
	for (int i = 0; i < number; i++) // 반복입력받을 횟수
	{
		int subnumber = 0;
		fscanf(fp, "%d", &subnumber); // 한 입력에 받을 정수갯수
		int sigmah = 0; //hi모든합
		int maxindex = -1;//저장된 맥스인덱스
		int pre_record = 0; //
		// number가 max인덱스보다 클시 pre_record에있는 인덱스부터 왼쪽으로 검사한다.
		for (int r = 0; r < subnumber; r++)
		{
			int nnumber;
			fscanf(fp, "%d", &nnumber); //한정수 입력
			//printf("%d" , nnumber);
			int index;
			//앞인덱스숫자보다 클경우에는 무조건 h(i)는 앞 인덱스 h값보다 크다.그러니
			//마지막에서 검사한 인덱스를 저장한후 (pre_index)가져와 사용한다.
			//작을경우에는 그냥 처음부터 일일이 세도록한다.
			if (( maxindex > -1  )&& (nnumber > array[maxindex])) 
			{
				index = pre_record - 1;
				sigmah +=(maxindex - pre_record +1);
			}
			else
				index = maxindex;

			array[++maxindex] = nnumber; // 입력받은 정수 맥스인덱스 하나늘리고 저장

			for ( ; index >= 0 && array[index] <= nnumber; index--)// hi count
			{
				sigmah++;
				
			}
			//memset(array,0,maxindex);
			//	if ((r % 100000) == 0)
			//	printf("%d\n", sigmah);
			sigmah %= 1000000;
			pre_record = index+1;
		}
		printf("%d\n", sigmah); //h(i)모든합 출력
	}
	fclose(fp);
	system("pause");
	return 0;
}