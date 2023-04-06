#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)
        cin >> v1.at(i);
    for (int i = 0; i < n; i++)
        cin >> v2.at(i);
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = v1.at(i) + v2.at(j);
            if (pq.size() < k)
                pq.push(sum);
            else if (sum > pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
            else
                break;
        }
    }
    stack<int> ans;
    while (pq.size())
    {
        ans.push(pq.top());
        pq.pop();
    }
    while (ans.size())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}