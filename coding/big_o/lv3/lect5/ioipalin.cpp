#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5005;
int dp[MAX][MAX];
int n; 

int lcs(string& a, string& b)
{
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    return dp[n][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    int ans = n - lcs(s, s1);
    if(ans < 2) ans += 2;
    cout << ans << '\n';

    return 0;
}