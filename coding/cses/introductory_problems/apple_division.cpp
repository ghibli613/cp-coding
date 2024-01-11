#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int power_2(int n)
{
    int res = 1;
    for(int i = 0; i < n; i++) res *= 2;
    return res;
}

void solve()
{
    int n; cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(ll &i : a)
    {
        cin >> i;
        sum += i;
    }
    int num_bit_sets = power_2(n);
    ll ans = sum;;
    for(int i = 0; i < num_bit_sets; i++)
    {
        ll sum1 = 0;
        for(int j = 0; j < n; j++)
            if((1 << j) & i) sum1 += a[j];
        if(ans > abs(2 *sum1 - sum)) ans = abs(2 *sum1 - sum);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}