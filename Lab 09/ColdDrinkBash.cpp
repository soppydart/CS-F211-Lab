#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end(), greater<int>());
    int c = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vect[i];
        if (sum < 0)
            break;
        c++;
    }
    cout << c << endl;

    return 0;
}