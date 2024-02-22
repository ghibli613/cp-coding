#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < k; i++)
    {
        int b, e; cin >> b >> e;
        a[b - 1].first++;
        a[e - 1].second--;
    }
    vector<int> hay(n);
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
        tmp += a[i].first;
        hay[i] = tmp;
        tmp += a[i].second;
    }
    sort(hay.begin(), hay.end());
    cout << hay[n / 2] << '\n';
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

