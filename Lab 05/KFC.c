#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int solve(int *arr, int n, int k, int *split, int index, int min)
{
    if (index == n)
    {
        if (findMax(split, k) < min)
            min = findMax(split, k);
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            split[i] += arr[index];
            min = solve(arr, n, k, split, index + 1, min);
            split[i] -= arr[index];
        }
    }
    return min;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int *split = calloc(k, sizeof(int));
    printf("%d\n", solve(arr, n, k, split, 0, INT_MAX));

    return 0;
}