#pragma warning(disable:4996)//3-1���ߴپƷ��Ͼ˴Ϥ���������������������������������
#include <stdio.h>
#include <string.h>
#include<windows.h>
#define capacity 20
int  check(char *token);
int main() {
	char arr[capacity] = { 0, }; //ip�Է�
	char *token;//�̾Ƴ� �ڸ�

	fgets(arr, capacity, stdin);
	arr[strlen(arr) - 1] = 0;//enter�� ���ش�
	if (strlen(arr) > 15)//���� �˻�
	{
		printf("NO");
		return -1;
	}

	token = strtok(arr, ".");
	if (!(check(token)))//ù�ܾ� üũ
	{
		printf("NO");
		return -1;
	}

	while ((token = strtok(NULL, ".")) != NULL)
	{
		if (!(check(token)))//�������ܾ� üũ
		{
			printf("NO");
			return -1;
		}
	}
	printf("yes");
	system("pause");
	return 0;
}
int  check(char *token)
{
	char words[4];
	int number = 0;

	if (strlen(token) > 3)
		return 0;

	strcpy(words, token);//ī��
	for (int i = 0; words[i] != 0; i++)
	{
		if (48 > words[i] && 57 < words[i])
			return 0;

		number *= 10;
		number += (words[i] - 48);

	}
	if (!(number >= 0 && number <= 255))
		return 0;

	return 1;
}