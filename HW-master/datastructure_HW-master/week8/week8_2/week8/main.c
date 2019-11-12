#include  <stdio.h>  //paren_checker.c
#include  <string.h>
#include  "stackADT.h"
#include <stdlib.h>
#define  MAX_LENGTH  100

char  OPEN[] = "([{";
char  CLOSE[] = ")]}";

int  is_open(char  ch);
int  is_close(char  ch);

void stackcount();

int  main()
{

	int number = 0;
	scanf_s("%d" , &number );
	getchar();
	for (int i = 0; i < number; i++)
	{
		stackcount();
		printf("\n");
	}
	
	system("pause");
	return 0;
}

void stackcount()
{
	char array[MAX_LENGTH] = { 0, };
	Stack arrays = create();
	int count = 0;
	fgets(array, MAX_LENGTH, stdin);
	int length = (int)strlen(array);
	for(int index = 0 ; index < length; index++)
	{
		
		if (is_open(array[index]) > -1)
		{
			Item a = { array[index] , ++count };
			push(arrays, a);
			printf("%d ", a.index);
		}
		else if (is_close(array[index]) > -1)
		{
			if (is_empty(arrays)) //비엇는지 먼저 검사 
			{
				printf("-1");  //맞지않는 유형의 형태가 나왔을때 무시한다.
			}
			else if( is_open(peek(arrays).data) != is_close(array[index]) ) //
			{
				printf("-1");  //맞지않는 유형의 형태가 나왔을때 무시한다.
			}
			else//is_open(peek(arrays).data) == is_close(array[index])
			{
				Item i = pop(arrays);
				printf("%d ", i.index); //먼저 나온숫자가 다시나온뒤에 감소
				//pop(arrays);
			}
			//index++;
		}
		else//if ((is_close(array[index]) == -1) && is_open(array[index]) == -1)
		{
		
		}
	}
	
}


int  is_close(char  ch)
{
	for (int i = 0; i < (int)strlen(CLOSE); i++)
	{
		if (CLOSE[i] == ch)return  i;
	}
	return  -1;
}
int  is_open(char  ch)
{
	for (int i = 0; i < (int)strlen(OPEN); i++)
		if (OPEN[i] == ch)
			return  i;
	return  -1;
}