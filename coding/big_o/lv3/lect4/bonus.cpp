#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> s[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    int ans = 0;
    for(int i = k; i <= n; i++)
        for(int j = k; j <= n; j++)
        {
            ans = max(ans, s[i][j] - s[i][j - k] - s[i - k][j] + s[i - k][j - k]);
        }
    
    cout << ans;

    return 0;
}