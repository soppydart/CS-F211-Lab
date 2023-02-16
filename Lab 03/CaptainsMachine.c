#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int binSearch(int *arr, int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (low == high)
    {
        if (arr[mid] == x || arr[mid] < x)
            return arr[mid];
        else
            return arr[mid - 1];
    }
    else if (arr[mid] > x)
        return binSearch(arr, low, mid - 1, x);
    else
        return binSearch(arr, mid + 1, high, x);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int *arr = malloc(n * sizeof(int)), s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        s += arr[i];
    }
    bubbleSort(arr, n);
    if (s / k < arr[0])
        printf("0\n");
    else
        printf("%d\n", binSearch(arr, 0, n - 1, s / k));

    return 0;
}