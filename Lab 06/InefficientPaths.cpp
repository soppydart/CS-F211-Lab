#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<string> st1;
    string word = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '/')
        {
            if (word != "")
                st1.push(word);
            word = "";
        }
        else
            word = str[i] + word;
    }
    stack<string> st2;

    while (!st1.empty())
    {
        st2.push(st1.top());
        if (st2.top() == ".")
            st2.pop();
        else if (st2.top() == "..")
        {
            st2.pop();
            if (!st2.empty())
                st2.pop();
        }
        st1.pop();
    }

    string ans = "";
    if (st2.empty())
        ans = "/";
    else
    {
        while (!st2.empty())
        {
            ans = "/" + st2.top() + ans;
            st2.pop();
        }
    }
    cout << ans << endl;

    return 0;
}