#pragma warning(disable:4996)//3-1다했다아럼니알니ㅏㅇ리ㅏㄴㅁㅇ리ㅏㄴㅁㅇ리ㅏㄴㅇㄹ
#include <stdio.h>
#include <string.h>
#include<windows.h>
#include <stdlib.h>
#define capacity 100
//여기까지
int main() {
	//255_asdfasdf.12.024.54를 입력할시 yes라고나옴 이걸 고쳐야한다.
	char arr[capacity] = { 0, };
	char *token;
	//fgets(arr, capacity, stdin);
	gets(arr);
	int count = 1;//처음0일때는 세지않고 셋다고 가정
	int number;//atoi수 저장
	int n = 0; //atoi자리수 확인
	int length;
	length = strlen(arr);
	if (strlen(arr) > 16)
	{
		printf("no");
		return -1;
	}
	token = strtok(arr, ".");
	//맨첫단어
	if ((atoi(token) >= 0 && atoi(token) <= 255))
	{
		number = atoi(token); // 0일때는?
		if (atoi(token) == 0 && strlen(token) == 1)//0일때 예외문
		{
		}
		else {
			while (number != 0)
			{
				number /= 10;
				n++;
			}


			if (strlen(token) != n)
			{
				printf("no");
				return -1;
			}
		}
	}
	else {
		printf("no");
		return -1;
	}
	//뒷토큰
	while ((token = strtok(null, ".")) != null)
	{
		n = 0;
		if (atoi(token) >= 0 && atoi(token) <= 255)
		{

			number = atoi(token); // 0일때는?
			if (atoi(token) == 0 && strlen(token) == 1)//0일때 예외문
			{
				count++;
				continue;
			}
			while (number != 0)
			{
				number /= 10;
				n++;
			}


			if (strlen(token) != n)
			{
				printf("no");
				return -1;
			}

			count++;
			continue;
		}
		else
		{
			printf("no");
			return -1;
		}
	}
	if (count == 4) {
		printf("yes");
	}
	else {
		printf("no");
	}
	system("pause");
	return 0;
}
