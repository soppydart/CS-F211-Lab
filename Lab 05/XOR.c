#include <stdio.h>
#include <stdlib.h>

int sumA(int *A, int n, int m)
{
    if (m % 2 == 0)
        return 0;
    int s = 0;
    for (int i = 0; i < n; i++)
        s ^= A[i];
    return s;
}

int sumB(int *B, int n, int m)
{
    if (n % 2 == 0)
        return 0;
    int s = 0;
    for (int i = 0; i < m; i++)
        s ^= B[i];
    return s;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int *A = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &m);
    int *B = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]);

    int xor = sumA(A, n, m) ^ sumB(B, n, m);
    printf("%d\n", xor);

    return 0;
}