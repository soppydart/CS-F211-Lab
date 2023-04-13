#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    cin >> x >> y;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        mp[vect[i] - x * i].push_back(i);
    int c = 0;
    for (int j = 0; j < n; j++)
    {
        int k = vect[j] - y * j;
        vector<int> temp = mp[k];
        for (int i = 0; i < temp.size(); i++)
        {
            if (j > temp[i])
                c++;
        }
    }
    cout << c << endl;
    return 0;
}