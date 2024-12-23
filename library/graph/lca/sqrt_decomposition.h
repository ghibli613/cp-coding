#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 1e5 + 10;
int n;
vector<int> graph[MAX];
int block_size;
int level[MAX], parent[MAX], jump_parent[MAX];

int getDepth(int u, int p)
{
    int res = 0;
    for(int v : graph[u])
        if(v != p)
            res = max(res, getDepth(v, u));
    return res + 1;
}

void dfs(int u, int p)
{
    level[u] = level[p] + 1;
    parent[u] = p;
    if(level[u] % block_size == 0)
        jump_parent[u] = p;
    else
        jump_parent[u] = jump_parent[p];
    
    for(int v : graph[u])
    {
        if(v != p)
            dfs(v, u);
    }
}

void dfs(int u, int p)
{
    level[u] = level[p] + 1;
    parent[u] = p;
    if(level[u] % block_size == 0)
        jump_parent[u] = p;
    else
        jump_parent[u] = jump_parent[p];

    for(int v : graph[u])
    {
        if(v != u)
            dfs(v, u);
    }
}

void preprocess()
{
    int height = getDepth(0, 1);
    block_size = sqrt(height);
    level[0] = -1;
    dfs(1, 0);
}

int lca(int u, int v)
{
    if(level[u] > level[v]) swap(u, v);
    while(level[u] < level[v])
    {
        if(level[jump_parent[v]] > level[u])
            v = jump_parent[v];
        else
            v = parent[v];
    }
    while (u != v)
    {
        if(jump_parent[u] == jump_parent[v])
        {
            u = parent[u];
            v = parent[v];
        }
        else
        {
            u = jump_parent[u];
            v = jump_parent[v];
        }
    }
    
    return u;
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