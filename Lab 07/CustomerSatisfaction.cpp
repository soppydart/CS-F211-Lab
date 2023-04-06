#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int c = 0;
    while (k--)
    {
        int ori = pq.top();
        int k = ori / 2;
        if (ori % 2)
            k++;
        pq.pop();
        pq.push(ori - k);
        c += k;
    }
    cout << c << endl;

    return 0;
}