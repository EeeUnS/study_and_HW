#include  "pos.h"

int  offset[8][2] = {
	
	{-1,  0},//0:NºÏ
	{-1 ,1}, //1: ºÏµ¿
	{0,  1},//2:Eµ¿
	{1,1},//3  µ¿³²
	{1,  0},//4:S³²,
	{1,-1},//5  ³²¼­
	{0,  -1},//6  W¼­
	{-1,-1}//7   ¼­ºÏ
};

Position  move_to(Position  pos, int  dir)
{
	Position  next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	return  next;
}