#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n; cin >> n;
  vector<ll> a(n), prefix_sums(n + 1);
  vector<ll> n_7(7, -1);
  n_7[0] = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    prefix_sums[i + 1] = prefix_sums[i] + a[i];
    ll tmp = prefix_sums[i + 1] % 7;
    if(n_7[tmp] == -1)
    {
      n_7[tmp] = i + 1;
    }
    else
    {
      ans = max(i + 1 - n_7[tmp], ans);
    }
  }
  cout << ans << '\n';
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

