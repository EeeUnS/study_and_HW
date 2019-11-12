#pragma warnig (disable: 4996)
#include "stdio.h"
#define MAX 100


int  main(void)
{
	int  data[MAX];
	int  n = 0;

	int  tmp;
	FILE  *fp = fopen("input.txt", "r");

	while (fscanf(fp, "%d", &tmp) != EOF)
		data[n++] = tmp;

	fclose(fp);

	int  target;
	int  found = 0;
	scanf("%d", &target);

	/*for (int i = 0; i < n; i++)
	{
		if (data[i] == target) {
			printf("%d \n", i);
			found = 1;
			break;
		}
	}
	if (!found)
		printf("-1");*/
		//또는 대체가능
		/*int i;
		for (i = 0; i < n && data[i] != target ; i++){	}
		if (i < n)
			printf("%d", i);
		else
			printnf("-1");*/
}