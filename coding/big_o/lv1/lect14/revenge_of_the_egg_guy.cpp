#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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
            if(dist[i][k] >= 1e9) continue;;
            for(int j = 1; j <= n; j++)
            {
                if(dist[k][j] < 1e9 && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void solve(int tc)
{
    int n; cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            int tmp; cin >> tmp;
            if(tmp == -1) matrix[i][j] = 1e9;
            else matrix[i][j] = tmp;
        }

    floydWarshall(matrix, n);
    cout << "Circuit Design #" << tc <<": ";
    if(dist[1][2] == 0) cout << "Back to the drawing board\n";
    else cout << "No more hedgehog troubles\n";
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