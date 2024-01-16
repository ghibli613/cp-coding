#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p.begin(), p.end(), greater<int>());
    vector<int> l(n);
    l[0] = 0; int max_e = p[0].first;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}