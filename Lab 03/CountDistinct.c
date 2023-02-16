#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (arr[mid] == x && (mid == high || arr[mid + 1] != x))
        return mid;
    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, high, x);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i = 0, c = 0;
    while (i < n)
    {
        c++;
        i = binarySearch(arr, 0, n - 1, arr[i]) + 1;
    }
    printf("%d\n", c);

    return 0;
}