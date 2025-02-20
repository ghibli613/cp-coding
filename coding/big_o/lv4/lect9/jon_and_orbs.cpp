#include<bits/stdc++.h>
using namespace std;
 
const double eps = 1e-7;
 
int k, Q;
double dp[7301][1003];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k >> Q;
    dp[0][0] = 1;
    for (int i = 1; i <= 7300; i++)
    {
        for (int x = 1; x <= k; x++)
        {
            dp[i][x] = dp[i - 1][x] * x / k + dp[i - 1][x - 1] * (k - x + 1) / k;
        }
    }
 
    while (Q--)
    {
        double p;
        cin >> p;
 
        for (int n = k; n <= 7300; n++)
        {
            if (dp[n][k] * 2000 >= p - eps)
            {
                cout << n << '\n';
                break;
            }
        }
    }
 
    return 0;
}

// https://en.wikipedia.org/wiki/Coupon_collector%27s_problem