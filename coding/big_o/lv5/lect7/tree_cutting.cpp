#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 3e5 + 7;

int n, color[N];
vector<int> graph[N];
int cntRed[N], cntBlue[N], totalRed, totalBlue, res;

void dfs(int u, int pu = 0)
{
    cntRed[u] = color[u] == 1;
    cntBlue[u] = color[u] == 2;
    for(int v : graph[u])
        if(v != pu)
        {
            dfs(v, u);
            cntRed[u] += cntRed[v];
            cntBlue[u] += cntBlue[v];
        }

    if(cntRed[u] == totalRed && cntBlue[u] == 0) res++;
    if(cntBlue[u] == totalBlue && cntRed[u] == 0) res++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
        totalRed += color[i] == 1;
        totalBlue += color[i] == 2;
    }

    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << res << '\n';

    return 0;
}