#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int solve(int n, int w, int i, int s, vector<int> weight, vector<int> value)
{
    if (w < 0 || i > n)
        return -1;
    if (w == 0)
        return s;
    if (dp[i][w] != -1)
        return dp[i][w];
    int a = solve(n, w, i + 1, s, weight, value);
    int b = solve(n, w - weight[i], i + 1, s + value[i], weight, value);
    return dp[i][w] = max(a, b);
}

int main()
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    }

    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    cout << solve(n, w, 0, 0, weight, value) << endl;

    return 0;
}