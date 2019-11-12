#include  <stdio.h>
#include<string.h>

int compare(char *str1, char *str2)
{
    char a = *str1;
    char b = *str2;

    if(a > 'z')
        a -= 'A'-'a';
    if(b > 'z')
        b -= 'A'-'a';
    if( a== 0 && b ==0)
        return 0;
    else if( a > b) //a가 뒤에 있다.
        return 1 ;
    else if( a < b) //B가 뒤에있다.
        return -1;
    else //( a==b )
        return compare((str1+1), (str2+1));
}

int main()
{
  	FILE  *fp1 = fopen("hurry.txt", "r");
    char *word[100] = { NULL ,};

    if (fp1 == NULL)
	{
		puts("파일안열림");
		return 0;
	}

	int n=-1;
	while (fscanf(fp1, "%s ", word[++n]) != EOF) //strlen ,strdup -> a , b -> -1반환
	{
	}

	for(int loop = 0; loop < n - 1; loop++) {
            for (int i = 0; i < n - 1 - loop; i++) {
                if (compare(word[i] ,word[i+1]) == -1) {
                    char *hold = word[i];
                    word[i] = word[i+1];
                    word[i+1] = hold;
                }
            }
        }
    //printf("%d.", compare(arr,brr));
    fclose(fp1);
    for(int i=0; i<n; i++)
        printf("%s\n", word[i]);
    return 0;
}
