
#include"stdio.h" //3-2
#include"string.h"
#include"stdlib.h"
//#pragma warning (disable: 4996)

const int MAX = 40;
const int BUFFER_SIZE = 80; //������������ ���Ұ���

char buffer[80] = { 0, };
char line[40][80] = { 0, };
/*
	fscanf, strdup�� ���Ұ� 2�����迭�� �̿��� fgetc���
*/

void Fprint(FILE *fpw, int count, int num , int tot);

int main()
{
	FILE  *fpr; fopen_s(&fpr, "har.txt", "r"); //�ȿ����� ����
	FILE  *fpw; fopen_s(&fpw, "aligned.txt", "w");

	int tot = -1;
	int count = 0;

	char NL = 0;//�߰����� ������ ���� ����

	int i = 0;
	/*-------------------------------------------------*/
	while (1)//Ż������?
	{
		/* ------------�ܾ���--------------------------------------------------------  */
		memset(buffer, 0, BUFFER_SIZE);
		if (NL == ' ')
			NL = 0;
		buffer[0] = NL;//NL�̹���
		if (buffer[0] != 0)
			i++;
		NL = 0;
		while ((buffer[i] = fgetc(fpr)) != EOF)//�ܾ����
		{
			if (buffer[i] == ' ' && i != 0)//�ܾ���� strdup�μ� �ۿ�  SP=32
			{
				buffer[i] = 0;  // '\0' NULL 
				i = 0;
				break;//Ż��
			}
			else if (buffer[i] == 32 && i == 0)
			{//ó������ ���ڿ��� �����̽����϶� �����ϰ� �����д´�
				continue;
			}
			else if (buffer[i] == '\n') // ������ �ƽ�Ű�ڵ�� 10
			{
				if ((NL = fgetc(fpr)) == '\n') //Ż��
				{/*��ĭ�� ������ �̷�������� üũ�Ѵ�
				 �̷������ �� NL�� ���� �ѱ��� �ƴҽÿ� ���� �ݺ��ÿ�
				 buffer�� ù������ �ѱ��
				 */
					buffer[i] = 0;//NULL��ä���
					i = 0;
					break;
				}
				else
				{//���̷������ ������ ����
					buffer[i] = 0; //������ null�� ä�� �ܾ�� ������
					i = 0;
					break;
				}
			}
			else //���ڸ� �״�� �̾ �Է�
				i++;
		}

		if (strlen(buffer) == 0)
			continue;

		/*------------------------���̰��,���----------------------------------------------------------------------------*/
		//��� & �˻�
		if ((tot + strlen(buffer) + 1 <= 80) && NL != 10)//+1�� ������� ����Ѱ� 
		{
			strcpy_s(line[count], BUFFER_SIZE , buffer);//�Ѷ��ο� �Է��� �ܾ�� count
			tot++;
			tot += strlen(line[count]);
			count++;  // -> �ؿ� count �ε����� ���� ����
		}
		else if ((tot + strlen(buffer)) >= 80)  // �������� ���������������� 80���Ѵ´� ���� �ڿ� �����ڸ����ִµ� ���
		{
			Fprint(fpw, count, 0, tot); //��� case 1

			if (NL == '\n') // tot+buffer>80�ε� buffer�ڰ� ������ �̷�������  case 1-2 buffer���
			{
				fprintf(fpw, "%s\n", buffer);
				tot = -1;
				count = 0;
				NL = 0;
			}
			else //buffer�� ó�� �Ѷ������� �ִ´�.
			{
				tot = strlen(buffer);
				count = 1;
				strcpy_s(line[0], BUFFER_SIZE, buffer);
			}
		}
		else if (NL == '\n')
		{
			/*NL�� �����϶��� tot���� ������� ����Ѵ�
			buffer�ǰ��� �����ؼ� ����� �Ͽ����Ѵ�.
			���⼭ �߰� �����̽��ٴ� �����ʴ´�*/
			
			Fprint(fpw, count, 1, 0); //��� case 2 buffer���
			fprintf(fpw, "%s", buffer);
			fprintf(fpw, "\n\n");

			tot = -1;
			count = 0;
			NL = 0;
		}
		else//������ ������ �ִ°�
		{
			printf("�ǵ��������� ����\n");
		}

		if (feof(fpr)) //������ Ż������
			break;
	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer�ܾ ���´�
	if(count == 1) //case1 ��buffer�� ����������
		fprintf(fpw, "%s", buffer);
	
	fclose(fpr);
	fclose(fpw);
	//system("pause");
	return 0;
}



void Fprint(FILE *fpw, int count, int num, int tot) //num 1�϶� �ܼ� ���, 0�϶� ���ݰ��
{
	int j = 0;
	switch (num)
	{
	case 0 :  // ���ݰ��
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", line[i]);
			if (i == count - 1) //������ �ܾ�
			{
				fprintf(fpw, "\n");
				break;
			}
			int a = (80 - tot) / (count - 1); //��ü������ �߰������� ����� Ƚ��
			int b = (80 - tot) % (count - 1); //���� ����� Ƚ��
			for (int i = 0; i <= a; i++)
			{
				fprintf(fpw, " ");
			}
			if (j++ < b)
				fprintf(fpw, " ");
		}
		break;
	
	case 1: //�ܼ� ���
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", line[i]);
			fprintf(fpw, " ");
		}
		break;
	default:
		printf("�߸��� �Է��Դϴ�.");
		break;
	}
}
