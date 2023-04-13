#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, k, ch;
    cin >> n >> q;
    map<int, int> mp;
    while (q--)
    {
        cin >> ch;
        if (ch == 1)
        {
            cin >> k;
            if (mp.count(k))
                mp[k]--;
            else
                mp[k]++;
        }
        else if (ch == 2)
        {
            cin >> k;
            int x = -1;
            for (auto it : mp)
            {
                if (it.first >= k && it.second == 1)
                {
                    x = it.first;
                    break;
                }
            }
            cout << x << endl;
        }
        else if (ch == 3)
        {
            cin >> k;
            int x = -1;
            for (auto it : mp)
            {
                if (it.first <= k && it.second == 1)
                {
                    x = it.first;
                }
            }
            cout << x << endl;
        }
    }

    return 0;
}