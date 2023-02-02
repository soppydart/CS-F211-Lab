#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char * str2, char *str1)
{
	for(int i=0;i<strlen(str1);i++)
	{
		str2[i] = str1[strlen(str1)-i-1];
	}
}

int main()
{
	char str[1000], *word, **pals;
	pals = malloc(50*sizeof(char*));
	for(int i=0;i<50;i++)
		pals[i] = malloc(1000*sizeof(char));
	scanf("%[^\t\n]s",str);
	int index = 0;
	word = strtok(str," ");
	while(word != NULL)
	{
		char *str2 = malloc(strlen(word)*sizeof(char));
		reverse(str2, word);
		if(!strcmp(word,str2) && strlen(word)>1)
			pals[index++] = word;
		printf("%s ",str2);
		word = strtok(NULL, " ");
	}
	printf("\n");
	for(int i=0;i<index;i++)
		printf("%s ",pals[i]);	
	if(index==0)
		printf("NO PALINDROMES");
	return 0;
}
