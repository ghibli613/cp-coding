#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct DisjointSet
{
    vector<int> parent, Rank;
    DisjointSet(): parent(26), Rank(26, 0)
    {
        for (int i = 0; i < 26; i++)
            parent[i] = i;
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
};

struct Graph
{
    int n;
    vector<string> s;
    vector<pii> edges;
    vector<bool> mark;
    vector<int> in_deg, out_deg;
    DisjointSet dsu;
    vector<int> ans, vi;

    Graph()
    {
        cin >> n;
        s.assign(n, "");
        vi.assign(n, 0);
        mark.assign(26, 0);
        in_deg.assign(26, 0);
        out_deg.assign(26, 0);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            int u = s[i][0] - 'a', v = s[i][s[i].size() - 1] - 'a';
            mark[u] = mark[v] = true;
            edges.push_back({u, v});
            in_deg[v]++;
            out_deg[u]++;

            dsu.unionSet(u, v);
        }
    }

    bool checkConnected()
    {
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (mark[i])
                if (dsu.findSet(i) == i)
                    cnt++;
        return (cnt == 1);
    }

    void euler(int u)
    {
        for (int i = 0; i < n; i++)
            if (!vi[i] && edges[i].first == u)
            {
                vi[i] = 1;
                euler(edges[i].second);
                ans.push_back(i);
            }
    }
    void solve()
    {
        int start = edges[0].first;
        bool ck = true;
        int node1 = 0, node2 = 0;
        for (int i = 0; i < 26; i++)
        {
            if (in_deg[i] == out_deg[i])
                continue;
            else if (in_deg[i] - out_deg[i] == 1)
                node1++;
            else if (out_deg[i] - in_deg[i] == 1)
                node2++, start = i;
            else
            {
                ck = false;
                break;
            }
        }
        if (ck == true && ((node1 == node2 && node1 == 0) || (node1 == node2 && node1 == 1)) && checkConnected())
        {
            euler(start);
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < (int)ans.size(); i++)
            {
                cout << s[ans[i]];
                if (i < (int)ans.size() - 1)
                    cout << '.';
            }
        }
        else
            cout << "***";
        cout << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        Graph g;
        g.solve();
    }

    return 0;
}