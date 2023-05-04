#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int l = str.length();

    bool dp[l][l];
    int count = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (i > j)
                continue;
            if (i == j)
                dp[i][j] = true;
            else if (i == j - 1)
            {
                if (str[i] == str[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if (str[i] == str[j] && dp[i + 1][j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            if (dp[i][j])
            {
                count++;
                // cout << i << " " << j << endl;
            }
        }
    }

    cout << count << endl;

    return 0;
}