#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  ll n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll & i : a) cin >> i;
  vector<ll> prefix_sums(n + 1);
  for(ll i = 0; i < n; i++)
  {
    prefix_sums[i + 1] += prefix_sums[i] + a[i]; 
  }
  for(ll i = 0; i < q; i++)
  {
    ll r, l; cin >> l >> r;
    cout << prefix_sums[r] - prefix_sums[l] << '\n';
  }
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
