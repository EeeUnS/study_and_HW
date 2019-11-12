#include"stdio.h" //3-2
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
//#pragma warning (disable: 4996)

const int Max = 40;
const int BUFFER_SIZE = 100;

int search_is();
void Fprint(FILE *fpr, int count, int num, int tot); //num 1일땐 단순 출력, 0일땐 간격계산
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
		printf("파일 안열림");
		return -1;
	}
	

	/*-------------------------------------------------*/
	while (1)//탈출조건?
	{
		if (feof(fpr) == 1)
			break;
		char input_buffer[100];
		if (*input_buffer <= 0)
		{
			fgets(input_buffer, BUFFER_SIZE, fpr);
			if (!search_is())//공백일시 트루반환 -> 전체출력및 한칸띄우기
			{
				Fprint(fpw, count, 1, 0); //출력 case 2 buffer출력				
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
			//strcpy_s(buffer, BUFFER_SIZE, strtok(NULL," ")); //단어가 저장된 마지막 인덱스는  count-1
			line_check(fpw, count, tot);
		}

	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer단어가 남는다

	if (count == 1) //case1 에buffer만 남아있을때
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
			if (!isspace(buffer[i])) //공백일때 트루 반환
				return 0;
		}
	return 1; //공백일때
}

void Fprint(FILE *fpw, int count, int num, int tot) //num 1일땐 단순 출력, 0일땐 간격계산
{
	int j = 0;
	switch (num)
	{
	case 0:  // 간격계산
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", words[i]);
			int a = (80 - tot) / (count - 1); //전체적으로 추가적으로 띄워쓸 횟수
			int b = (80 - tot) % (count - 1); //개별 띄워쓸 횟수
			for (int i = 0; i <= a; i++)
			{
				fprintf(fpw, " ");
			}
			if (j++ < b)
				fprintf(fpw, " ");
		}
		fprintf(fpw, "\n");
		break;

	case 1: //단순 출력
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", words[i]);
			fprintf(fpw, " ");
		}
		fprintf(fpw, "\n");
		break;
	default:
		printf("잘못된 입력입니다.");
		break;
	}
}

void line_check(FILE*fpw, int count, int tot)
{
	if ((tot + strlen(buffer) + 1) <= 80)//+1은 띄어쓰기까지 고려한것  
	{
		strcpy_s(words[count] , BUFFER_SIZE ,buffer);//한라인에 입력할 단어수 count
		++tot;  //띄어쓰기 고려
		tot += strlen(words[count++]);   // ->  count 인덱스의 값은 없다
	}
	else if ((tot + strlen(buffer)) >= 80)  // 출력: buffer는 포함하지않고 출력한다.
	{
		int j = 0;
		for (int i = 0; i < count; i++)
		{
			Fprint(fpw, count, 0, tot); //출력 case 1
		}
		tot = strlen(buffer);
		count = 1;
		strcpy_s(words[0], BUFFER_SIZE, buffer);
	}
	else { //나오면안되는 오류
		printf("의도하지않은 오류\n");
	}
}