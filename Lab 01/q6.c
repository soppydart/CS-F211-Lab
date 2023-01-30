#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkPrime(int x)
{
	for(int i=2;i<=x/2;i++)
	{
		if(x%i == 0)
			return false;
	}
	return true;
}

void maxDig(int n, int *a)
{
	while(n>0)
	{
		a[n%10 -1]++;
		n /= 10;
	}
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int *arr = calloc(10, sizeof(int));
	for(int i=a;i<=b;i++)
	{
		if(checkPrime(i))
			maxDig(i, arr);
	}
	int maxPos = 0;
	for(int i=1;i<10;i++)
	{
		if(arr[i]>arr[maxPos])
			maxPos = i;
	}
	printf("%d %d",maxPos+1,arr[maxPos]);

	return 0;
}
