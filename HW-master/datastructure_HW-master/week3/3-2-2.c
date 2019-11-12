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
		printf("파일 안열림");
		return -1;
	}

	int tot = -1;
	int count = 0;

	char NL = 0;//추가적인 개행을 위한 변수
	int i = 0;

	/*-------------------------------------------------*/
	while (1)//탈출조건?
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
		//출력 & 검사
		if ((tot + strlen(buffer) + 1 <= 80) && NL != 10)//+1은 띄어쓰기까지 고려한것
		{
			strcpy(line[count], buffer);//한라인에 입력할 단어수 count
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
				if (j + tot < 80) //tot =80 , j=0일때 돌아간다
				{
					fprintf(fpw, " ");
					j++;
				}
			}
			if (NL == 10) //buffer뒤의 개행  tot+buffer>80인데 buffer뒤가 개행이 이루어질경우
			{
				fprintf(fpw, "%s", buffer);//buffer출력
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
		else if (NL == 10)//NL이 개행일때는 tot값에 상관없이 출력한다
		{//buffer의값도 포함해서 출력을 하여야한다.
		 //여기서 추가 스페이스바는 하지않는다
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
		else//나오면 문제가 있는것
			printf("의도하지않은 오류\n");
	}
	/*-----------------------------------------------------------------------------------------------*/
	buffer[i] = 0;//buffer단어가 남는다
	if ((tot + strlen(buffer)) >= 80)  // 버퍼를 포함안했을때 행이 완성된경우
	{
		for (int i = 0; i < count; i++)
		{
			fprintf(fpw, "%s", line[i]);
			if (i == count - 1)
				break;
			fprintf(fpw, " ");

		}
		fprintf(fpw, "%s", buffer);//행이 띄워진후 마지막 버퍼만 처리
	}
	else//그냥 출력만 쭉 시키면된다
	{
		for (int i = 0; i < count; i++) //마지막줄 쓰기
		{
			fprintf(fpw, "%s", line[i]);
			fprintf(fpw, " ");
		}
		fprintf(fpw, "%s", buffer);//마지막 버퍼만 삽입
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
        if(!isspace(buffer[i])) //공백일때 트루 반환
            return 0;
    }
    return 1; //공백일때
}

