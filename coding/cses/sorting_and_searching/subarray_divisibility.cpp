#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> pre_sums(n + 1);
  map<int, ll> mm;
  ll ans = 0;
  mm[0]++;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    pre_sums[i + 1] = pre_sums[i] + a[i];
    ll tmp = pre_sums[i + 1] % n;
    if(tmp < 0)
    {
      tmp += n;
    }
    ans += mm[tmp];
    mm[tmp]++;
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

