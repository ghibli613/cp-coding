void tarjan(int u)
{
    counter++;
    num[u] = low[u] = counter;
    st.push(u);

    for(int v : graph[u])
    {
        if(!found[v])
        {
            if(num[v] > 0)
                low[u] = min(low[u], num[v]);
            else
            {
                dfs_tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if(num[u] == low[u])
    {
        cout << "Found a SCC:";
        int v;
        do
        {
            v = st.top();
            st.pop();
            cout << " " << v;
            found[v] = true;
        } while(v != u);
        cout << "\n";
    }
}