#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    map<string, int> mp;
    for (int i = 0; i < str.length() - 10; i++)
    {
        mp[str.substr(i, 10)]++;
    }
    int c = 0;
    vector<string> vect;
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            c++;
            vect.push_back(it.first);
        }
    }
    cout << c << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << endl;
    }

    return 0;
}