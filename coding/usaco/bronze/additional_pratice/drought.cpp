#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    ll bag_needed = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(h[i + 1] > h[i])
        {
            if(i + 2 > n - 1)
            {
                cout << -1 << '\n';
                return;
            }
            ll difference = h[i + 1] - h[i];
            h[i + 1] -= difference;
            h[i + 2] -= difference;
            if(h[i + 2] < 0)
            {
                cout << -1 << '\n';
                return;
            }
            bag_needed += difference * 2;
        }
        else if(h[i] > h[i + 1])
        {
            if(i % 2 != 1)
            {
                cout << -1 << '\n';
                return;
            }
            ll difference = h[i] - h[i + 1];
            bag_needed += difference * (i + 1);
        }
    }

    cout << bag_needed << '\n';
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