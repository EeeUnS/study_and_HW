
#include"stdio.h" //3-2
#include"string.h"
#include"stdlib.h"
//#pragma warning (disable: 4996)

const int MAX = 40;
const int BUFFER_SIZE = 80; //전역변수선언에 사용불갸ㅏ

char buffer[80] = { 0, };
char line[40][80] = { 0, };
/*
	fscanf, strdup는 사용불가 2차원배열을 이용해 fgetc사용
*/

void Fprint(FILE *fpw, int count, int num , int tot);

int main()
{
	FILE  *fpr; fopen_s(&fpr, "har.txt", "r"); //안열리면 뻑남
	FILE  *fpw; fopen_s(&fpw, "aligned.txt", "w");

	int tot = -1;
	int count = 0;

	char NL = 0;//추가적인 개행을 위한 변수

	int i = 0;
	/*-------------------------------------------------*/
	while (1)//탈출조건?
	{
		/* ------------단어만들기--------------------------------------------------------  */
		memset(buffer, 0, BUFFER_SIZE);
		if (NL == ' ')
			NL = 0;
		buffer[0] = NL;//NL이문제
		if (buffer[0] != 0)
			i++;
		NL = 0;
		while ((buffer[i] = fgetc(fpr)) != EOF)//단어생성
		{
			if (buffer[i] == ' ' && i != 0)//단어를끊어 strdup로서 작용  SP=32
			{
				buffer[i] = 0;  // '\0' NULL 
				i = 0;
				break;//탈출
			}
			else if (buffer[i] == 32 && i == 0)
			{//처음읽은 문자열이 스페이스바일때 무시하고 새로읽는다
				continue;
			}
			else if (buffer[i] == '\n') // 개행은 아스키코드로 10
			{
				if ((NL = fgetc(fpr)) == '\n') //탈출
				{/*한칸더 개행이 이루어지는지 체크한다
				 이루어지는 지 NL로 값을 넘긴후 아닐시에 다음 반복시에
				 buffer의 첫값으로 넘긴다
				 */
					buffer[i] = 0;//NULL로채운다
					i = 0;
					break;
				}
				else
				{//안이루어질시 개행은 무시
					buffer[i] = 0; //개행은 null로 채워 단어로 끝낸다
					i = 0;
					break;
				}
			}
			else //문자를 그대로 이어서 입력
				i++;
		}

		if (strlen(buffer) == 0)
			continue;

		/*------------------------길이계산,출력----------------------------------------------------------------------------*/
		//출력 & 검사
		if ((tot + strlen(buffer) + 1 <= 80) && NL != 10)//+1은 띄어쓰기까지 고려한것 
		{
			strcpy_s(line[count], BUFFER_SIZE , buffer);//한라인에 입력할 단어수 count
			tot++;
			tot += strlen(line[count]);
			count++;  // -> 밑에 count 인덱스의 값은 없다
		}
		else if ((tot + strlen(buffer)) >= 80)  // 위조건은 만족하지못하지만 80을넘는다 따라서 뒤에 남는자리가있는데 출력
		{
			Fprint(fpw, count, 0, tot); //출력 case 1

			if (NL == '\n') // tot+buffer>80인데 buffer뒤가 개행이 이루어질경우  case 1-2 buffer출력
			{
				fprintf(fpw, "%s\n", buffer);
				tot = -1;
				count = 0;
				NL = 0;
			}
			else //buffer를 처음 한라인으로 넣는다.
			{
				tot = strlen(buffer);
				count = 1;
				strcpy_s(line[0], BUFFER_SIZE, buffer);
			}
		}
		else if (NL == '\n')
		{
			/*NL이 개행일때는 tot값에 상관없이 출력한다
			buffer의값도 포함해서 출력을 하여야한다.
			여기서 추가 스페이스바는 하지않는다*/
			
			Fprint(fpw, count, 1, 0); //출력 case 2 buffer출력
			fprintf(fpw, "%s", buffer);
			fprintf(fpw, "\n\n");

			tot = -1;
			count = 0;
			NL = 0;
		}
		else//나오면 문제가 있는것
		{
			printf("의도하지않은 오류\n");
		}

		if (feof(fpr)) //유일한 탈출조건
			break;
	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer단어가 남는다
	if(count == 1) //case1 에buffer만 남아있을때
		fprintf(fpw, "%s", buffer);
	
	fclose(fpr);
	fclose(fpw);
	//system("pause");
	return 0;
}



void Fprint(FILE *fpw, int count, int num, int tot) //num 1일땐 단순 출력, 0일땐 간격계산
{
	int j = 0;
	switch (num)
	{
	case 0 :  // 간격계산
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
		break;
	
	case 1: //단순 출력
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", line[i]);
			fprintf(fpw, " ");
		}
		break;
	default:
		printf("잘못된 입력입니다.");
		break;
	}
}
