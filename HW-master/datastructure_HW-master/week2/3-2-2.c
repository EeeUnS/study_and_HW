#include"stdio.h" //3-2
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
//#pragma warning (disable: 4996)

const int Max = 40;
const int BUFFER_SIZE = 100;

int search_is();
void Fprint(FILE *fpr, int count, int num, int tot); //num 1�϶� �ܼ� ���, 0�϶� ���ݰ��
void line_check(FILE*fpw, int count, int tot);

char buffer[80];
char words[40][40] = { 0, };
char *line[100] = { 0, };


int tot = -1;
int count = 0;
int i = 0;

int main()//isspace
{
	FILE  *fpr; fopen_s(&fpr, "har.txt", "r");
	FILE  *fpw; fopen_s(&fpw, "aligned.txt", "w");
	if ((int)fpr == -1)
	{
		printf("���� �ȿ���");
		return -1;
	}
	

	/*-------------------------------------------------*/
	while (1)//Ż������?
	{
		if (feof(fpr) == 1)
			break;
		char input_buffer[100];
		if (*input_buffer <= 0)
		{
			fgets(input_buffer, BUFFER_SIZE, fpr);
			if (!search_is())//�����Ͻ� Ʈ���ȯ -> ��ü��¹� ��ĭ����
			{
				Fprint(fpw, count, 1, 0); //��� case 2 buffer���				
				fprintf(fpw, "\n");
				tot = -1;
				count = 0;
				continue;
			}
			strcpy(buffer, strtok(input_buffer, " "));
			 //strcpy_s  , &pbuffer
			line_check(fpw, count, tot);
		}
		else
		{
			strcpy(buffer, strtok(NULL, " "));

			//strcpy (input_buffer , strtok(NULL, " "));
			//strcpy_s(buffer, BUFFER_SIZE, strtok(NULL," ")); //�ܾ ����� ������ �ε�����  count-1
			line_check(fpw, count, tot);
		}

	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer�ܾ ���´�

	if (count == 1) //case1 ��buffer�� ����������
		fprintf(fpw, "%s", buffer);

	fclose(fpr);
	fclose(fpw);
	system("pause");
	return 0;
}

int search_is()
{
	int i = 0;
		for (; buffer[i] != '\n'; i++)
		{
			if (!isspace(buffer[i])) //�����϶� Ʈ�� ��ȯ
				return 0;
		}
	return 1; //�����϶�
}

void Fprint(FILE *fpw, int count, int num, int tot) //num 1�϶� �ܼ� ���, 0�϶� ���ݰ��
{
	int j = 0;
	switch (num)
	{
	case 0:  // ���ݰ��
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", words[i]);
			int a = (80 - tot) / (count - 1); //��ü������ �߰������� ����� Ƚ��
			int b = (80 - tot) % (count - 1); //���� ����� Ƚ��
			for (int i = 0; i <= a; i++)
			{
				fprintf(fpw, " ");
			}
			if (j++ < b)
				fprintf(fpw, " ");
		}
		fprintf(fpw, "\n");
		break;

	case 1: //�ܼ� ���
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", words[i]);
			fprintf(fpw, " ");
		}
		fprintf(fpw, "\n");
		break;
	default:
		printf("�߸��� �Է��Դϴ�.");
		break;
	}
}

void line_check(FILE*fpw, int count, int tot)
{
	if ((tot + strlen(buffer) + 1) <= 80)//+1�� ������� ����Ѱ�  
	{
		strcpy_s(words[count] , BUFFER_SIZE ,buffer);//�Ѷ��ο� �Է��� �ܾ�� count
		++tot;  //���� ���
		tot += strlen(words[count++]);   // ->  count �ε����� ���� ����
	}
	else if ((tot + strlen(buffer)) >= 80)  // ���: buffer�� ���������ʰ� ����Ѵ�.
	{
		int j = 0;
		for (int i = 0; i < count; i++)
		{
			Fprint(fpw, count, 0, tot); //��� case 1
		}
		tot = strlen(buffer);
		count = 1;
		strcpy_s(words[0], BUFFER_SIZE, buffer);
	}
	else { //������ȵǴ� ����
		printf("�ǵ��������� ����\n");
	}
}