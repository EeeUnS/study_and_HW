#pragma warning (disable: 4996) 
#include"string_tools.h"
#include"library.h"
#include<windows.h>

#define BUFFER_LENGTH 200
#define NUM_CHARS 256
#define null NULL
#define SIZE_INDEX_TABLE 100

void insert_to_index_directory(Song *ptr_song);
void insert_node(Artist *ptr_artist, SNode *ptr_snode);//c
void print_artist(Artist *p);//c
void  print_song(Song *ptr_song);//c
Artist * find_artist(char *name);//c
SNode *find_snode(Artist *ptr_artist, char *title);//c
SNode *find_song(int index);
void save_song(Song *ptr_song, FILE *fp);
void save_artist(Artist *p, FILE *fp);
void destroy_song(Song *ptr_song);
void remove_snode(Artist *ptr_artist, SNode *ptr_snode);

Artist *artist_directory[NUM_CHARS] = { NULL, };
SNode *index_directory[SIZE_INDEX_TABLE] = { NULL ,};

int num_index = 0;

//void initilize()//쓸모없는 함수 memset 은 쓸수없는가?
//{
//	for (int i = 0; i < NUM_CHARS; i++)
//		artist_directory[i] = NULL;
//
//	for (int i = 0; i < SIZE_INDEX_TABLE ; i++)
//		index_directory[i] = null;
//}

void load(FILE *fp)
{
	char buffer[BUFFER_LENGTH];
	char *name= NULL;
	char *title = NULL;
	char *path = NULL;

	while (1)
	{
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
			break;
		name = strtok(buffer, "#");
		if (strcmp(name, " ") == 0)
			name = NULL;
		else
			name = strdup(name);

		title = strtok(null, "#");
		if (strcmp(title, " ") == 0)
			title = NULL;
		else
			title = strdup(title);

		path = strtok(null, "#");
		if (strcmp(path, " ") == 0)
			path = NULL;
		else
			path = strdup(path);
		//printf("%s %s %s \n", name , title, path);
		add_song(name, title, path);
	}
}

void search_song(char *artist, char *title)
{
	Artist *ptr_artist = find_artist(artist);
	if (ptr_artist == NULL)
	{
		printf("No such artist exists. \n");
		return;
	}

	SNode *ptr_snode = find_snode(ptr_artist, title);
	
	if (ptr_snode != null)
	{
		printf("Found:\n");
		print_song(ptr_snode->song);
	}
	else {
		printf("No such artist exists. \n");
		return;
	}


}

SNode *find_snode(Artist *ptr_artist, char *title)
{
	SNode *ptr_snode = ptr_artist->head;
	while (ptr_snode != null && strcmp(ptr_snode->song->title, title) < 0)
		ptr_snode = ptr_snode;//그대로 대입?

	if (ptr_snode != null && strcmp(ptr_snode->song->title, title) == 0)
	{
		return ptr_snode;
	}
	else 
		return null;
}

void search_song_no_title(char *artist)
{
	Artist *ptr_artist = find_artist(artist);
	if (ptr_artist == NULL)
	{
		printf("No such artist exists. \n");
		return;
	}
	printf("Found:\n");
	print_artist(ptr_artist);


}

Artist *create_artist_instance(char *name)
{
	Artist *ptr_artist = (Artist *)malloc(sizeof(Artist));
	ptr_artist->name = name;
	ptr_artist->head = NULL;
	ptr_artist->tail = NULL;
	ptr_artist->next = NULL;

	return ptr_artist;
}

Artist *add_artist(char *name)
{
	Artist *ptr_artist = create_artist_instance(name);
	Artist *p = artist_directory[(unsigned char)name[0]]; //first node
	Artist *q = NULL;

	while (p != NULL && strcmp(p->name, name) < 0)
	{
		q = p;
		p = p->next;
	}

	if (p == NULL && q == NULL) //unique node 유일한 노드
	{
		artist_directory[(unsigned char)name[0]] = ptr_artist;

	}
	else if (q == NULL) //add at the front
	{
		ptr_artist->next = artist_directory[(unsigned char)name[0]];
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else //add_after(q)
	{
		ptr_artist->next = p;
		q->next = ptr_artist;
	}

//	ptr_artist->next = p;
//	artist_directory[(unsigned char)name[0]] = ptr_artist;

	return ptr_artist;
}

Song *create_song_instance(Artist *ptr_artist, char *title, char *path)
{
	Song *ptr_song = (Song *)malloc(sizeof(Song));
	ptr_song->artist = ptr_artist;
	ptr_song->title = title;
	ptr_song->path = path;
	ptr_song->index = num_index; //static은 안되는가?
	num_index++;
	return  ptr_song;
}

void add_song(char *artist, char *title, char* path)
{
	//find if the artist already exists
	Artist *ptr_artist = find_artist(artist);
	if (ptr_artist == NULL)
		ptr_artist  = add_artist(artist);
	//add the song to the artist pointed by ptr_artist

	Song *ptr_song = create_song_instance(ptr_artist, title, path);
	SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));

	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL;
	
	//insert node

	insert_node(ptr_artist, ptr_snode);
	insert_to_index_directory(ptr_song);
}

void insert_to_index_directory(Song *ptr_song)
{
	SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL; //unused

	int index = ptr_song->index % SIZE_INDEX_TABLE;

	//insert the snode into the single linked list at index_table[index]

	SNode *p = index_directory[index];
	SNode *q = NULL;

	//while (p != null && strcmp(p->song->title, ptr_song->title) < 0)
	//{
	//	q = p;
	//	p = p->next;
	//}
	//if (q == NULL)//add first
	//{
	//	ptr_snode->next = p;
	//	index_directory[index] = ptr_snode;
	//}  
	//else { //add after q
	//	ptr_snode->next = p;
	//	q->next = ptr_snode;
	//}
	while (p != NULL )//&& strcmp(p->song->title, ptr_snode->song->title) < 0삭제
	{
		p = p->next;

	}
	// add ptr_snode before p
	// 1.empty 2. at the front 3. at the end 4. in the middle

	if (p == NULL) //empty
	{
		index_directory[index] = ptr_snode;
	}
	//else if (p == index_directory[index]) //2 정렬을 하지않기때문에 맨앞에 넣을일이없다
	else //3
	{
		p->next = ptr_snode;
		ptr_snode->prev = p;
	}
	//else { 4정렬을 하지않기때문에 중간에 넣을일이없다
	
}

void insert_node(Artist *ptr_artist,SNode *ptr_snode)
{
	SNode *p = ptr_artist->head;
	while (p != NULL && strcmp(p->song->title,ptr_snode->song->title )<0)
	{
		p = p->next;

	}
	// add ptr_snode before p
	// 1.empty 2. at the front 3. at the end 4. in the middle

	if (ptr_artist->head == NULL) //empty
	{
		ptr_artist->head = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	else if (p==ptr_artist->head) //2
	{
		ptr_snode->next = ptr_artist->head;
		ptr_artist->head->prev = ptr_snode;
		ptr_artist->head = ptr_snode;
	}
	else if (p == NULL) //3
	{
		ptr_snode->prev = ptr_artist->tail;
		ptr_artist->tail->next = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	else {
		ptr_snode->next = p;
		ptr_snode->prev = p->prev;
		p->prev->next = ptr_snode;
		p->prev = ptr_snode;
	}

}

Artist * find_artist(char *name)
{
	Artist *p = artist_directory[(unsigned char)name[0] ]; //first artist with initial name[0]
	/*  name[0] : 00000000 ~ 1111111  이해못함..*/
	while (p != NULL && strcmp(p->name, name) < 0)
	{
		p = p->next;
	}
	
	if (p != NULL && strcmp(p->name, name) == 0)
		return p;
	else
		return NULL;
}

void status()
{
	for (int i = 0; i < NUM_CHARS; i++)
	{
		Artist *p = artist_directory[i];
		while (p != NULL)
		{
			print_artist(p);
			p = p->next;
		}

	}
}

void print_artist(Artist *p)
{
	printf("%s\n", p->name);
	SNode *ptr_snode = p->head;
	while (ptr_snode != null)
	{
		print_song(ptr_snode->song);
		ptr_snode = ptr_snode->next;
	}
}

void  print_song(Song *ptr_song)
{
	printf("    %d: %s, %s\n", ptr_song->index  , ptr_song->title, ptr_song->path);
}

SNode *find_song(int index) { //노래번호로 찾기
	SNode *ptr_snode = index_directory[index%SIZE_INDEX_TABLE];
	while (ptr_snode != null && ptr_snode->song->index != index)
		ptr_snode = ptr_snode->next;

	return ptr_snode;

}


void play(int index)
{
	SNode *ptr_snode = find_song(index);
	if (ptr_snode == null) {
		printf("No such song exist. \n");
		return;
	}

	printf("Found the song : %s\n" , ptr_snode->song->title);
	ShellExecute(GetDesktopWindow(), "open", ptr_snode->song->path, NULL, NULL, SW_SHOW);
}


void save(FILE *fp)
{
	for (int i = 0; i < NUM_CHARS; i++)
	{
		Artist *p = artist_directory[i];
		while (p != NULL)
		{
			save_artist(p , fp);
			p = p->next;
		}

	}

}

void save_artist(Artist *p, FILE *fp)
{
	SNode *ptr_snode = p->head;
	while (ptr_snode != null)
	{
		save_song(ptr_snode->song , fp);
		ptr_snode = ptr_snode->next;
	}


}

void save_song(Song *ptr_song, FILE *fp)
{
	if(ptr_song->artist != null)
		fprintf(fp, "%s#",ptr_song->artist->name);
	else
		fprintf(fp, " #\n");
	if(ptr_song->title != null)
		fprintf(fp, "%s#", ptr_song->title);
	else
		fprintf(fp, " #\n");
	if(ptr_song->path != null)
		fprintf(fp, "%s#\n", ptr_song->path);
	else
		fprintf(fp, " #\n");
}

void remove(int index)
{
	//find the song
	SNode *q = null;
	SNode *p = index_directory[index %SIZE_INDEX_TABLE];

	while (p != null && p->song->index != index)
	{
		q = p;
		p = p->next;
	}

	if (p == NULL)//add first
	{
		printf("No such song exist. \n");
		return;
	}
	Song *ptr_song = p->song;
	if (q == NULL)  //remove first
	{
		index_directory[index%SIZE_INDEX_TABLE] = p->next;

	}
	else {  //remover after q
		q->next = p->next;
	}
	free(p);

	Artist *ptr_artist = ptr_song->artist;

	//find the snode in the double linked list of ptr_artist
	SNode *ptr_snode = find_snode(ptr_artist, ptr_song->title);
	if(ptr_snode == null)
	{
		printf("Not found snode - something wrong \n");
		return;
	}
	remove_snode( ptr_artist,ptr_snode);
	destroy_song(ptr_song);
}


void destroy_song(Song *ptr_song)
{
	if (ptr_song->title != null)
		free(ptr_song->title);
	if (ptr_song->artist != null)
		free(ptr_song->artist);
	if (ptr_song->path != null)
		free(ptr_song->path);
	free(ptr_song);
}

void remove_snode(Artist *ptr_artist,SNode *ptr_snode)
{
	SNode *first = ptr_artist->head;
	SNode *last = ptr_artist->tail;

	if (first == ptr_snode && last == ptr_snode) // 4case    unique node
	{
		ptr_artist->head = null;
		ptr_artist->tail = null;
		
	}
	else if (first == ptr_snode) { //remove first
		ptr_artist->head = ptr_snode->next;
	}
	else if (last == ptr_snode) { //remove last
		ptr_artist->tail = ptr_snode->prev;
	}
	else // in the middle
	{
		ptr_snode->prev->next = ptr_snode->next;
		ptr_snode->next->prev = ptr_snode->prev;
	}
	free(ptr_snode);
}


/*수정할만한것
셋초기화 
index_directiory 2중연결로만들기
타이틀순서인것 그냥 순서대로 넣기
*/