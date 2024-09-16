#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

vector<vector<int>> graph;

struct Graph
{
    vector<vector<int>> graph;
    vector<int> num, low;
    vector<bool> found;
    int counter, n, m;
    map<string, int> id;
    map<int, string> name;
    stack<int> st;

    Graph(int n = 0, int m = 0):
        graph(n + 1, vector<int>()),
        num(n + 1), low(n + 1), found(n + 1), 
        n(n), m(m)
        {
            int cnt = 0;
            for(int i = 1; i <= m; i ++) 
            {
                string u, v;
                cin >> u >> v;
                if(!id[u]) {
                    cnt ++;
                    id[u] = cnt;
                    name[cnt] = u;
                }
                if(!id[v]) {
                    cnt ++;
                    id[v] = cnt;
                    name[cnt] = v;
                }
                graph[id[u]].push_back(id[v]);
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
            string ans = "";
            do
            {
                v = st.top();
                st.pop();
                ans += name[v];
                ans += ", ";
                found[v] = true;
            } while(v != u);
            ans.pop_back(); ans.pop_back();
            cout << ans << "\n";
        }
    }
    
    void tarjan()
    {
        counter = 0;
        low.assign(n + 1, 0);
        num.assign(n + 1, 0);
    
        found.assign(n + 1, false);
        counter = 0;
        st = stack<int>();
    
        for(int i = 1; i <= n; i++)
        {
            if(!num[i])
            {
                dfs_tarjan(i);
            }
        }
    }
    
};

void solve(int n, int m)
{
    Graph g(n, m);
    g.tarjan();
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    // cin >> t;

    while(true)
    {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cout << "Calling circles for data set " << tc << ":\n";
        solve(n, m);
        tc++;
    }

    return 0;
}