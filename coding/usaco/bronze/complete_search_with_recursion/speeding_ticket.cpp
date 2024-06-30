#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    int cnt = 0;
    vector<int> road(100);
    for(int i = 0; i < n; i++)
    {
        int miles, speed; cin >> miles >> speed;
        for(int j = cnt; j < cnt + miles; j++)
            road[j] = speed;
        cnt += miles;
    }
    cnt = 0;
    vector<int> bessie(100);
    for(int i = 0; i < m; i++)
    {
        int miles, speed; cin >> miles >> speed;
        for(int j = cnt; j < cnt + miles; j++)
            bessie[j] = speed;
        cnt += miles;
    }
    int ans = 0;
    for(int i = 0; i < 100; i++)
    {
        ans = max(ans, bessie[i] - road[i]);
    }
    cout << ans << '\n';
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

