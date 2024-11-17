#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coins = {5, 10, 20, 50, 100, 200};
    vector<int> dp(505, 1e9);

    dp[0] = 0;
    for (int coin : coins)
        for (int i = coin; i < 500; i++)
            dp[i] = min(dp[i], dp[i - coin] + 1);

    vector<int> have(6);
    double in;
    while (true)
    {
        cin >> have[0] >> have[1] >> have[2] >> have[3] >> have[4] >> have[5];
        if (have[0] + have[1] + have[2] + have[3] + have[4] + have[5] == 0)
            break;

        cin >> in;
        int val = round(in * 100);
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += coins[i] * have[i];

        vector<int> dpGive(505, 1e9);
        dpGive[0] = 0;
        // compute minimum number of ways to get x value with given coins
        // kinda similar to knapsack
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < have[i]; j++)
                for (int k = min(500, sum); k >= coins[i]; k--)
                    dpGive[k] = min(dpGive[k], dpGive[k - coins[i]] + 1);

        int res = 1e9;
        for (int i = val; i <= min(500, sum); i++)
            res = min(res, dpGive[i] + dp[i - val]);
        printf("%3d\n", res);
    }

    return 0;
}