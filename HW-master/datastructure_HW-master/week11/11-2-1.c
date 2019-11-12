#include<stdio.h>
#include<stdbool.h>

int N = 8;
int maze[][8] = { //총갯수 1 +1 +1 + 1 + 1 + 1
{ 0, 0, 0, 0, 0, 0, 0, 1 },
{ 0, 1, 1, 0, 1, 1, 0, 1 },
{ 0, 0, 0, 1, 0, 0, 0, 1 },
{ 0, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 1, 0, 1, 0, 0, 0, 1 },
{ 0, 1, 0, 0, 0, 1, 0, 1 },
{ 0, 0, 0, 1, 0, 0, 0, 1 },
{ 0, 1, 1, 1, 0, 1, 0, 0 }
};

/*
#define WHITE 0 // white  PATHWAY_COLOUR
#define BLUE 1 // blue  WALL_COLOUR
#define RED 2 // red  BLOCKED_COLOUR
#define GREEN 3 // green   PATH_COLOUR
*/

enum number {
	WHITE = 0,//PATHWAY_COLOUR
	BLUE,//WALL_COLOUR
	RED,//BLOCKED_COLOUR
	GREEN,//PATH_COLOUR
};

void  printMaze();
int findMazePath(int x, int y);

int main() {
	printMaze();
	printf(" %d \n " , findMazePath(0, 0));
	printf("\n\n");
	printMaze();
	system("pause");
}


void  printMaze()
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d", maze[i][j]);
		}
		printf("                 %d\n", i);
	}

}
int count = 0;
int findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N )
		return false;
	else if(maze[x][y] == GREEN)  // 벽과 아닌것을 구분 그린일때는 다시 통행가능한걸로 바꾸고 돌아간다.
	{
		maze[x][y] == WHITE;
		return false;
	}
	else if (maze[x][y] == BLUE)
	{
		return false;
	}
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = 0;
		return true; //숫자로서 더한다.
	}
	else {
		maze[x][y] = GREEN;
	/*	if (findMazePath(x - 1, y) || findMazePath(x, y + 1)
			|| findMazePath(x + 1, y) || findMazePath(x, y - 1))
		{
			return true;
		}*/
		int sum = 0;
		sum += findMazePath(x - 1, y);
		sum += findMazePath(x, y + 1);
		sum += findMazePath(x + 1, y);
		sum += findMazePath(x, y - 1);

		maze[x][y] = RED; // dead end
		return sum;
	}
}