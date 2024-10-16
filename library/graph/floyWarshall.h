int floydWarshall(vector<vector<int>> &matrix, int n)
{
    dist.assign(n + 1, vector<int>(n + 1));
    path.assign(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = i == j ? 0 : matrix[i][j];
            if(i != j && dist[i][j] < INF)
            {
                path[i][j] = i;
            }
            else
            {
                path[i][j] = -1;
            }
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dist[i][k] >= INF) continue;
            for(int j = 1; j <= n; j++)
            {
                if(dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    // check negative cycle
    for(int i = 1; i <= n; i++)
    {
        if(dist[i][j] < 0) return false;
    }
}