#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> t(m);
    multiset<int> h;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        h.insert(tmp);
    }
    for(int i = 0; i < m; i++) cin >> t[i];

    for(int i = 0; i < m; i++)
    {
        if(h.empty()) 
        {
            cout << -1 << '\n';
            continue;
        }
        auto it = h.upper_bound(t[i]);
        if(it == h.begin()) cout << -1 << '\n';
        else 
        {
            it--;
            cout << *it << '\n';
            h.erase(it);
        }
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