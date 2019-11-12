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

	int tot = -1; //한줄에 들어가는 문자수 계산
	int count = 0; //한라인에들어가는 단어갯수

	while ((fscanf_s(fpr, "%s", buffer, BUFFER_SIZE) != EOF)) //한단어씩 입력받는다ㅣ
	{
		if ((tot + strlen(buffer) + 1) <= 80)//+1은 띄어쓰기까지 고려한것  
		{
			line[count] = _strdup(buffer);//한라인에 입력할 단어수 count
			++tot;  //띄어쓰기 고려
			tot += strlen(line[count++]);   // ->  count 인덱스의 값은 없다
		}
		else if ((tot + strlen(buffer)) >= 80)  // 출력: buffer는 포함하지않고 출력한다.
		{
			int j = 0;
			for (int i = 0; i < count; i++)
			{
				fprintf(fpw, "%s", line[i]);
				if (i == count - 1) //마지막 단어
				{
					fprintf(fpw, "\n");
					break;
				}
				int a = (80 - tot) / (count - 1); //전체적으로 추가적으로 띄워쓸 횟수
				int b = (80 - tot) % (count - 1); //개별 띄워쓸 횟수
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
		else { //나오면안되는 오류
			printf("의도하지않은 오류\n");
		}
	}

	for (int i = 0; i < (count - 1); i++) //마지막줄 쓰기
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