#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dq.push_back(0);
    for (int i = 1; i < k; i++)
    {
        if (arr[i] > arr[dq.front()])
        {
            while (!dq.empty())
                dq.pop_back();
            dq.push_back(i);
        }
        else
        {
            if (dq.size() == 1)
                dq.push_back(i);
            else if (arr[i] > arr[dq.back()])
            {
                dq.pop_back();
                dq.push_back(i);
            }
        }
    }
    cout << arr[dq.front()] << " ";

    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k)
        {
            dq.pop_front();
            dq.push_back(i);
        }
        if (arr[i] > arr[dq.front()])
        {
            while (!dq.empty())
                dq.pop_back();
            dq.push_back(i);
        }
        else
        {
            if (dq.size() == 1)
                dq.push_back(i);
            else if (arr[i] > arr[dq.back()])
            {
                dq.pop_back();
                dq.push_back(i);
            }
        }
        cout << arr[dq.front()] << " ";
    }
    cout << endl;

    return 0;
}