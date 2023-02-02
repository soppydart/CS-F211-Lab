#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	char s[1000], a[1000];
	scanf("%s %s",s,a);
	
	int index = 0, j;
	bool flag = false;
	char arr1[strlen(s)];
	int *arr2 = calloc(strlen(s), sizeof(int));

	for(int i=0;i<strlen(s);i++)
	{
		flag = false;
		char ch = s[i];
		for(j=0;j<index;j++)
		{
			if(arr1[j] == ch)
			{
				flag = true;
				break;
			}
		}
		if(flag)
			arr2[j]++;
		else
		{
			arr1[index] = ch;
			arr2[index]++;
			index++;
		}
	}

	for(int i=0;i<strlen(a);i++)
	{
		flag = false;
		for(j=0;j<strlen(s);j++)
		{
			if(a[i] == s[j])
			{
				flag = true;
				arr2[j]--;
			}
		}
		if(!flag)
		{
			printf("NOT POSSIBLE");
			return 0;
		}
	}

	for(int i=0;i<strlen(s);i++)
	{
		if(arr2[i] != 0)
		{
			printf("NOT POSSIBLE");
			return 0;
		}
	}
	
	for(int i=0;i<strlen(s);i++)
	{
		for(j=0;j<strlen(s);j++)
		{
			if(a[i] == s[j])
			{
				printf("%d ",j+1);
				break;
			}
		}
	}

	return 0;
}
