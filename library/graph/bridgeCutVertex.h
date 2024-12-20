void bridgeCutVertex(int u, int p)
{
    counter++;
    num[u] = low[u] = counter;
    int numChild = 0;

    for(int v : graph[u])
    {
        if(v == p) continue;
        if(num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            bridgeCutVertex(v, u);
            low[u] = min(low[u], low[v]);
            numChild++;
            if(low[v] > num[u])
                bridge.push_back(make_pair(u, v));
            if(low[v] >= num[u] && p != -1)
                isCut[u] = true;
        }
    }
    if(p == -1 && numChild > 1)
        isCut[u] = true;
}