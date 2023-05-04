#include <bits/stdc++.h>
using namespace std;

int **dp;

int MatrixChainMultiplication(int mat[], int low, int high)
{
    if (low == high)
        return 0;

    if (dp[low][high] != -1)
        return dp[low][high];

    dp[low][high] = INT_MAX;

    // Iterating from low to high - 1
    for (int k = low; k < high; k++)
    {
        int cost = MatrixChainMultiplication(mat, low, k) +
                   MatrixChainMultiplication(mat, k + 1, high) +
                   mat[low - 1] * mat[k] * mat[high];
        if (cost < dp[low][high])
            dp[low][high] = cost;
    }
    return dp[low][high];
}

int main()
{
    int n;
    cin >> n;
    int mat[n + 1];
    for (int i = 0; i < n + 1; i++)
        cin >> mat[i];

    // Assigning memory to dp array
    // and Initializing with -1.
    dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
    }
    cout << MatrixChainMultiplication(mat, 1, n) << endl;
    return 0;
}
