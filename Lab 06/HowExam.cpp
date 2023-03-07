#include <iostream>
#include <stack>
using namespace std;

int *prevSmaller(int *arr, int n)
{
    stack<int> st;
    int *ps = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        while (!st.empty() && st.top() >= arr[i])
        {
            c++;
            st.pop();
        }
        ps[i] = st.empty() ? -1 : i - 1 - c;
        st.push(arr[i]);
    }
    return ps;
}

int *nextSmaller(int *arr, int n)
{
    stack<int> st;
    int *ns = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--)
    {
        int c = 0;
        while (!st.empty() && st.top() >= arr[i])
        {
            c++;
            st.pop();
        }
        ns[i] = st.empty() ? n : i + 1 + c;
        st.push(arr[i]);
    }
    return ns;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *ps = prevSmaller(arr, n);
    int *ns = nextSmaller(arr, n);
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        int area = (ns[i] - ps[i] - 1) * arr[i];
        if (max < area)
            max = area;
    }
    cout << max << endl;

    return 0;
}