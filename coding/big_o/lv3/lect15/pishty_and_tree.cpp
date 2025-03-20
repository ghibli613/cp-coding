#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define mp make_pair

class BIT
{
public:
    int arr[MAXN];
    int n;
    void init(int n)
    {
        this->n = n;
        fill(arr, arr + 1 + n, 0);
    }
    void update(int id, int val)
    {
        for (int i = id; i <= n; i += i & (-i))
            arr[i] ^= val;
    }
    int get(int id)
    {
        int res = 0;
        for (int i = id; i >= 1; i -= i & (-i))
            res ^= arr[i];
        return res;
    }
} bit;

vector<int> G[MAXN];
int in[MAXN], out[MAXN], cnt = 0;

void DFS(int u, int pre)
{
    cnt++;
    in[u] = cnt;
    for (int v : G[u])
        if (v != pre)
        {
            DFS(v, u);
        }
    out[u] = cnt;
}

struct edge
{
    int u, v, c;
};

struct query
{
    int u, v, c, id;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bit.init(n);
        cnt = 0;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        vector<edge> edges;
        for (int i = 1; i < n; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            edges.push_back({u, v, c});
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1, 0);
        vector<query> Q;
        int q;
        cin >> q;
        for (int iQuery = 0; iQuery < q; iQuery++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u = in[u];
            v = in[v];
            Q.push_back({u, v, c, iQuery});
        }

        // sort
        sort(edges.begin(), edges.end(), [](const edge &A, const edge &B)
             { return A.c < B.c; });
        sort(Q.begin(), Q.end(), [](const query &A, const query &B)
             { return A.c < B.c; });

        vector<int> res(q);
        int j = 0;
        for (int i = 0; i < q; i++)
        {
            while (j < (int)edges.size() && edges[j].c <= Q[i].c)
            {
                if (in[edges[j].u] > in[edges[j].v])
                    swap(edges[j].u, edges[j].v);
                bit.update(in[edges[j].v], edges[j].c);
                bit.update(out[edges[j].v] + 1, edges[j].c);
                j++;
            }
            res[Q[i].id] = bit.get(Q[i].u) ^ bit.get(Q[i].v);
        }
        for (int i = 0; i < q; i++)
            cout << res[i] << '\n';
    }
}