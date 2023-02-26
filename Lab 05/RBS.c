#include <stdio.h>
#include <stdlib.h>

void solve(char *arr, int left, int right, int i)
{
    if (left == 0 && right == 0)
    {
        arr[i] = '\0';
        printf("%s\n", arr);
    }
    if (left > 0)
    {
        arr[i] = '(';
        solve(arr, left - 1, right, i + 1);
    }
    if (right > left)
    {
        arr[i] = ')';
        solve(arr, left, right - 1, i + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char *arr = malloc((n) * sizeof(char));
    solve(arr, n / 2, n / 2, 0);

    return 0;
}