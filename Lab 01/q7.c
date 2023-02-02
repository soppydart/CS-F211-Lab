#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int getLast(char *str, int i, char ch, int n)
{
	if(n==0)
		return i-1;
	else if(i==strlen(str))
		return -1;
	if(str[i] == ch)
		n--;
	return getLast(str, i+1, ch, n);
}

int main()
{
	char str[1000], word[1000];
	scanf("%[^\t\n]s",str);
	scanf("%s",word);

	char *arr1 = malloc(strlen(word)*sizeof(char));
	int *arr2 = calloc(strlen(word),sizeof(int));
	int index = 0, j, marker = 0;

	for(int i=0;i<strlen(word);i++)
	{
		bool flag = false;
		char ch = word[i];
		for(j=0;j<index;j++)
		{
			if(word[i] == arr1[j])
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

	int imin, jmin, curlength = 1000, c = 0;
	for(int i=0;i<strlen(str);i++)
	{
		int max = -1;
		bool flag = true;
		for(int j=0;j<strlen(arr1);j++)
		{
			int g = getLast(str, i, arr1[j], arr2[j]);
			if(g==-1)
			{
				flag = false;
				break;
			}
			if(g>max)
				max = g;
		}
		if(!flag)
			continue;
		if(max-i<curlength)
		{
			imin = i;
			jmin = max;
			curlength = max - i;
			c++;
		}
	}
	if(c==0)
	{
		printf("NO WINDOW");
		return 0;
	}

	printf("%d %d\n", imin, jmin);
	for(int i=imin;i<=jmin;i++)
		printf("%c",str[i]);

	return 0;
}
