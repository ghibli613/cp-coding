#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

ll n, m, a, d;

ll undivisible(ll x)
{
    ll res = x;
    for(int mark = 1; mark < 1 << 5; mark++)
    {
        ll lcm = 1, cnt = 0;
        for(int i = 0; i < 5; i++)
        {
            if((1 << i) & mark)
            {
                if(lcm <= x)
                {
                    cnt++;
                    ll value = a + i * d;
                    ll gcd = __gcd(lcm, value);
                    if(lcm / gcd <= x / value)
                    {
                        lcm = lcm / gcd * value;
                    }
                    else
                        lcm = x + 1;
                }
                else 
                    break;
            }
        }
        if(lcm <= x)
        {
            if(cnt % 2)
                res -= x / lcm;
            else res += x / lcm;
        }
    }
    return res;
}

void solve()
{
    cin >> n >> m >> a >> d;
    cout << undivisible(m) - undivisible(n - 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}