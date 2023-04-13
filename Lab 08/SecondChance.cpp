#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> lmap, wmap;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (!lmap.count(x))
            lmap[x] = 0;
        lmap[y]++;
    }
    vector<int> ans;
    for (auto it : lmap)
    {
        if (it.second <= 1)
            ans.push_back(it.first);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}