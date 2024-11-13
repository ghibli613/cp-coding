#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_VALUE = 300;

int main()
{
    vector<vector<ll>> dp(MAX_VALUE + 1, vector<ll>(MAX_VALUE + 1, 0));

    for (int j = 0; j <= MAX_VALUE; ++j)
        dp[0][j] = 1;

    for (int i = 1; i <= MAX_VALUE; ++i)
        for (int j = 1; j <= MAX_VALUE; ++j)
            dp[i][j] = dp[i][j - 1] + (i >= j ? dp[i - j][j] : 0);

    string in;
    while (getline(cin, in))
    {
        vector<int> input;
        string num = "";
        for (char c : in)
        {
            if (c == ' ')
            {
                input.push_back(stoi(num));
                num = "";
            }
            else
            {
                num += c;
            }
        }
        input.push_back(stoi(num));

        int l1 = 0, l2 = 300;
        if (input.size() == 2)
            l2 = input[1];
        else if (input.size() == 3)
        {
            l1 = input[1];
            l2 = input[2];
        }

        vector<ll> ways(301, 0);
        ways[0] = 1;
        for (int c = l1; c <= l2; ++c)
        {
            for (int i = c; i < 301; ++i)
            {
                ways[i] += ways[i - c];
            }
        }
        if (input[0] == 0)
        {
            if(l1 == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else
            cout << dp[input[0]][min(300, l2)] - dp[input[0]][min(300, max(0, l1 - 1))] << '\n';
    }
}