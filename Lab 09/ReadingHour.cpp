#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect[i];
    sort(vect.begin(), vect.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++)
        pq.push(0);
    for (int i = 0; i < n; i++)
    {
        int x = pq.top();
        x += vect[i];
        pq.pop();
        pq.push(x);
    }
    for (int i = 0; i < n - 1; i++)
        pq.pop();
    cout << pq.top() << endl;

    return 0;
}