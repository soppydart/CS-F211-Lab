#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,ri,rh,ci,ch;
	scanf("%d%d",&m,&n);
	int **a, **b;
	a = malloc(m * sizeof(int));
	b = malloc(m * sizeof(int));
	for(int i=0; i<m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
		b[i] = (int*)malloc(n * sizeof(int));
	}
	int s=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&a[i][j]);
			s += a[i][j];
			b[i][j] = s;
		}
	}
	scanf("%d%d%d%d",&ri,&ci,&rh,&ch);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d ",b[i][j]);
		printf("\n");
	}
	if(ri+rh>m || ci+ch>n)
	{
		printf("NOT POSSIBLE\n");
		return 0;
	}
	int s1= 0;
	for(int i=ri;i<ri+rh;i++)
	for(int j=ci;j<ci+ch;j++)
	s1 += b[i][j];
	printf("%d",s1);
	return 0;
}
