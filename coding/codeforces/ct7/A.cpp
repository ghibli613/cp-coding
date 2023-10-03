#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    vector<vector<char>> a(8,vector<char>(8));
    int ans = 0;
    for(int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for(int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'B') cnt++;
        }
        if(cnt == 8) ans++;
    }
    if(ans == 8)
    {
        cout << 8;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for(int j = 0; j < 8; j++)
        {
            if(a[j][i] == 'B') cnt++;
        }
        if(cnt == 8) ans++;
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