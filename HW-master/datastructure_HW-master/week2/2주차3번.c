#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#pragma warning (disable: 4996)

#define MAX 80
#define BUFFER_SIZE 20


char *line[MAX];
char buffer[BUFFER_SIZE];

int main() {
	//while ((fscanf(fp, "%s", buf1) != EOF)) {

	FILE  *fpr = fopen("harry.txt", "r");
	FILE  *fpw = fopen("aligned.txt", "w");

	int tot = -1;
	int count = 0;
	while ((fscanf(fpr, "%s", buffer) != EOF)) //�Ѵܾ �Է¹޴´٤�
	{
		if ((tot + strlen(buffer)) + 1 <= 80)//+1�� ������� ����Ѱ� 
		{
			line[count] = strdup(buffer);//�Ѷ��ο� �Է��� �ܾ�� count
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
				if (j + tot<80) //tot =80 , j=0�϶� ���ư���
				{
					fprintf(fpw, " ");
					j++;
				}
			}
			tot = strlen(buffer);
			count = 1;
			line[0] = strdup(buffer);
		}
		else {
			printf("�ǵ��������� ����\n");
		}
	}
	for (int i = 0; i < count; i++) //�������� ����
	{
		fprintf(fpw, "%s", line[i]);
		if (i == count - 1)
		{
			fprintf(fpw, "\n");
			break;
		}
		fprintf(fpw, " ");
	}

	fclose(fpr);
	fclose(fpw);
	system("pause");
	return 0;
}
