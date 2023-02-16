#include <stdio.h>
#include <stdlib.h>

int solve(int *arr, int low, int high, int k)
{
    int mid = (low + high) / 2;
    if (low == high)
        return mid;
    if (arr[mid] < k)
        return solve(arr, mid + 1, high, k);
    else if (arr[mid] > k)
        return solve(arr, low, mid, k);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", arr[solve(arr, 0, n - 1, k) - 1]);

    return 0;
}