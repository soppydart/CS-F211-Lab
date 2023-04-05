#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    int k, c = 0;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<queue<int>> vect(k);
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            vect.at(i).push(x);
            c++;
        }
    }
    while (c--)
    {
        int minEl = INT_MAX;
        int index = 0;
        for (int i = 0; i < k; i++)
        {
            if (vect.at(i).size() != 0)
            {
                if (vect.at(i).front() < minEl)
                {
                    index = i;
                    minEl = vect.at(i).front();
                }
            }
        }
        pq.push(minEl);
        vect.at(index).pop();
    }
    while (pq.size())
    {
        int x = pq.top();
        cout << x << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}