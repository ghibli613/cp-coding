#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
  int n, q; cin >> n >> q;
  vector<vector<int>> a(n + 1, vector<int>(3, 0));
  for(int i = 0; i < n; i++)
  {
    int tmp; cin >> tmp;
    a[i + 1][tmp - 1] = a[i][tmp - 1] + 1;
    for(int j = 0; j < 3; j++)
    {
      if(j != tmp - 1) a[i + 1][j] = a[i][j];
    }
  }

  for(int i = 0; i < q; i++)
  {
    int l, r; cin >> l >> r;
    for(int j = 0; j < 3; j++)
    {
      if(j != 2) cout << a[r][j] - a[l - 1][j] << ' ';
      else cout << a[r][j] - a[l - 1][j];
    }
    cout << '\n';
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
