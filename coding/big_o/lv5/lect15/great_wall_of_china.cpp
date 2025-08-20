#include <bits/stdc++.h>
using namespace std;

struct MinCostMaxFlow
{
    const long long INF = 1e15;

    struct dataEdge
    {
        int from, to;
        long long cap, cost;
    };

    int N, S, T;
    long long K;
    vector<dataEdge> E;
    vector<vector<int>> adj;
    vector<long long> pre, dist;

    MinCostMaxFlow(int _N, long long _K, int src, int sink)
    {
        N = _N, K = _K;
        S = src, T = sink;
        adj.resize(_N);
        pre.resize(_N);
        dist.resize(_N);
    }

    void addEdge(int u, int v, long long cap, long long cost)
    {
        dataEdge e1 = {u, v, cap, cost};
        dataEdge e2 = {v, u, 0, -cost};
        adj[u].push_back(E.size());
        E.push_back(e1);
        adj[v].push_back(E.size());
        E.push_back(e2);
    }

    bool spfa()
    {
        fill(dist.begin(), dist.end(), INF);
        vector<bool> inq(N, false);
        queue<int> q;
        dist[S] = 0;
        q.push(S);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u])
            {
                int v = E[id].to;
                long long cap = E[id].cap, cost = E[id].cost;
                if (dist[v] <= dist[u] + cost || cap <= 0)
                    continue;
                dist[v] = dist[u] + cost, pre[v] = id;
                if (!inq[v])
                    q.push(v), inq[v] = true;
            }
        }

        return dist[T] != INF;
    }

    long long minCost()
    {
        long long maxFlow = 0, res = 0;

        while (maxFlow < K)
        {
            if (!spfa())
                break;

            long long flow = K - maxFlow;

            int cur = T;
            while (cur != S)
            {
                int id = pre[cur];
                flow = min(flow, E[id].cap);
                cur = E[id].from;
            }

            maxFlow += flow, res += flow * dist[T];

            cur = T;
            while (cur != S)
            {
                int id = pre[cur];
                E[id].cap -= flow;
                E[1 ^ id].cap += flow;
                cur = E[id].from;
            }
        }

        if (maxFlow != K)
            return -1;
        else
            return res;
    }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

#define _(x, y) x *n + y

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<string> s(5);

        for (int i = 0; i < 5; i++)
            cin >> s[i];

        int base = 5 * n;
        int source = base + base;
        int sink = base + base + 1;

        int numNode = base + base + 2;

        MinCostMaxFlow flow(numNode, 3, source, sink);
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < n; j++)
            {
                for (int t = 0; t < 4; t++)
                {
                    int u = i + dx[t];
                    int v = j + dy[t];
                    if (u < 0 || u >= 5 || v < 0 || v >= n)
                        continue;
                    flow.addEdge(_(i, j) + base, _(u, v), 1, 0);
                }
                int price = (isdigit(s[i][j]) ? s[i][j] - '0' : 0);
                flow.addEdge(_(i, j), _(i, j) + base, 1, price);
            }

        for (int i = 0; i < 5; i++)
        {
            if (s[i][0] == '@')
                flow.addEdge(source, _(i, 0), 1, 0);
            flow.addEdge(_(i, n - 1) + base, sink, 1, 0);
        }

        cout << flow.minCost() << '\n';
    }

    return 0;
}