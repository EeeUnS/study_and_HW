#include<stdio.h>
#include<stdbool.h>

int N = 8;
int maze[][8] = {
{0, 0, 0, 0, 0, 0, 0, 1},
{0, 1, 1, 0, 1, 1, 0, 1},
{0, 0, 0, 1, 0, 0, 0, 1},
{0, 1, 0, 0, 1, 1, 0, 0},
{0, 1, 1, 1, 0, 0, 1, 1},
{0, 1, 0, 0, 0, 1, 0, 1},
{0, 0, 0, 1, 0, 0, 0, 1},
{0, 1, 1, 1, 0, 1, 0, 0}
};

#define PATHWAY_COLOUR 0 // white
#define WALL_COLOUR 1 // blue
#define BLOCKED_COLOUR 2 // red
#define PATH_COLOUR 3 // green

void  printMaze();
bool findMazePath(int x, int y);

int main() {
	printMaze();
	findMazePath(0, 0);

	printf("\n\n");
	printMaze();
	system("pause");
}


void  printMaze()
{
	for (int i = 0; i < N; i++) //È®ÀÎ¿ë
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d", maze[i][j]);
		}
		printf("                 %d\n", i);
	}

}

bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] != PATHWAY_COLOUR)
		return false;
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATH_COLOUR;
		return true;
	}
	else {
		maze[x][y] = PATH_COLOUR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1)
			|| findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;
		}
		maze[x][y] = BLOCKED_COLOUR; // dead end
		return false;
	}
}