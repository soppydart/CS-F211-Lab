#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    int arr[n], spread[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int popCount = 0;
        while (!st.empty() && arr[i] >= st.top())
        {
            st.pop();
            popCount++;
        }
        spread[i] = ++popCount;
        while (popCount--)
            st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << spread[i] << " ";
    cout << endl;

    return 0;
}