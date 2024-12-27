#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;

int parent[MAX];
int Rank[MAX];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        Rank[i] = 1;
    }
}

int findSet(int u)
{
    if (parent[u] != u)
        parent[u] = findSet(parent[u]);
    return parent[u];
}

bool unionSet(int u, int v)
{
    int pu = findSet(u), pv = findSet(v);
    if (pu == pv)
        return false;
    if (Rank[pu] > Rank[pv])
        parent[pv] = pu;
    else if (Rank[pu] < Rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        Rank[pu]++;
    }
    return true;
}

int main()
{
    int n, q, t, u, v;
    cin >> n >> q;
    makeSet(n);

    while (q--)
    {
        cin >> t >> u >> v;
        if(t == 1)
            unionSet(u, v);
        else
        {
            int pu = findSet(u);
            int pv = findSet(v);
            cout << (pu == pv ? "YES\n" : "NO\n");
        }
    }
    return 0;
}