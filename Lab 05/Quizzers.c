#include <stdio.h>
#include <stdlib.h>

int solve(int *arr, int n, int k, int t)
{
    int c = 0, sum = 0, index = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    if (sum / k >= t)
        c++;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[index] + arr[i];
        if (sum / k >= t)
            c++;
        index++;
    }
    return c;
}

int main()
{
    int n, k, t;
    scanf("%d%d%d", &n, &k, &t);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", solve(arr, n, k, t));

    return 0;
}