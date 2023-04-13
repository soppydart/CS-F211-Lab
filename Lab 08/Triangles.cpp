#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vect.push_back({x, y});
    }
    for (int i = 0; i < n - 1; i++)
    {
        map<pair<int, int>, int> mp;
        for (int j = i + 1; j < n; j++)
        {
            int Y = vect[j].second - vect[i].second;
            int X = vect[j].first - vect[i].first;
            int g = __gcd(X, Y);
            X /= g;
            Y /= g;
            mp[{X, Y}]++;
        }
        int num = n - i - 1;
        ans += num * (num - 1) / 2;
        for (auto it : mp)
        {
            int m = it.second;
            ans -= m * (m - 1) / 2;
        }
    }
    cout << ans << endl;

    return 0;
}