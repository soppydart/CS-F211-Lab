#include <bits/stdc++.h>
using namespace std;

int dp[1001][5001];

int solve(vector<int> vect, int n, int k, int i)
{
    if (dp[i][k] != -1)
        return dp[i][k];
    if (k == 0)
        return true;
    if (k < 0 || i == n)
        return false;
    if (dp[i][k] == -1)
        return dp[i][k] = solve(vect, n, k - vect[i], i + 1) || solve(vect, n, k, i + 1);
}

int main()
{

    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 5001; j++)
            dp[i][j] = -1;

    int n, k;
    cin >> n >> k;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    if (solve(vect, n, k, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}