#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m, counter;
    vector<int> cost, num, low;
    vector<vector<int>> graph;
    vector<bool> found;
    stack<int> st;
    ll ans, num_way;

    Graph()
    {
        cin >> n;
        cost.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>());
        for(int i = 1; i <= n; i++) cin >> cost[i];
        num.assign(n + 1, 0); low.assign(n + 1, 0);
        found.assign(n + 1, false);
        ans = 0; num_way = 1, counter = 0;
        cin >> m;
        for(int i = 0; i < m; i++)
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
            int v;
            vector<int> checkpost;
            do
            {
                v = st.top();
                st.pop();
                checkpost.push_back(v);
                found[v] = true;
            } while(v != u);

            int max_cost = MOD;
            for (int i = 0; i < (int)checkpost.size(); i++)
            {
                max_cost = min(max_cost, cost[checkpost[i]]);
            }
            ans += max_cost;

            int cnt_way = 0;
            for (int i = 0; i < (int)checkpost.size(); i++)
            {
                if(max_cost == cost[checkpost[i]])
                    cnt_way++;
            }
            num_way *= cnt_way % MOD;
            num_way %= MOD;
        }
    }
    
    void solve()
    {
        for(int i = 1; i <= n; i++)
            if(!num[i])
                dfs_tarjan(i);
        cout << ans << ' ' << num_way;
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