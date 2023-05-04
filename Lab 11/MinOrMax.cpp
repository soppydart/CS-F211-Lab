#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int recursion(int i, int j, vector<int> arr)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans1 = arr[i] + min(recursion(i + 2, j, arr), recursion(i + 1, j - 1, arr));
    int ans2 = arr[j] + min(recursion(i + 1, j - 1, arr), recursion(i, j - 2, arr));
    return dp[i][j] = max(ans1, ans2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += vect[i];
    int player1 = recursion(0, n - 1, vect);
    cout << (2 * player1 - sum) << endl;

    return 0;
}