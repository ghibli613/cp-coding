#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

const int MAX = 1e3 + 10;

int f[MAX][MAX];

int editDistance(const string& s, const string& t, int n, int m)
{
    for(int i = 0; i <= m; i++)
        f[0][i] = i;
    for(int i = 0; i <= n; i++)
        f[i][0] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i - 1] == t[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
    return f[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s, t;
    while(cin >> n)
    {
        cin >> s >> m >> t;
        cout << editDistance(s, t, n, m) << '\n';
    }

    return 0;
}