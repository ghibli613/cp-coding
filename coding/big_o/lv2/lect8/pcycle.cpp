#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m;
    vector<vector<int>> c;
    vector<vector<bool>> link;
    vector<int> deg;
    vector<int> result;
    vector<int> costPrefix;

    Graph()
    {
        cin >> n >> m;
        c.assign(n + 1, vector<int>(n + 1, -MOD));
        link.assign(n + 1, vector<bool>(n + 1, false));
        deg.assign(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            c[u][v] = c[v][u] = w;

            link[u][v] = link[v][u] = true;
            deg[u]++;
            deg[v]++;
        }
    }

    void findEulerPath(int u)
    {
        for (int v = 1; v <= n; v++)
        {
            if (link[u][v])
            {
                link[u][v] = link[v][u] = false;
                findEulerPath(v);
            }
        }
        result.push_back(u);
    }

    bool checkRoad(int start)
    {
        int nRes = result.size() - 1;
        if (nRes != m + 1)
        {
            return false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] % 2 == 1)
                return false;
        }
        int cost = 0;
        for (int i = start; i < nRes; i++)
        {
            cost += c[result[i]][result[i + 1]];
            if (cost < 0)
                return false;
        }
        for (int i = 1; i < start; i++)
        {
            cost += c[result[i]][result[i + 1]];
            if (cost < 0)
                return false;
        }
        return true;
    }

    void solve()
    {
        result.push_back(0);
        findEulerPath(1);

        int low = MOD, start = 1;
        int nRes = result.size() - 1;
        costPrefix.assign(nRes + 1, 0);
        for (int i = 2; i <= nRes; i++)
        {
            costPrefix[i] = costPrefix[i - 1] + c[result[i]][result[i - 1]];
            if (costPrefix[i] < low)
            {
                low = costPrefix[i];
                start = i;
            }
        }

        if (!checkRoad(start))
            cout << -1;
        else
        {
            for (int i = start; i <= nRes; i++)
            {
                cout << result[i] << " ";
            }
            for (int i = 2; i <= start; i++)
            {
                cout << result[i] << " ";
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        Graph g;
        g.solve();
    }

    return 0;
}