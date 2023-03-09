#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> st;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (st.empty())
        {
            st.push(str[i]);
            continue;
        }
        if (str[i] == '(' && st.top() == ')' ||
            str[i] == ')' && st.top() == '(')
            st.pop();
        else
            st.push(str[i]);
    }
    int c = 0;
    while (!st.empty())
    {
        c++;
        st.pop();
    }
    cout << c << endl;

    return 0;
}