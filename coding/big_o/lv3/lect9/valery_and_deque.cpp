#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, q; cin >> n >> q;
    deque<int> a;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    vector<pair<int, int>> ans(n + 5);
    for(int i = 1; i <= n; i++)
    {
        int A = a.front(); a.pop_front();
        int B = a.front(); a.pop_front();
        ans[i] = {A, B};
        a.push_back(min(A, B));
        a.push_front(max(A, B));
    }
    int maxx = a.front();
    a.pop_front();
    vector<int> b;
    while(!a.empty())
    {
        b.push_back(a.front());
        a.pop_front();
    }
    while(q--)
    {
        ll m; cin >> m;
        if(m <= n) cout << ans[m].first << ' ' << ans[m].second << '\n';
        else
            cout << maxx << ' ' << b[(m - n - 1) % (n - 1)] << '\n';
    }
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