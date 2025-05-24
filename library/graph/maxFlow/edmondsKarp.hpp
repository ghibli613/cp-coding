const int MAX = 100;
const int INF = 1e9;

int cap[MAX][MAX];
int flow[MAX][MAX];
int parent[MAX];
vector<int> graph[MAX];

int bfs(int s, int t)
{
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    queue<pair<int, int>> q;

    q.push({s, INF});
    while(!q.empty())
    {
        int u = q.front().first, f = q.front().second;
        q.pop();

        for(int v : graph[u])
        {
            if(parent[v] == -1 && cap[u][v] > flow[u][v])
            {
                parent[v] = u;
                int newFlow = min(f, cap[u][v] - flow[u][v]);
                if(v == t) return newFlow;
                q.push({v, newFlow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int s, int t)
{
    int newFlow, sumFlow = 0;
    while((newFlow = bfs(s, t)) != 0)
    {
        sumFlow += newFlow;
        int prev, cur = t;
        while(cur != s)
        {
            prev = parent[cur];
            flow[prev][cur] += newFlow;
            flow[cur][prev] -= newFlow;
            cur = prev;
        }
    }
    return sumFlow;
}