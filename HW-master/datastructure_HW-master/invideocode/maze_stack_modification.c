#include  <stdio.h>
#include  "stack.h"
#include  "pos.h"
#define  MAX  100
#define  PATH  0                     /*  지나갈수있는위치  */
#define  WALL  1                    /*  지나갈수없는위치  */
#define  VISITED  2                /*  이미방문한위치  */
#define  BACKTRACKED  3           /*  방문했다가되돌아나온위치  */
int  maze[MAX][MAX];
int  n;           /*  미로의크기  */

void  read_maze();
void  print_maze();
bool  movable(POS  pos,  int  dir);

int  main()
{
    read_maze();
    /* maze.txt파일로부터미로의모양을배열  maze로입력받는다.  */
    Stack  s  =  create();
    /*  위치를저장할스택  */
    Position  cur;
    /*  항상현재위치를표현  */
    cur.x  =  0;
    cur.y  =  0;
    int init_dir = 0; /* 어떤 위치에 도착했을  처음으로 시도해 볼 이동 방향 */


    while(1)
    {
        maze[cur.x][cur.y]  =  VISITED;
        /*  현재위치를방문했다고표시한다.  */
        if  (cur.x  ==  n-1  &&  cur.y  ==  n-1)
        {
            /*  현재위치가출구라면.  */
            printf("Found  the  path.\n");
            break;
        }
        bool  forwarded  =  false;
        /*  4방향중한곳으로전진하는데성공했는지를표시한다.*/
        for  (int  dir  =  init_dir ;  dir<4;  dir++)
        {
            /*  0:N,  1:E,  2:S,  3:W  */
            if  (movable(cur,  dir))
            {
                /*  dir방향으로이동할수있는지검사  */
                push(s,  dir); /* 스택에는 현재 위치 대신 이동하는 방향을 push */
                /*  현재위치를  stack에  push하고    */
                cur  =  move_to(cur,  dir);
                /*  dir방향으로한칸이동한위치를새로운  cur라고한다.*/
                forwarded  =  true;
                init_dir = 0;
                break;
            }
        }
        if  (!forwarded)
        {
            /*  4방향중어느곳으로도가지못했다면  */
            maze[cur.x][cur.y]  =  BACKTRACKED;

            /*  왔다가되돌아간위치임을표시  */
            if  (is_empty(s))
            {
                /*  되돌아갈위치가없다면원래길이없는미로  */
                printf("No  path  exists.\n");
                break;
            }
            int d = pop(s);
            cur = move_to(cur, (d+2)%4);
            /*이전 위치에서 지금 위치에 올 때 d방향으로
                이동했었다면 되돌아 가려면 (d+2)%4번
                    방향으로 이동하면 된다*/
           init_dir = d+1; /*되돌아 간 위치에서는 d+1번 방향부터 시도해보면 된다.*/
        }
    }
    print_maze();
}
