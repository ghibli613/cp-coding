struct Graph
{
    struct Edge
    {
        int u, v, w;
        Edge(int u = 0, int v = 0, int w = 0)
            : u(u), v(v), w(w) {}
    };

    vector<vector<pii>> adj;
    vector<int> dist, path;
    vector<bool> visited;
    vector<Edge> edges;
    vector<vector<int>> matrix, dist_matrix, path_matrix;

    Graph(int n = 0, int m = 0): 
        adj(n + 1, vector<pii>()), 
        dist(n + 1, MOD), 
        path(n + 1, -1),
        visited(n + 1, false),
        edges(m),
        matrix(n + 1, vector<int>(n + 1)),
        dist_matrix(n + 1, vector<int>(n + 1)),
        path_matrix(n + 1, vector<int>(n + 1)) {}
    
    void bfs(int s)
    {
        queue<int> q;
    
        q.push(s);
        visited[s] = true;
    
        int u, v;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                if(!visited[v])
                {
                    visited[v] = true;
                    path[v] = u;
                    q.push(v);
                }
            }
        }
    }

    void dfs_recursive(int s)
    {
        visited[s] = true;
    
        for(int i = 0; i < (int)adj[s].size(); i++)
        {
            int v = adj[s][i].first;
    
            if(!visited[v])
            {
                path[v] = s;
                dfs_recursive(v);
            }
        }
    }

    void dfs_stack(int s)
    {
        stack<int> st;
    
        st.push(s);
        visited[s] = true;
    
        int u, v;
        while(!st.empty())
        {
            u = st.top();
            st.pop();
            for(int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                if(!visited[v])
                {
                    visited[v] = true;
                    path[v] = u;
                    st.push(v);
                }
            }
        }
    }
    
    void dijkstra(int s)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        dist[s] = 0;
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            int u = tmp.second;
            if(tmp.first != dist[u]) continue;
            for(int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int bellmanFord(int n, int m, int s)
    {
        dist[s] = 0;
        int u, v, w;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                u = edges[j].u;
                v = edges[j].v;
                w = edges[j].w;
                if(dist[u] != MOD && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    path[v] = u;
                }
            }
        }
        for(int j = 0; j < m; j++)
        {
            u = edges[j].u;
            v = edges[j].v;
            w = edges[j].w;
            if(dist[u] != MOD && dist[v] > dist[u] + w)
            {
                return false;
            }
        }
        return true;
    }

    int floydWarshall(vector<vector<int>> &matrix, int n)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist_matrix[i][j] = i == j ? 0 : matrix[i][j];
                if(i != j && dist_matrix[i][j] < MOD)
                {
                    path_matrix[i][j] = i;
                }
                else
                {
                    path_matrix[i][j] = -1;
                }
            }
        }
        for(int k = 1; k <= n; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                if(dist_matrix[i][k] >= MOD) continue;
                for(int j = 1; j <= n; j++)
                {
                    if(dist_matrix[k][j] < MOD && dist_matrix[i][j] > dist_matrix[i][k] + dist_matrix[k][j])
                    {
                        dist_matrix[i][j] = dist_matrix[i][k] + dist_matrix[k][j];
                        path_matrix[i][j] = path_matrix[k][j];
                    }
                }
            }
        }
        // check negative cycle
        for(int i = 1; i <= n; i++)
        {
            if(dist_matrix[i][i] < 0) return false;
        }
    }
};