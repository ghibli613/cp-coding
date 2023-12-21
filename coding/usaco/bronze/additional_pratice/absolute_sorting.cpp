#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    pair<int, int> condition{INT_MIN, INT_MAX};
    
    for(int i = 1; i < n; i++)
    {
        if(a[i - 1] < a[i])
        {
            int tmp = (a[i] + a[i - 1]) / 2;
            if(tmp < condition.second) condition.second = tmp;
        }
        else if(a[i - 1] > a[i])
        {
            int tmp = (a[i] + a[i - 1]) / 2;
            if((a[i] + a[i - 1]) % 2 != 0) tmp++;
            if(tmp > condition.first) condition.first = tmp;
        }
    }

    if(condition.first > condition.second) cout << -1 << '\n';
    else if(condition.first == INT_MIN)
    {
        if(condition.second == INT_MAX) cout << 0 << '\n';
        else cout << condition.second << '\n';
    }
    else cout << condition.first << '\n';
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