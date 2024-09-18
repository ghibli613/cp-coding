#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m, counter, num_cmp;
    vector<vector<int>> graph, new_graph;
    vector<int> num, low, reg, out_deg;
    stack<int> st;
    vector<bool> found;

    Graph()
    {
        cin >> n >> m;
        counter = 0; num_cmp = 0;
        graph.assign(n + 1, vector<int>());
        new_graph.assign(n + 1, vector<int>());
        num.assign(n + 1, 0); low.assign(n + 1, 0); reg.assign(n + 1, 0);
        out_deg.assign(n + 1, 0);
        found.assign(n + 1, false);

        for(int i = 0; i< m; i++)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
        }
    }
    
    void dfs_tarjan(int u)
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
            int v; num_cmp++;
            do
            {
                v = st.top();
                st.pop();
                new_graph[num_cmp].push_back(v);
                reg[v] = num_cmp;
                found[v] = true;
            } while(v != u);
        }
    }
    
    void solve()
    {
    
        for(int i = 1; i <= n; i++)
        {
            if(!num[i])
            {
                dfs_tarjan(i);
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int v : graph[i])
            {
                if(reg[v] != reg[i])
                {
                    out_deg[reg[i]]++;
                }
            }
        }

        int count_zero_degree = 0;
        vector <int> res;

        for(int i = 1; i <= num_cmp; i++)
            if(out_deg[i] == 0)
            {
                for(int v: new_graph[i])
                    res.push_back(v);
                count_zero_degree++;
            }
        // cout << reg[2] << '\n';
        if(count_zero_degree > 1)
        {
            cout << 0;
            return;
        }

        sort(res.begin(), res.end());
        cout << (int)res.size() << '\n';
        for(int v: res)
            cout << v << ' ';
    }
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
    {
        Graph g;
        g.solve();
    }

    return 0;
}