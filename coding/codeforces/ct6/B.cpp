#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, m; cin >> n >> m;
    char pre; cin >> pre;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    set<char> check;
    check.insert(pre);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == pre)
            {
                if(i-1 >= 0 && a[i-1][j] != '.' && check.find(a[i-1][j]) == check.end())
                {
                    check.insert(a[i-1][j]);
                    ans++;
                }
                if(i+1 < n && a[i+1][j] != '.' && check.find(a[i+1][j]) == check.end())
                {
                    check.insert(a[i+1][j]);
                    ans++;
                }
                if(j-1 >= 0 && a[i][j-1] != '.' && check.find(a[i][j-1]) == check.end())
                {
                    check.insert(a[i][j-1]);
                    ans++;
                }
                if(j+1 < m && a[i][j+1] != '.' && check.find(a[i][j+1]) == check.end())
                {
                    check.insert(a[i][j+1]);
                    ans++;
                }
            }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}