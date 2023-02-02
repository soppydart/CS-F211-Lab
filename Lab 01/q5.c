#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int **a = malloc((2*n-1)*sizeof(int*));
	for(int i=0;i<2*n;i++)
		a[i] = malloc((2*n-1)*sizeof(int));
	int ri,rf,ci,cf;
	if(n%2==1)
	{
		ci = n-1;
		cf = ci + 2;
		ri = n - 3;
		rf = n - 1;
	}
	else
	{
		ci = n-2;
		cf = ci+2;
		ri = n-2;
		rf = n;
	}
	a[rf][ci] = 1;
	int b = 1;
	
	while(1)
	{
		for(int i=ci;i<cf;i+=2)
		{
			a[rf][i] = b++;
			if(b<=n*n)
				a[rf][i+1] = -1;
		}
		if(b>n*n)
			break;
		
		for(int i=rf;i>ri;i-=2)
		{
			a[i][cf] = b++;
			a[i-1][cf] = -2;
		}
		ci-=2;
		for(int i=cf;i>ci;i-=2)
		{
			a[ri][i] = b++;
			if(b<=n*n)
				a[ri][i-1] = -1;
		}
		
		if(b>n*n)
		break;
		
		rf+=2;
		for(int i=ri;i<rf;i+=2)
		{
			a[i][ci] = b++;
			a[i+1][ci] = -2;
		}
		cf+=2;
		ri-=2;
	}
	
	for(int i=0;i<2*n;i++)
	{
		for(int j=0;j<2*n;j++)
		{
			if(a[i][j] == -1)
				printf("-\t");
			else if(a[i][j] == -2)
				printf("|\t");
			else if(a[i][j] != 0)
				printf("%d\t", 2*a[i][j]);
			else
				printf(" \t");
		}
		printf("\n");
	}
	
	return 0;
}
