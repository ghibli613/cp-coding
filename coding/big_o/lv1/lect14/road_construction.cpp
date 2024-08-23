#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int n, m;
const double INF = 1e8;

vector<vector<double>> dist;

double distance(pii u, pii v)
{
    double x = u.first - v.first;
    double y = u.second - v.second;
    return sqrt(x * x + y * y);
}

double CalCost(int u, int v, double w)
{
    double sum = 0.0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            sum += dist[i][j] - min(min(dist[i][j], dist[i][u] + w + dist[v][j]), dist[i][v] + w + dist[u][j]);
        }
    return sum;
}

void floydWarshall()
{
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

void solve()
{
    vector<pii> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    dist.assign(n + 1, vector<double>(n + 1, INF));
    
    for(int i = 1; i <= n; i++)
    {
        dist[i][i] = 0.0;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        dist[u][v] = dist[v][u] = distance(a[u], a[v]);
    }
    floydWarshall();
    double ans = 0.0;
    int ansU = 0, ansV = 0;
    
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
        {
            double tmp = CalCost(u, v, distance(a[u], a[v]));
            
            if(ans < tmp)
            {
                ans = tmp;
                ansU = u;
                ansV = v;
            }
        }
    
    if(ans > 1.0) cout << ansU << ' ' << ansV << '\n';
    else cout << "No road required\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve();
    }

    return 0;
}