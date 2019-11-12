#ifndef POS_H_INCLUDED
#define POS_H_INCLUDED

typedef  struct  pos { int  x, y; }  Position;

Position  move_to(Position  pos, int  dir);
#endif // POS_H_INCLUDED
