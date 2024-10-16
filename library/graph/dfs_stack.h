void dfs(int s)
{
    int sz = adj.size();
    path.assign(sz, -1);
    visited.assign(sz, false);
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
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                path[v] = u;
                st.push(v);
            }
        }
    }
}