#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(string str1, string str2)
    {
        return str1 + str2 < str2 + str1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> vect(n);
    priority_queue<string, vector<string>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        pq.push(str);
    }
    string ans = "";
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;

    return 0;
}