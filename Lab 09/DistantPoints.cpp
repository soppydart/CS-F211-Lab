#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end());
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] - vect[0] >= k)
        {
            p = i;
            // cout << p << " " << vect[i] << " " << vect[0] << endl;
            break;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    for (int i = 0; i < p; i++)
        pq1.push(vect[i]);
    for (int i = p; i < n; i++)
        pq2.push(vect[i]);
    int c = 0;

    while (!pq1.empty() && !pq2.empty())
    {
        if (pq2.top() - pq1.top() >= k)
        {
            c++;
            // cout << pq1.top() << " " << pq2.top() << endl;
            pq1.pop();
            pq2.pop();
        }
        else
        {
            // cout << pq1.top() << " " << pq2.top() << endl;
            pq2.pop();
        }
    }
    cout << c << endl;

    return 0;
}