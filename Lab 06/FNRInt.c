#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], ans[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int *freq = calloc(n, sizeof(int));
    int queue[n], front = -1, rear = 0;
    queue[rear] = arr[0];
    freq[arr[0]]++;
    ans[0] = queue[0];
    for (int i = 1; i < n; i++)
    {
        queue[++rear] = arr[i];
        freq[arr[i]]++;
        while (front < rear && freq[queue[front + 1]] > 1)
        {
            front++;
        }
        if (front >= rear)
            ans[i] = -1;
        else
            ans[i] = queue[front + 1];
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}