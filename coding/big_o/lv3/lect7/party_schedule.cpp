#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;

    while (true)
    {
        cin >> w >> n;
        if (n == 0 && w == 0)
            break;

        vector<int> dp(w + 1, 0);
        vector<int> weight(n), profit(n);

        for(int i = 0; i < n; i++) cin >> weight[i] >> profit[i];

        for (int i = 0; i < n; i++)
            for (int j = w; j >= weight[i]; j--)
            {
                if (dp[j] < dp[j - weight[i]] + profit[i])
                    dp[j] = dp[j - weight[i]] + profit[i];
            }

        for(int i = w; i > 0; i--)
        {
            if(dp[i] != dp[i - 1])
            {
                cout << i << ' ';
                break;
            }
        }
        cout << dp[w] << '\n';
    }

    return 0;
}