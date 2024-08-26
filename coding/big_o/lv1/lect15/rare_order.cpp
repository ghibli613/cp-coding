#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector<bool> present(26);
vector<bool> visited(26);
vector<vector<int>> adj;
vector<int> ans;

void dfs(int u) 
{
	visited[u] = 1;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}

	ans.push_back(u);
}

void solve()
{
    vector<string> index;
    while(true)
    {
        string tmp; cin >> tmp;
        if(tmp == "#") break;
        index.push_back(tmp);
    }

    adj.assign(26, vector<int>());
    int n = index.size();

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < min((int)index[i].size(),(int)index[i + 1].size()); j++)
            if(index[i][j] != index[i+1][j])
            {
                present[index[i][j]-'A'] = present[index[i+1][j]-'A'] = 1;
                adj[index[i][j] - 'A'].push_back(index[i + 1][j] - 'A');
                break;
            }
    
    for (int i = 0; i < 26; i++)
		if (!visited[i] && present[i])
			dfs(i);
	
    
    for (int i = (int)ans.size() - 1; i >= 0; i--) cout << char(ans[i] + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}