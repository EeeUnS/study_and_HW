#ifndef  LIBRARY_H
#define LIBRARY_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;

struct song
{
	Artist *artist;
	char *title;
	char *path;
	int index;
};


struct snode
{
	struct snode *next, *prev;
	Song *song;
};

struct  artist
{
	char *name;
	struct  artist *next;
	SNode *head, *tail;

};


//void initilize();//������� �Լ�
void load(FILE *fp);
void search_song(char *artist, char *title);
void search_song_no_title(char *artist);
void add_song(char *artist, char *title, char* path);

void save(FILE *fp);
void play(int index);
void remove(int index);  //stdio.h�� remove�� ������ִ�. ���� ���� ��������� ��� ������ִµ�
void status();
Artist *create_artist_instance(char *name);
Artist *add_artist(char *name);
Song *create_song_instance(Artist *ptr_artist, char *title, char *path);


#endif // ! LIBRARY_H
