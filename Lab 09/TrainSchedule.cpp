#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr, dep;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back(x);
        dep.push_back(y);
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int c = 0, maxE = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            c++;
            i++;
            maxE = max(maxE, c);
        }
        else
        {
            c--;
            j++;
        }
    }

    cout << maxE << endl;

    return 0;
}