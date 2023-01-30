#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int *a = malloc(n*sizeof(int));
	int neg = 0;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int k = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			int temp = a[i];
			for(int j=i;j>k;j--)
				a[j] = a[j-1];
			a[k] = temp;
			k++;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
		
	return 0;
}
