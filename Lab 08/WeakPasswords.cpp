#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<vector<int>, int> mp;
    vector<string> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    for (int i = 0; i < n; i++)
    {
        string str = vect[i];
        vector<int> lcount(26, 0);
        for (int j = 0; j < str.length(); j++)
        {
            char ch = str[j];
            lcount[ch - 97]++;
        }
        mp[lcount]++;
    }
    int c = 0;
    for (auto it : mp)
    {
        c += it.second * (it.second - 1) / 2;
    }
    cout << c << endl;

    return 0;
}