
#include"stdio.h"//1.12
#pragma warning (disable: 4996) 
#include"stdlib.h"
typedef struct a{
	int x;
	struct a *front;
	struct a *end;
}Node;

void swap (int *x, int *y)
{
	int tot;
	tot = *x;
	*x = *y;
	*y = tot;
}

int main()
{
	int n;
	Node *pRoot=NULL;
	Node *Current = NULL;

	int arr[5];
	int num=-1;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d",&n );
		Current = (Node *)malloc(sizeof(Node));
		Current->x = n;
		Current->front = NULL;
		Current->end = NULL;
		arr[++num] = n;
		if (pRoot == NULL)
			pRoot = Current;
		else
		{
			Node *Currentroot = pRoot;
			while (1)
			{
				if(Currentroot->x <= n)//오른쪽으로이동
				{
					if (Currentroot->end == NULL)
					{
						Currentroot->end = Current;
						break;
					}
					else
						Currentroot = Currentroot->end;
				}
				else
				{ 
					if (Currentroot->x > n)//왼쪽으로이동
					{
						if (Currentroot->front == NULL)
						{
							Currentroot->front = Current;
							break;
						}
						else
							Currentroot = Currentroot->front;
					}
				
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5 - i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d   ", arr[i]);
	}

	getchar(); getchar(); 
	return 0 ;
}