#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1005;
int dp[MAX][MAX];

int lcs(string& a, string& b)
{
    int n = a.size();
    int m = b.size();

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    return dp[n][m];
}

void solve()
{
    string s;
    getline(cin, s);
    string s1 = s;
    reverse(s1.begin(), s1.end());
    cout << lcs(s, s1) << '\n';
    // cout << s << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    getline(cin, in);
    int t = stoi(in);

    while(t--)
        solve();

    return 0;
}