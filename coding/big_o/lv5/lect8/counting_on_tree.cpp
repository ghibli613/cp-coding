#include<bits/stdc++.h>
using namespace std;
 
const int N = 50004;
const int MOD = 1e9 + 7;
 
int n, K, a[N];
vector<int> g[N];
long long f[N][105], res;
 
void dfs(int u, int par)
{
    f[u][a[u]] = 1;
    for (int v: g[u])
    {
        if (v == par) continue;
        dfs(v, u);
 
        for (int x = K; x >= 0; x--)
        {
            for (int xv = 0; xv <= x; xv++)
            {
                f[u][x] = (f[u][x] + f[u][x - xv] * f[v][xv]) % MOD;
            }
        }
    }
    res = (res + f[u][K]) % MOD;
}
 
void solve()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    res = 0;
    dfs(1, 1);
    cout << res << '\n';
 
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        for (int x = 0; x <= K; x++)
        {
            f[i][x] = 0;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        solve();
    }
    return 0;
}