#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> dp(n, 0);
    stack<int> st;
    int length = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            st.push(i);
            continue;
        }
        if (st.empty())
            continue;
        int j = st.top();
        st.pop();
        dp[i] = i - j + 1 + (j >= 1 ? dp[j - 1] : 0);
        if (dp[i] > length)
        {
            length = dp[i];
            cnt = 1;
        }
        else if (dp[i] == length)
            cnt++;
    }
    cout << length << endl;

    return 0;
}