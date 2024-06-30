#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n; 
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin >> r[j];
        sort(r.begin(), r.end());
        c[i] = r[n / 2];
    }
    sort(c.begin(), c.end());

    cout << c[n/2];
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