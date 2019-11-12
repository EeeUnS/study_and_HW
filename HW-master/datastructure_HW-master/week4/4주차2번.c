#pragma warning (disable: 4996)//4-2 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define capacity 100 
#define buffer_length 100 
#define MAX 100 

typedef struct term {   // �ϳ��� ���� ǥ���ϴ� ����ü         
	int coef;    // ��� 
	int expo;    // ����     
} term;

typedef struct polynomial {  // �ϳ��� ���׽��� ǥ���ϱ� ���� ����ü 
	char name;    // f, g, h���� ���׽��� �̸�     
	int nbr_terms;   // �� ���׽��� �����ϴ� ���� ����  
	term *terms[MAX];  // MAX�� 100������ �Ѵ�.      
} polynomial;

polynomial *polys[MAX];   // ���� ���� ���׽��� �����ϱ����� �迭    

int n = 0;      // ���׽��� ����  

int read_line(FILE * fp, char str[], int n);
//���׽��� �α׸� ���������� �Ἥ ��ȯ���� ���� ��� �� 
int create(char *b);//�Էµ�� �Ѱ� �ִ��������� ��ȯ 
void add(char *b);//�Է� ��� ���� 
void mult(char *b);//�Էµ�� �ΰ� 
void calc(char *b);//�Էµ�� �ΰ�-�Լ������ 
void diff(char *b);//�Էµ�� �װ� as���� 
void print(char *b);//�Էµ�� �Ѱ� 

int main() {
	char command_line[buffer_length];//���� ���� 
	char *command;
	//memset(polys, 0, sizeof(polys)); 

	while (1)
	{
		printf("$ ");
		if (read_line(stdin, command_line, buffer_length) <= 0)
			continue;
		command = strtok(command_line, " ");

		char *b = command_line + strlen(command) + 1;

		if (strcmp(command, "create") == 0) {
			//char name = *b; 
			create(b);
		}
		else if (strcmp(command, "add") == 0) {
			add(b);
		}
		else if (strcmp(command, "mult") == 0) {
			mult(b);
		}
		else if (strcmp(command, "calc") == 0) {
			calc(b);
		}
		else if (strcmp(command, "diff") == 0) {
			diff(b);
		}
		else if (strcmp(command, "print") == 0) {
			print(b);
		}
		else if (strcmp(command, "exit") == 0)
			break;
	}
	return 0;
}
/*��Ʈ���� ��������
polynomial polys[MAX];   // ���� ���� ���׽��� �����ϱ����� �迭
int n;      // ���׽��� ����

char name;    // f, g, h���� ���׽��� �̸�
int nbr_terms;   // �� ���׽��� �����ϴ� ���� ����
term terms[MAX]
int coef;    // ���
int expo;    // ����
*/
int read_line(FILE * fp, char str[], int n)
{
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
int create(char *b)//check 
{//�̹� ����Ȱ��� �ִ��� �˻� 
	for (int i = 0; i < n; i++)
	{
		if (*b == polys[i]->name)
		{
			printf("�̹� ����� �Լ��Դϴ�.\n");
			return 0;
		}
	}
	polys[n] = (polynomial *)malloc(sizeof(polynomial));
	memset(polys[n], 0, sizeof(polynomial));

	for (int i = 0; i < MAX; i++) {
		polys[n]->terms[i] = (term *)malloc(sizeof(term));
		memset(polys[n]->terms[i], 0, sizeof(term));
	}
	polys[n]->name = *b;  //�Ҵ�������� �޸� ���� why? 
	n++;
	return 1;
}
void add(char *b) {
	char token = *strtok(b, " ");//�Լ��̸��� ����ɰ��̴�. 
	int index = -1;
	int coef;//���� 
	int expo;//��� 

	while (token != polys[++index]->name)//indexã��, ������ �ݺ����� Ż���Ѵ�. 
	{
	}
	coef = atoi(strtok(NULL, " "));// ����� ���� 
	expo = atoi(strtok(NULL, " "));//�������� 
	if (polys[index]->terms[expo]->coef == 0)//���� 
		polys[index]->nbr_terms++;
	polys[index]->terms[expo]->coef += coef;//��� 
	polys[index]->terms[expo]->expo = expo;//���� 
	return;
}
void mult(char *b) {//check 
	int count = 0;//������ ���� ������ ī��Ʈ�Ѵ� 
	char token = *strtok(b, " ");//�Լ��̸��� ����ɰ��̴�. 
	int number = atoi(strtok(NULL, " ")); //���� ����� ����ȴ�. 
	int index = -1;
	while (token != polys[++index]->name)//indexã��, ������ �ݺ����� Ż���Ѵ�. 
	{
	}
	int i = 0;
	while (!(count == polys[index]->nbr_terms))//������ Ż�� 
	{

		if (polys[index]->terms[i]->coef != 0)//0�̾ƴҶ� 
		{
			polys[index]->terms[i]->coef *= number;
			count++;
		}
		i++;
	}
	return;
}
void calc(char *b) //�Էµ�� �ΰ� - �Լ������//check 
{

	char token = *strtok(b, " ");//�Լ��̸��� ����ɰ��̴�. 
	int x = atoi(strtok(NULL, " ")); //x���� ����ȴ�. 
	int number = 1, tot = 0;//tot ��Ż�� , number ������������ �� 
	int count = 0;
	int index = -1;
	while (token != polys[++index]->name)//indexã��, ������ �ݺ����� Ż���Ѵ�. 
	{
	}
	int it = 0;
	while (!(count == polys[index]->nbr_terms))//������ Ż�� 
	{

		if (polys[index]->terms[it]->coef != 0)//0�̾ƴҶ� 
		{
			number *= polys[index]->terms[it]->coef;//����� ���Ѵ�. 
			for (int i = 1; i <= polys[index]->terms[it]->expo; i++)
			{
				number *= x; //��������ŭ ���Ѵ�. 
			}
			count++;
			tot += number;
			number = 1;
		}
		it++;
	}
	printf("%c(%d) = %d\n", polys[index]->name, x, tot);
	return;
}
void diff(char *b) {//�̺�  
	char token1 = *strtok(b, " ");//���Լ� 
	char *as = strtok(NULL, " ");//as 
	char *token2 = strtok(NULL, " ");//�̺��Լ� 
	if (create(token2))//create(h) 
	{
		int index = -1;//���Լ� �ε��� 
		while (index < MAX)
		{
			if (token1 == polys[++index]->name)
				break;
			index++;
		}
		if (index == MAX)
			return;
		int count = 0;

		for (int i = 1; count != polys[index]->nbr_terms; i++)
		{
			if ((polys[index]->terms[i]->coef) != 0)
			{
				polys[n - 1]->terms[i - 1]->expo = i - 1;
				polys[n - 1]->terms[i - 1]->coef = i * (polys[index]->terms[i]->coef);
				polys[n - 1]->nbr_terms++;
				count++;
			}
		}
	}
	return;
}
void print(char *b) {//check 
	char *token = strtok(b, " ");//�Լ��̸��� ����ɰ��̴�. 
	if (strcmp(token, "all") == 0)//������� 0��ȯ ��ü ��� 
	{
		for (int i = 0; i < n; i++)
		{
			printf("%c(x): ", polys[i]->name);
			char *function = &polys[i]->name;
			print(function);//����Լ� ���� 
		}
	}

	else //�κ��Լ��� ��� 
	{
		int index = -1;

		while (*token != polys[++index]->name)//indexã��, ������ �ݺ����� Ż���Ѵ�. 
		{
		}// ��ü����϶��� ���ʿ��� �κ��̶� �ణ ��ȿ�����̴�. 
		 //���ڿ��� ���� ����ұ�? ���ھ� ����ϰ� �ұ�? 
		int MAX_index = 0;
		//�׼��� ���� Ȯ���ϴ¿� 
		for (int i = 0, count = 0; i < MAX; i++)//i�� ���⼭ �ְ����� ����̴�. 
		{
			if (polys[index]->terms[i]->coef != 0 && MAX_index < i)
			{
				MAX_index = i;
				count++;
			}
			if (count == polys[index]->nbr_terms)
				break;
		}//MAX_index�� ���ߴ�. 
		if (MAX_index != 0)//ù�� ��� 
		{
			if (polys[index]->terms[MAX_index]->coef != 1)// 1���� 
				printf("%dx^%d",
					polys[index]->terms[MAX_index]->coef, polys[index]->terms[MAX_index]->expo);
			else
			{
				printf("x^%d",
					polys[index]->terms[MAX_index]->expo);
			}//�ε����� 0�� �ƴϰ� ����� 1�϶� ����� �����Ѵ�. 
		}//���, x^���� 
		else//MAX_index =0�ϰ�� 
		{
			printf("%d\n", polys[index]->terms[MAX_index]->coef);
			return;
		}
		if (1 == polys[index]->nbr_terms)
		{
			printf("\n");
			return;
		}MAX_index--;



		for (int count = 1; ; )
		{
			if (polys[index]->terms[MAX_index]->coef != 0 && MAX_index != 0)
			{
				if (polys[index]->terms[MAX_index]->coef > 0)
				{
					if (polys[index]->terms[MAX_index]->coef != 1)
						printf("+%dx^%d",
							polys[index]->terms[MAX_index]->coef, polys[index]->terms[MAX_index]->expo);
					else
					{
						printf("+x^%d",
							polys[index]->terms[MAX_index]->expo);
					}//�ε����� 0�� �ƴϰ� ����� 1�϶� ����� �����Ѵ�. 

				}
				else //(polys[index]->terms[MAX_index].coef<0)//���� ����̴ٸ��� 
				{
					printf("%dx^%d",
						polys[index]->terms[MAX_index]->coef, polys[index]->terms[MAX_index]->expo);
				}
				count++;
			}
			else if ((polys[index]->terms[MAX_index]->coef != 0 && MAX_index == 0))//�ڿ������ 
			{
				if (polys[index]->terms[MAX_index]->coef > 0)//���� ���� 
				{
					printf("+%d",
						polys[index]->terms[MAX_index]->coef);
				}
				else
				{
					printf("%d",
						polys[index]->terms[MAX_index]->coef);
				}
				count++;
			}//0�϶� ������ ���� ����� �ٷ� ���� 

			if (count == polys[index]->nbr_terms)
				break;
			MAX_index--;
		}
		printf("\n");
	}
	return;
}
//���� ���� ���ϰ��ִ°��� �𸣰ڴ�.