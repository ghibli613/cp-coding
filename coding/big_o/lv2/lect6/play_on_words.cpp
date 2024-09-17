#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<int> in, out;

    Graph():
    visited(26, false), graph(26, vector<int>()),
    in(26, 0), out(26, 0)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            int u = s[0] - 'a';
            int v = s.back() - 'a';
            graph[u].push_back(v);
            graph[v].push_back(u);
            in[v]++; out[u]++;
        }
    }
    
    void dfs(int s)
    {
        visited[s] = true;
    
        for(int i = 0; i < (int)graph[s].size(); i++)
        {
            int v = graph[s][i];
    
            if(!visited[v])
            {
                dfs(v);
            }
        }
    }

    void isEulerPath()
    {
        int cntComp = 0;
        for(int i = 0; i < 26; i++)
            if(!visited[i] && in[i] + out[i] != 0)
            {
                cntComp++;
                dfs(i);
            }
            
        if(cntComp > 1)
        {
            cout << "The door cannot be opened.\n";
            return;
        }
        int diff = 0;
        bool isEuler = true;
        for(int i = 0; i < 26; i++)
            if(abs(in[i] - out[i]) == 1)
                diff++;
            else if(abs(in[i] - out[i]) > 1)
                isEuler = false;
        if(diff > 2) isEuler = false;
        if(isEuler)
            cout << "Ordering is possible.\n";
        else cout << "The door cannot be opened.\n";
    }
};

void solve()
{
    Graph g;
    g.isEulerPath();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}