#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    int *pass = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
        st.push(arr[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        int popCount = 0;
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
            popCount++;
        }
        if (st.empty())
        {
            pass[i] = -1;
            st.push(arr[i]);
        }
        else
        {
            int a = popCount + 1;
            pass[i] = a;
            while (a--)
                st.push(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << pass[i] << " ";
    cout << endl;

    return 0;
}