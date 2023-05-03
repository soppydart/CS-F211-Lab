#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

long solve(vector<int> cost, int n, int k, int i)
{
    if (k == 0)
        return 0;
    if (i == n || k < 0)
        return INT_MAX;

    if (dp[i][k] != -1)
        return dp[i][k];

    long a = 1 + solve(cost, n, k - cost[i], i);
    long b = solve(cost, n, k, i + 1);
    return dp[i][k] = min(a, b);
}

int main()
{

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
            dp[i][j] = -1;
    }

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    long x = solve(c, n, k, 0);
    if (x >= INT_MAX)
        cout << -1 << endl;
    else
        cout << x << endl;

    return 0;
}