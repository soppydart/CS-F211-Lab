#include <stdio.h>
#include <stdlib.h>

int solve(int *arr, int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (low >= high)
    {
        if (arr[mid] == x || arr[mid] > x)
            return mid + 1;
        else
            return mid + 2;
    }
    else if (arr[mid] > x)
        return solve(arr, low, mid - 1, x);
    else
        return solve(arr, mid + 1, high, x);
}

int main()
{
    int n;
    scanf("%d", &n);
    int s = 0;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        s += n - i - 1;
        arr[i] = s;
    }
    printf("%d\n", solve(arr, 0, n - 1, n * (n - 1) / 4));

    return 0;
}