#pragma warning (disable: 4996)//5-1 고침!!!!!
#include"stdio.h" 
#include"string.h" 
#include"stdlib.h" 
#define MAX 100 

typedef struct node
{
	char* word;
	int number;//중첩수 
	struct node *next;
} Node;
int add_after(char *item);

char *ignore[60];
Node *word_lists[26];//26개의 head 
Node *head;
int main()
{
	char buffer[MAX];
	int ign = 0; //ignore갯수 
	for (int i = 0; i < 26; i++)  //list메모리할당 
	{
		word_lists[i] = (Node *)malloc(sizeof(Node));
		memset(word_lists[i], 0, sizeof(Node));
	}
	FILE  *fp2 = fopen("ignore.txt", "r");

	if (fp2 == NULL)
	{
		puts("파일안열림");
		return 0;
	}
	while (fscanf(fp2, "%s ", buffer) != EOF)
	{
		ignore[ign++] = strdup(buffer);
	}
	fclose(fp2);
	//비교할 ignore단어를 모두 읽는다. *********************************************************** 
	FILE  *fp1 = fopen("harry.txt", "r");
	if (fp1 == NULL)
	{
		puts("파일안열림");
		return 0;
	}
	while (fscanf(fp1, "%s ", buffer) != EOF)//strlen ,strdup -> a , b -> -1반환 
	{
		int r = 0;
		if (strlen(buffer) < 3)
			continue;
		for (int i = 0; i < ign; i++)
		{
			if (strcmp(ignore[i], buffer) == 0)
			{
				r = 1;
				break;
			}
		}
		if (r == 1)
		{
			continue;
		}
		head = word_lists[buffer[0] - 97];
		while (1)//연결리스트 탐색 
		{
			if (head->next == NULL && head->word == NULL)
			{
				head->word = strdup(buffer);
				head->number = 1;
				break;
			}if (strcmp(head->word, buffer) > 0)
			{
				Node *tmp = (Node *)malloc(sizeof(Node));
				tmp->word = strdup(buffer);
				tmp->number = 1;
				tmp->next = word_lists[buffer[0] - 97];
				word_lists[buffer[0] - 97] = tmp;
				break;
			}
			else if (strcmp(head->word, buffer) == 0)
			{
				head->number++;
				break;
			}
			else if (head->next == NULL)
			{
				add_after(buffer);
			}
			else if ((strcmp(head->word, buffer) < 0) && (strcmp(head->next->word, buffer) > 0))
			{
				add_after(buffer);
				break;
			}
			head = head->next;//다음칸 진행 
		}
	}
	//출력  *********************************************************** 
	for (int i = 0; i < 26; i++)
	{
		head = word_lists[i];
		while (1)
		{
			printf("%s : %d \n", head->word, head->number);
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	getchar();
	getchar();
	return 0;
}

int add_after(char *item)
{
	if (head == NULL)
		return 0;
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->word = strdup(item);
	tmp->number = 1;
	tmp->next = NULL;
	if (head->next != NULL)
	{
		tmp->next = head->next;
	}
	head->next = tmp;
	return 1;
}
