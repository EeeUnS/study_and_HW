#include"stdio.h" //3-2
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
//#pragma warning (disable: 4996)

const int Max = 40;
const int BUFFER_SIZE = 100;

int search_is();

char buffer[BUFFER_SIZE] = { 0, };
char line[MAX][40] = { 0, };

int main()//isspace
{
	FILE  *fpr ; fopen_s(&fpr,"harry.txt", "r");
	FILE  *fpw ; fopen_s(&fpw ,"aligned.txt", "w");
	if (fpr == -1)
	{
		printf("���� �ȿ���");
		return -1;
	}

	int tot = -1;
	int count = 0;

	char NL = 0;//�߰����� ������ ���� ����
	int i = 0;

	/*-------------------------------------------------*/
	while (1)//Ż������?
	{
        while(fgets(buffer , BUFFER_SIZE ,fpr) != NULL)
        {
            if(!search_is())
            {
				fprintf(fpw, "\n");
                continue;
            }
            strtok(buffer,  , " ");


        }


		/*-------------------------------------------------------------------------*/
		//��� & �˻�
		if ((tot + strlen(buffer) + 1 <= 80) && NL != 10)//+1�� ������� ����Ѱ�
		{
			strcpy(line[count], buffer);//�Ѷ��ο� �Է��� �ܾ�� count
			tot++;
			tot += strlen(line[count]);
			count++;  // -> �ؿ� count �ε����� ���� ����
		}
		else if ((tot + strlen(buffer)) >= 80)  // �������� ���������������� 80���Ѵ´� ���� �ڿ� �����ڸ����ִµ� ���
		{
			int j = 0; //���⸦ �߰��� �� Ƚ��
			for (int i = 0; i < count; i++)
			{

				fprintf(fpw, "%s", line[i]);
				if (i == count - 1)
				{
					fprintf(fpw, "\n");
					break;
				}
				fprintf(fpw, " ");
				if (j + tot < 80) //tot =80 , j=0�϶� ���ư���
				{
					fprintf(fpw, " ");
					j++;
				}
			}
			if (NL == 10) //buffer���� ����  tot+buffer>80�ε� buffer�ڰ� ������ �̷�������
			{
				fprintf(fpw, "%s", buffer);//buffer���
				fprintf(fpw, "\n");
				tot = -1;
				count = 0;
				NL = 0;
				continue;
			}
			tot = strlen(buffer);
			count = 1;
			strcpy(line[0], buffer);
		}
		else if (NL == 10)//NL�� �����϶��� tot���� ������� ����Ѵ�
		{//buffer�ǰ��� �����ؼ� ����� �Ͽ����Ѵ�.
		 //���⼭ �߰� �����̽��ٴ� �����ʴ´�
			for (int i = 0; i < count; i++)
			{

				fprintf(fpw, "%s", line[i]);

				fprintf(fpw, " ");
				if (i == count - 1)
				{
					fprintf(fpw, "%s", buffer);
					fprintf(fpw, "\n\n");
				}
			}
			tot = -1;
			count = 0;
			NL = 0;
		}
		else//������ ������ �ִ°�
			printf("�ǵ��������� ����\n");
	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer�ܾ ���´�
	if ((tot + strlen(buffer)) >= 80)  // ���۸� ���Ծ������� ���� �ϼ��Ȱ��
	{
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", line[i]);
			if (i == count - 1)
				break;
			fprintf(fpw, " ");

		}
		fprintf(fpw, "%s", buffer);//���� ������� ������ ���۸� ó��
	}
	else//�׳� ��¸� �� ��Ű��ȴ�
	{
		for (int i = 0; i < count; i++) //�������� ����
		{
			fprintf(fpw, "%s", line[i]);
			fprintf(fpw, " ");
		}
		fprintf(fpw, "%s", buffer);//������ ���۸� ����
	}
	fclose(fpr);
	fclose(fpw);
	system("pause");
	return 0;
}

int search_is()
{
    int i = 0
    for(; buffer[i] != '\n' ; i++)
    {
        if(!isspace(buffer[i])) //�����϶� Ʈ�� ��ȯ
            return 0;
    }
    return 1; //�����϶�
}

