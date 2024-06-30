#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    double d, h; cin >> n >> d >> h;
    vector<double> y(n);
    for(int i = 0; i < n; i++) cin >> y[i];
    
    double ans = d * h / 2;

    for(ll i = n - 2; i >= 0; i--)
    {
        ans += d * h / 2;
        if(y[i + 1] - y[i] < h)
        {
            ans -= (h - y[i + 1] + y[i]) * (d * (h - y[i + 1] + y[i]) / h) / 2;
        }
    }

    printf("%.7lf\n", ans);
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