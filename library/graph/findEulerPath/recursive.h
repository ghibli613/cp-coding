void findEulerPath(int u)
{
    for(int v = 0; v < n; v++)
    {
        if(g[u][v] > 0)
        {
            g[u][v]--;
            g[v][u]--;
            findEulerPath(v);
        }
    }
    result.push_back(u);
}
