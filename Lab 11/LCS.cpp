#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, vector<int> b, int i, int j)
{
    if (i >= a.size() || j > b.size())
        return 0;
    if (a[i] == b[j])
        return 1 + solve(a, b, i + 1, j + 1);
    else
        return max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
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

    cout << solve(a, b, 0, 0) << endl;

    return 0;
}