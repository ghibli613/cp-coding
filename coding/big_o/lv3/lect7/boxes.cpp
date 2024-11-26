#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        // dp[i] stores the maximum number of boxes that can be
        // stacked up for exactly total weight i.
        vector<int> W(n + 1), L(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> W[i] >> L[i];

        vector<int> dp(3000 + 3000 + 1, 0);
        // Condisder box N, box N-1..to box 1.
        for (int box = n; box >= 1; --box)
        {
            for (int load = L[box]; load >= 0; --load)
            {
                if (dp[load])
                    dp[load + W[box]] = max(dp[load + W[box]], // The original best stack.
                                            dp[load] + 1);     // The box stack.
            }
            if (dp[W[box]] == 0)
                dp[W[box]] = 1;
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}