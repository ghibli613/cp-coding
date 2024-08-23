#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> dist;

void floydWarshall(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] += dist[i][k] * dist[k][j];
                if(dist[i][j] >= 2)
                {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}

void solve(int tc)
{
    int n; cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        for(int j = 1; j <= m; j++)
        {
            int tmp; cin >> tmp;
            dist[i][tmp] = 1;
        }
    }
    cout << "Case #" << tc << ": ";
    floydWarshall(n);
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