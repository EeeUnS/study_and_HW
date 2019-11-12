// int atoi
#include"stdio.h"//1¹ø
#include"stdlib.h"

#pragma warning (disable: 4996)
#define Max 100
int main()
{
	int tot = 0;
	int sub = 0;
	char str[Max];
	fgets(str, Max, stdin);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (48 <= str[i] && str[i] <= 57 && (48 <= str[i + 1] && str[i + 1] <= 57))
		{
			sub += (str[i] - 48);
			sub *= 10;
		}
		else if (48 <= str[i] && str[i] <= 57)
		{
				tot += str[i] - 48 + sub;
				sub = 0;
		}
	}
	printf("%d", tot);
	system("pause");
	return 0;
}