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
	while ((fscanf(fpr, "%s", buffer) != EOF)) //한단어씩 입력받는다ㅣ
	{
		if ((tot + strlen(buffer)) + 1 <= 80)//+1은 띄어쓰기까지 고려한것 
		{
			line[count] = strdup(buffer);//한라인에 입력할 단어수 count
			tot++;
			tot += strlen(line[count]);
			count++;  // -> 밑에 count 인덱스의 값은 없다
		}
		else if ((tot + strlen(buffer)) >= 80)  // 위조건은 만족하지못하지만 80을넘는다 따라서 뒤에 남는자리가있는데 출력
		{
			int j = 0; //띄어쓰기를 추가로 할 횟수
			for (int i = 0; i < count; i++)
			{

				fprintf(fpw, "%s", line[i]);
				if (i == count - 1)
				{
					fprintf(fpw, "\n");
					break;
				}
				fprintf(fpw, " ");
				if (j + tot<80) //tot =80 , j=0일때 돌아간다
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
			printf("의도하지않은 오류\n");
		}
	}
	for (int i = 0; i < count; i++) //마지막줄 쓰기
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
