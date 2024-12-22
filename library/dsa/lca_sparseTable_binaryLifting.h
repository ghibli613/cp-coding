#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 1e5 + 10;
const int MAX_LOG = 18;

int n, l;
vector<int> graph[MAX];
int counter;
int tin[MAX], tout[MAX];
int parent[MAX][MAX_LOG];

void dfs(int u, int p)
{
    tin[u] = ++counter;
    
    parent[u][0] = p;
    for(int v : graph[u])
        if(v != p)
            dfs(v, u);
    
    tout[u] = ++counter;
}

void preprocess()
{
    counter = 0;
    l = ceil(log2(n));

    dfs(1, 1);

    for(int k = 1; k <= l; k++)
        for(int i = 1; i <= n; i++)
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
}

int isAncestor(int u, int v)
{
    return tin[u] <= tin[v] && tin[v] <= tout[u];
}

int lca(int u, int v)
{
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    for(int k = l; k >= 0; k--)
        if(!isAncestor(parent[u][k], v))
            u = parent[u][k];
    
    return parent[u][0];
}

int main()
{
    ios::sync_with_stdio(0);

    int q, u, v;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    preprocess();
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}