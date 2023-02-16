#include <stdio.h>
#include <stdlib.h>

int solve(int *arr, int low, int high, int x)
{
    int mid = (low + high) / 2;
    int a = arr[mid];
    if (a * a == x || (a * a < x && (a + 1) * (a + 1) > x))
        return a;
    else if (a * a > x)
        return solve(arr, low, mid - 1, x);
    else if (a * a < x && (a + 1) * (a + 1) <= x)
        return solve(arr, mid + 1, high, x);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    printf("%d\n", solve(arr, 0, n - 1, n));

    return 0;
}