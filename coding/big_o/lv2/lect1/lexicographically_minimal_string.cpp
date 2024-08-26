#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int parent[26];

int findSet(int u)
{
    if(parent[u] != u)
    {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v)
{
    int pu = findSet(u);
    int pv = findSet(v);
    
    if(pu == pv) return;
    else if(pu > pv) parent[pu] = pv;
    else parent[pv] = pu;
}

void solve()
{
    string a, b, c; cin >> a >> b >> c;
    for(int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < (int)a.size(); i++)
    {
        unionSet(a[i] - 'a', b[i] - 'a');
    }
    
    for(int i = 0; i < (int)c.size(); i++)
    {
        cout << (char)(findSet(c[i] - 'a') + 'a');
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