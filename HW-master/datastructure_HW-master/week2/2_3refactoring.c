#include"stdio.h"
#include"string.h"
#include"stdlib.h"

const int MAX = 80;
const int BUFFER_SIZE = 80;

char *line[80];
char buffer[80];

int main() {

	FILE  *fpr; fopen_s(&fpr, "harry.txt", "r");
	FILE  *fpw; fopen_s(&fpw, "aligned.txt", "w");

	int tot = -1; //���ٿ� ���� ���ڼ� ���
	int count = 0; //�Ѷ��ο����� �ܾ��

	while ((fscanf_s(fpr, "%s", buffer, BUFFER_SIZE) != EOF)) //�Ѵܾ �Է¹޴´٤�
	{
		if ((tot + strlen(buffer) + 1) <= 80)//+1�� ������� ����Ѱ�  
		{
			line[count] = _strdup(buffer);//�Ѷ��ο� �Է��� �ܾ�� count
			++tot;  //���� ���
			tot += strlen(line[count++]);   // ->  count �ε����� ���� ����
		}
		else if ((tot + strlen(buffer)) >= 80)  // ���: buffer�� ���������ʰ� ����Ѵ�.
		{
			int j = 0;
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
			tot = strlen(buffer);
			for (int i = 0; i < count; i++)
				free(line[i]);
			count = 1;
			line[0] = _strdup(buffer);
		}
		else { //������ȵǴ� ����
			printf("�ǵ��������� ����\n");
		}
	}

	for (int i = 0; i < (count - 1); i++) //�������� ����
	{
		fprintf(fpw, "%s", line[i]);
		fprintf(fpw, " ");
	}
	fprintf(fpw, "%s", line[count - 1]);

	for (int i = 0; i < count; i++)
		free(line[i]);
	fclose(fpr);
	fclose(fpw);
	//system("pause");
	return 0;
}