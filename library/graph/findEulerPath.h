void findEulerPath(int u)
{
    for(int v = 0; v < n; v++)
    {
        if(g[u][v] > 0)
        {
            g[u][v]--;
            g[v][u]--;
            findEulerPath_recursive(v);
        }
    }
    result.push_back(u);
}

// void findEulerPath(int u)
// {
//     stack<int> st;
//     st.push(u);

//     while (!st.empty())
//     {
//         int v = st.top();
//         int i;
//         for(i = 0; i < n; ++i)
//             if(g[v][i] > 0)
//                 break;
//         if(i == n)
//         {
//             res.push_back(v);
//             st.pop();
//         }
//         else
//         {
//             --g[v][i];
//             --g[i][v];
//             st.push(i);
//         }
//     }
// }