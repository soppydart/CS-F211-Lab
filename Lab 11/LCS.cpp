#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int> a, vector<int> b, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << lcs(a, b, m, n) << endl;

    return 0;
}