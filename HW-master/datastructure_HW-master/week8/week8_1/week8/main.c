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
	for (int i = 0; i < number; i++) // �ݺ��Է¹��� Ƚ��
	{
		int subnumber = 0;
		fscanf(fp, "%d", &subnumber); // �� �Է¿� ���� ��������
		int sigmah = 0; //hi�����
		int maxindex = -1;//����� �ƽ��ε���
		int pre_record = 0; //
		// number�� max�ε������� Ŭ�� pre_record���ִ� �ε������� �������� �˻��Ѵ�.
		for (int r = 0; r < subnumber; r++)
		{
			int nnumber;
			fscanf(fp, "%d", &nnumber); //������ �Է�
			//printf("%d" , nnumber);
			int index;
			//���ε������ں��� Ŭ��쿡�� ������ h(i)�� �� �ε��� h������ ũ��.�׷���
			//���������� �˻��� �ε����� �������� (pre_index)������ ����Ѵ�.
			//������쿡�� �׳� ó������ ������ �������Ѵ�.
			if (( maxindex > -1  )&& (nnumber > array[maxindex])) 
			{
				index = pre_record - 1;
				sigmah +=(maxindex - pre_record +1);
			}
			else
				index = maxindex;

			array[++maxindex] = nnumber; // �Է¹��� ���� �ƽ��ε��� �ϳ��ø��� ����

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
		printf("%d\n", sigmah); //h(i)����� ���
	}
	fclose(fp);
	system("pause");
	return 0;
}