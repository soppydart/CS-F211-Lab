#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectRandom(int x)
{
    static int res;
    static int count = 0;

    count++;

    if (count == 1)
        res = x;
    else
    {
        int i = rand() % count;
        if (i == count - 1)
            res = x;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d \n", selectRandom(x));
    }
    return 0;
}
