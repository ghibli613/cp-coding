#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

int n;
int root = 1;
vector<int> graph[N];
vector<int> T[N];
int counter;
int tin[N], tout[N];
ll f[N];
int w[N];

void DFS(int u, int par)
{
    tin[u] = ++counter;
    f[u] = w[u];
    for (int v : graph[u])
    {
        if (v != par)
        {
            DFS(v, u);
            f[u] += f[v];
            T[u].push_back(tin[v]);
        }
    }
    tout[u] = ++counter;
}

bool isAncestor(int u, int v)
{
    return tin[u] < tin[v] && tin[v] < tout[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    
    for (int i = 2; i <= n; i++)
    {
        int par;
        cin >> par;
        graph[par].push_back(i);
    }

    DFS(1, 1);

    int Q;
    cin >> Q;
    while (Q--)
    {
        char type;
        int a;
        cin >> type >> a;
        if (type == 'R')
            root = a;
        else
        {
            if (root == a)
                cout << f[1] << endl;
            else if (isAncestor(a, root))
            {
                int id = upper_bound(T[a].begin(), T[a].end(), tin[root]) - T[a].begin() - 1;
                cout << f[1] - f[graph[a][id]] << endl;
            }
            else
                cout << f[a] << endl;
        }
    }
}