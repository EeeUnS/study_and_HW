#include"ctype.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MAX 100
#pragma warning (disable: 4996)

//int read_line_with_compresstion(char compressed[], int limit);

int main()
{
	char buffer[MAX][MAX] = { 0, };
	int row, coulumn;
	FILE  *fp = fopen("tabular.txt", "r");
	if (fp == NULL)
	{
		puts("파일안열림");
		return 0;
	}
	fscanf(fp, "%d ", &row);
	fscanf(fp, "%d ", &coulumn);

	int *length = (int *)malloc(coulumn * sizeof(int));

	int  h = 0;
	char ch;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coulumn; j++)
		{
			h = 0;
			while (((ch = fgetc(fp)) != '&') && (buffer[i*coulumn + j][h - 1] != 92 && ch != 92) && (ch != EOF))// 92 = &
			{

				if (ch == '\n')
					continue;
				if (h < MAX - 1 && (!isspace(ch) || h > 0 && !isspace(buffer[i*coulumn + j][h - 1])))
				{
					buffer[i*coulumn + j][h++] = ch;
				}

			}
			if (ch == 92)  //만악의 근원
			{
				ch = fgetc(fp);
			}

			if (h > 0 && (isspace(buffer[i*coulumn + j][h - 1]) | (buffer[i*coulumn + j][h - 1] == 92)))
				h--;
			buffer[i*coulumn + j][h] = '\0';

			if (length[j] < h)  //문제 
			{
				length[j] = h;//가장 긴길이만 저장
			}
		}
	}

	fclose(fp);
	printf("r\n");

	FILE  *fpw = fopen("output.txt", "w"); //출력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coulumn; j++)
		{
			for (h = 0; buffer[i*coulumn + j][h] != 0; h++)
			{
				fprintf(fpw, "%c", buffer[i*coulumn + j][h]);
			}

			for (int k = 0; k < length[j] - h; k++)
			{
				fprintf(fpw, " ");
			}

			fprintf(fpw, " ");

		}
		fprintf(fpw, "\n");;
	}
	fclose(fpw);

	system("pause");
	return 0;
}
