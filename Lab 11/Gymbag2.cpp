#include <bits/stdc++.h>
using namespace std;

int solve(int n, int w, int i, int s, int wi, vector<int> weight, vector<int> value)
{
    if (wi > w)
        return -1;
    if (i >= n)
        return s;
    int a = solve(n, w, i + 1, s, wi, weight, value);
    int b = solve(n, w, i + 1, s + value[i], wi + weight[i], weight, value);
    return max(a, b);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    cout << solve(n, w, 0, 0, 0, weight, value) << endl;

    return 0;
}