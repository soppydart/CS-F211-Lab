#include <bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    int m, n;
    string str1, str2;
    cin >> m >> str1 >> n >> str2;
    cout << solve(str1, str2, m, n) << endl;

    return 0;
}