int kruskal()
{
    int mst = 0;
    int cnt = 0;

    sort(edges.begin(), edges.end());
    DisjointSet djs(n);

    for(int u, v, w, i = 0; i < m; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;

        if(djs.unionSet(u, v))
        {
            cnt++;
            mst += w;
        }
    }
    return cnt == n - 1 ? mst : -1;
}