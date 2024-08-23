#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;

vector<vector<int>> dist;

void floydWarshall(vector<vector<int>> &matrix, int n)
{
    dist.assign(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = i == j ? 0 : matrix[i][j];
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dist[i][k] >= INF) continue;;
            for(int j = 1; j <= n; j++)
            {
                if(dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void solve(int tc)
{
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));
    vector<int> u(m), v(m), w(m);
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        matrix[u[i]][v[i]] = w[i];
        matrix[v[i]][u[i]] = w[i];
    }
    floydWarshall(matrix, n);
    cout << "Case #" << tc << ": ";
    for(int i = 0; i < m; i++)
    {
        if(dist[u[i]][v[i]] != w[i])
        {
            cout << "Impossible\n";
            return;
        }
    }
    cout << m << '\n';
    for(int i = 0; i < m; i++)
    {
        cout << u[i] << ' ' << v[i] << ' ' << w[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}