#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n, int type)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (type == 1)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int findMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int solve(int *arr, int n, int k)
{
    int *sum = calloc(k, sizeof(int));
    bubbleSort(arr, n, 1);
    int indexN = 0, indexK = 0;
    while (indexN != n - n % k)
    {
        sum[indexK++] += arr[indexN++];
        if (indexK == k)
            indexK = 0;
    }
    indexK = 0;
    bubbleSort(sum, k, 0);
    for (int i = indexN; i < n; i++)
        sum[indexK++] += arr[i];
    return findMax(sum, k);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", solve(arr, n, k));

    return 0;
}