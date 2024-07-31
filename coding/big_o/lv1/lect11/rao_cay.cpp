#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int x[2] = {-1, 1};

void solve()
{
    int m, n; cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    int ans = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j])
            {
                ans += 4;
            }
        }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(!matrix[i][j]) continue;
            for(int c : x)
            {
                if(i + c < 0 || i + c >= m || !matrix[i + c][j]) continue;
                ans--;
            }
            for(int c : x)
            {
                if(j + c < 0 || j + c >= n || !matrix[i][j + c]) continue;
                ans--;
            }
        }
    cout << ans;
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