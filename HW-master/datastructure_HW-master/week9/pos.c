#include  "pos.h"

int  offset[8][2] = {
	
	{-1,  0},//0:N��
	{-1 ,1}, //1: �ϵ�
	{0,  1},//2:E��
	{1,1},//3  ����
	{1,  0},//4:S��,
	{1,-1},//5  ����
	{0,  -1},//6  W��
	{-1,-1}//7   ����
};

Position  move_to(Position  pos, int  dir)
{
	Position  next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	return  next;
}