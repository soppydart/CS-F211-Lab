#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(int *a, int n, int *b, int q)
{
	bool flag = false;
	int i = 0, j = 0;
	int *b0 = b;
	while(i<n && j<q)
	{
		if(a[i] == b[i])
		{
			a++;
			b++;
			flag = true;
		}
		else
		{
			a++;
			b = b0;
			flag == false;
		}
	}
	if(j == q && flag)
		return true;
	else
		return false;
}
int** transverse(int **a, int m, int n)
{
	int **b = malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		b[i] = malloc(m*sizeof(int));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			b[j][i] = a[i][j];
	return b;
}
int main()
{
	int m,n,p,q;
	scanf("%d%d",&m,&n);
	int **a = malloc(m*sizeof(int));
	for(int i=0;i<m;i++)
		a[i] = malloc(n*sizeof(int));
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	scanf("%d%d",&p,&q);
	int **b = malloc(p*sizeof(int));
	for(int i=0;i<q;i++)
		b[i] = malloc(n*sizeof(int));
	for(int i=0;i<p;i++)
	for(int j=0;j<q;j++)
	scanf("%d",&b[i][j]);
	
	int rowMatch = 0, colMatch = 0;
	for(int i=0;i<m;i++)
	{
		if(i<n)
		if(check(a[i],n,b[i],q))
			rowMatch++;
	}
	
	a = transverse(a, m, n);
	b = transverse(b, p, q);
	
	for(int i=0;i<n;i++)
	{
		if(i<m)
		if(check(a[i],m,b[i],p))
			colMatch++;
	}
	
	if(rowMatch == p && colMatch == q)
	printf("YES\n");
	else if(rowMatch>0 || colMatch>0)
	printf("PARTIAL\n");
	else
	printf("NO\n");
	
	return 0;
}
