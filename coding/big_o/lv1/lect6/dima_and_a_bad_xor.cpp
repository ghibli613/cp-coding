#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> ans(n);
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
        result ^= a[i][0];
    }
    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
        {
            if(result != 0)
            {
                break;
            }
            else
            {
                result ^= a[i][j - 1] ^ a[i][j];
                ans[i] = j;
            }
        }

    if(result) 
    {
        cout << "TAK\n";
        for(int t = 0; t < n; t++)
            cout << ans[t] + 1 << ' ';
    }
    else cout << "NIE";

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