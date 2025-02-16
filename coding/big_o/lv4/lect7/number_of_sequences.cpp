#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n + 1, 0), f(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + i; j <= n; j += i)
        {
            if(a[j] != -1)
            {
                if(a[i] != -1 && a[j] % i != a[i])
                {
                    cout << 0;
                    return 0;
                }
                a[i] = a[j] % i;
            }
            if(i > 1) f[j] = 1;
        }
    }

    ll ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!f[i])
        {
            ll p = i;
            while(p <= n)
            {
                if(a[p] == -1)
                {
                    ans = (ans * i) % mod;
                }
                p *= i;
            }
        }
    }

    cout << ans;

    return 0;
}