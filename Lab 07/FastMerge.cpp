#include <iostream>
#include <vector>
#include <queue>
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
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}