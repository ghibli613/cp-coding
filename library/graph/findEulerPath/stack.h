void findEulerPath(int u)
{
    stack<int> st;
    st.push(u);

    while (!st.empty())
    {
        int v = st.top();
        int i;
        for(i = 0; i < n; ++i)
            if(g[v][i] > 0)
                break;
        if(i == n)
        {
            res.push_back(v);
            st.pop();
        }
        else
        {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }
}