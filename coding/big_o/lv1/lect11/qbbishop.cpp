#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m, stX, stY, enX, enY;
    cin >> n >> m >> stX >> stY >> enX >> enY;
    vector<vector<bool>> obs(n, vector<bool>(n));
    vector<vector<int>> d(n, vector<int>(n));
    const int dx[4] = {-1, -1, 1, 1};
    const int dy[4] = {-1, 1, -1, 1};
    for(int i = 0; i < m; i++)
    {
        int x, y; 
        cin >> x >> y;
        obs[x - 1][y - 1] = true;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = INT_MAX;
    
    queue<pair<int, int>> q;
    d[stX - 1][stY - 1] = 0;
    q.push({stX - 1, stY - 1});
    while(!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int step = 1;
            while(true)
            {
                int x = u + dx[i] * step;
                int y = v + dy[i] * step;
                if(x < 0 || x > n - 1 || y < 0 || y > n - 1) break;
                if(obs[x][y]) break;
                if(d[x][y] > d[u][v] + 1)
                {
                    d[x][y] = d[u][v] + 1;
                    q.push({x, y});
                }
                step++;
            }
        }
    }
    if(d[enX - 1][enY - 1] == INT_MAX)
        cout << -1;
    else cout << d[enX - 1][enY - 1];
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