#include<stdio.h>
#include<stdlib.h>

int main()
{
	int k, n;
	scanf("%d%d",&k, &n);
	int *arr = malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int mid = (k+1)/2;
	int index = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<mid)
		{
			int temp = arr[i];
			for(int j=i;j>index;j--)
				arr[j] = arr[j-1];
			arr[index] = temp;
			index++;
		}
	}
	//index = (n+1)/2 - 1;
	int midIndex = (n+1)/2 - 1;
	for(int i=index;i<n;i++)
	{
		if(arr[i] == mid)
		{
			for(int j=i;j>index;j--)
				arr[j] = arr[j-1];
			arr[index] = mid;
			break;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}
