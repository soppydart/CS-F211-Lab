#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void subsetSum(int pos, int len, int set[], int subset[], int n, int target)
{
	if(pos == n)
	{
		int sum = 0;
		for(int i=0;i<len;i++)
			sum += subset[i];
		if(sum == target)
		{
			int *f = calloc(n, sizeof(int));
			printf("POSSIBLE\n");
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(subset[i] == set[j] && f[j]==0)
					{
						printf("%d ",j);
						f[j]++;
						break;
					}
				}
			}
			exit(0);
		}
		return;
	}

	subset[len] = set[pos];
	subsetSum(pos+1, len+1, set, subset, n, target);
	subsetSum(pos+1, len, set, subset, n, target);
}

int main()
{
	int n, sum;
	scanf("%d",&n);
	int *arr = malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&sum);
	int *sub = malloc(n*sizeof(int));
	subsetSum(0, 0, arr, sub, n, sum);
	printf("NOT POSSIBLE");

	return 0;
}
