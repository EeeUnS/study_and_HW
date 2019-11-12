#pragma warning (disable: 4996)

#include  <stdio.h>
#include  "stackADT.h"//stdbool이 include되어있다.
#include  "pos.h"
#include  <stdlib.h>

#define  MAX  100
#define  PATH  1                     /*  지나갈수있는위치  */
#define  WALL  0                    /*  지나갈수없는위치  */
#define  VISITED  2                /*  이미방문한위치  */
#define  BACKTRACKED  3           /*  방문했다가되돌아나온위치  */

int  maze[MAX][MAX];
int  n;           /*  미로의크기  */

void  read_maze();
void  print_maze();
bool  movable(Position  pos, int  dir);

int search(int i , int j);  //위치를 입력받는다


/*
설계:
1로 칠해진것 자체를 하나의 미로로 인식한다.
따라서 한덩이를 1의 값으로 이어진 미로로 인식하고 모든방향을 탐색한후 크기를 반환한다.
기존 미로와의 가장 큰차이점은
4 방향 -> 8방향으로 대각선방향이 추가되었다
pos.c에서 수정
PATH -> 1
WALL -> 0
*/



int  main()
{
	read_maze();	/* maze.txt파일로부터미로의모양을배열  maze로입력받는다.  */
	//	print_maze();

	for (int i = 0; i < n; i++) //확인용
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 1)
				printf("%d\n" , search(i,j));
		}
		
	}

	system("pause");
	return 0;
}


void  read_maze()
{
	FILE  *fp = fopen("inmaze.txt", "r");
	int buffer;  //입력받는 0,1

	if ((int)fp == -1)
	{
		printf("파일 안열림");
		return -1;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; )
		{
			fscanf(fp, "%d", &buffer);
			if (buffer == ' ')
				continue;
			maze[i][j++] = buffer;
		}
	}
	fclose(fp); //더이상의 파일을 입력받을 필요가없다.
}

void  print_maze()
{
	for (int i = 0; i < n; i++) //확인용
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", maze[i][j]);
		}
		printf("                 %d\n" , i);
	}

}

bool  movable(Position  pos, int  dir)
{
	switch (dir)
	{
		case 0:
			if((pos.x - 1) >= 0 && (maze[pos.x-1][pos.y] == 1))
				return true; 
			return false;
		case 1:
			if ((pos.x - 1 >= 0) && (pos.y + 1 < n) && (maze[pos.x-1][pos.y+1] == 1))
				return true;
			return false;
		case 2:
			if ((pos.y + 1 < n) && (maze[pos.x][pos.y+1] == 1))
				return true;
			return false;
		case 3:
			if ((pos.y + 1 < n) && (pos.x + 1 < n)  && (maze[pos.x +1][pos.y+1] == 1))
				return true;
			return false;
		case 4:
			if ((pos.x + 1 < n) && (maze[pos.x + 1][pos.y] == 1))
				return true;
			return false;
		case 5:
			if ((pos.x + 1 < n && pos.y - 1 >= 0 )&&( maze[pos.x +1][pos.y-1] == 1))
				return true;
			return false;
		case 6:
			if (pos.y - 1 >= 0 &&  maze[pos.x ][pos.y-1] == 1)
				return true;
			return false;

		case 7:
			if (pos.x - 1 >= 0 && pos.y - 1 >= 0 && maze[pos.x - 1][pos.y-1] == 1)
				return true;
			return false;
	default:
		return false;
	}
}



int search(int i, int j)  //현재
{
	Stack  s = create();						/*  위치를저장할스택  */

	int sum = 1;					// 덩어리의 전체크기
	Position  cur;									 /*  항상 현재 위치를표현  */
	cur.x = i;
	cur.y = j;

	int init_dir = 0;								/* 어떤 위치에 도착했을  처음으로 시도해 볼 이동 방향 */

	while (1)  //이 미로는 출구가 없는 미로이다.
	{
		maze[cur.x][cur.y] = VISITED;						 /*  현재위치를방문했다고표시한다.  따라서 방문한곳은 모두 2 3로 도배*/
		
		bool  forwarded = false;							 /*  8방향 중 한곳으로전진하는데성공했는지를표시한다.*/
		for (int dir = init_dir; dir < 8; dir++)  
		{
										/*  0:N북 	1: 북동 	2:E동,	3  동남	4:S남,	5  남서		6  W서	7   서북	*/
			if (movable(cur, dir))						/*  dir방향으로이동할수있는지검사  */
			{
				push(s, dir);					 /* 스택에는 현재 위치 대신 이동하는 방향을 push */
				cur = move_to(cur, dir);		/*  현재위치를  stack에  push하고 dir 방향으로한칸이동한위치를새로운  cur라고한다.*/
				forwarded = true;

				init_dir = 0;
				sum++;		//push를 할때마다 sum값을 올려준다.
				break;
			}
		}
		if (!forwarded)	/*  8방향중어느곳으로도가지못했다면  */
		{
			//maze[cur.x][cur.y] = BACKTRACKED;			/*  왔다가되돌아간위치임을표시  */

			if (is_empty(s)) /* 원래출구없는미로 유일한 탈출문 */
			{
				//printf("No  path  exists.\n");
				break;
			}
			int d = pop(s);
			cur = move_to(cur, (d + 4) % 8);
			/*이전 위치에서 지금 위치에 올 때 d방향으로
				이동했었다면 되돌아 가려면 (d+2)%4번
					방향으로 이동하면 된다
					=> 8방향에선 +4 %8		*/
			init_dir = d + 1;					/*되돌아 간 위치에서는 d+1번 방향부터 시도해보면 된다.*/
		}
	}
	//print_maze();
	return sum;
}
