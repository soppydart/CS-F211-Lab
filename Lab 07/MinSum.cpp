#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }
    while (m--)
    {
        int k = pq.top();
        k /= 2;
        pq.pop();
        pq.push(k);
    }
    int sum = 0;
    while (pq.size())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;

    return 0;
}