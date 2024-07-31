#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int vertex, int n)
{
    vector<bool> path(n);
    stack<int> st;
    st.push(vertex);
    visited[vertex] = true;
    path[vertex] = true;
    int u, v;
    while(!st.empty())
    {
        u = st.top();
        st.pop();
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            v = adj[u][i];
            if(!visited[v])
            {
                path[v] = true;
                visited[v] = true;
                st.push(v);
            }
            else if(path[v]) return true;
        }
    }
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;
    adj.assign(n, vector<int>());
    visited = vector<bool>(n);
    vector<bool> num_par(n);
    bool flag = false;
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;

        if(!num_par[y - 1]) num_par[y - 1] = true;
        else
        {
            flag = true;
        }
        adj[x - 1].push_back(y - 1);
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        if(dfs(i, n))
        {
            flag = true;
            break;
        }
    }
    if(flag) cout << 0;
    else cout << 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 3;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}