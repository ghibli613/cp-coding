#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    vector<ll> second(n/2);
    int ans = 0;
    vector<ll> miner(n / 2);
    for(int i = 0; i < n / 2; i++) miner[i] = a[i];

    for(int i = n - 1; i >= n / 2; i--)
    {
        if(miner.empty()) break;
        while(!miner.empty())
        {
            if(miner[miner.size() - 1] <= a[i] / 2)
            {
                ans += 1;
                miner.pop_back();
                break;
            }
            else
            {
                miner.pop_back();
            }
        }
    }
    cout << (int)a.size() - ans << '\n';
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