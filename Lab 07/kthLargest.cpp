#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != -1)
            vect.push_back(x);
    }
    cin >> k;
    k--;
    sort(vect.begin(), vect.end());
    while (k--)
        vect.pop_back();
    cout << vect.back() << endl;
}