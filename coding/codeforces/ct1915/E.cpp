#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i< n; i++) cin >> a[i];
    
    set<ll> minus;
    ll sum_odd = 0, sum_even = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) sum_even += a[i];
        else sum_odd += a[i];
        ll tmp = sum_even - sum_odd;
        if(tmp == 0)
        {
            cout << "YES\n";
            return;
        }
        if(minus.find(tmp) != minus.end())
        {
            cout << "YES\n";
            return;
        }
        minus.insert(tmp);
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}