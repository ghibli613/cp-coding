#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> dist;

const int INF = 1e8 + 7;

void floydWarshall(vector<vector<int>> &matrix, int n)
{
    dist.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = i == j ? 0 : matrix[i][j];
        }
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(dist[i][k] >= INF) continue;;
            for(int j = 0; j < n; j++)
            {
                if(dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if(dist[i][j] < -150 * 1000) dist[i][j] = -INF;
                }
            }
        }
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(dist[i][k] >= INF) continue;;
            for(int j = 0; j < n; j++)
            {
                if(dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = -INF;
                }
            }
        }
    }
}
void solve(int n, int m, int q)
{
    vector<vector<int>> matrix(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = min(matrix[u][v], w);
    }
    floydWarshall(matrix, n);
    for(int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if(dist[u][v] >= INF) cout << "Impossible\n";
        else if(dist[u][v] <= -INF) cout << "-Infinity\n";
        else cout << dist[u][v] << '\n';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;

    while(true)
    {
        cin >> n >> m >> q;
        if(n == 0 && m == 0 && q == 0) break;
        solve(n, m, q);
    }

    return 0;
}