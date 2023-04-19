#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, l, r, c = 0;
    cin >> n >> q;
    vector<int> vect(n, 0);
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '*')
            c++;
        vect[i] = c;
    }
    while (q--)
    {
        cin >> l >> r;
        cout << vect[r] - vect[l] << endl;
    }

    return 0;
}