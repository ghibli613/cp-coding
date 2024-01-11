 #include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, p; cin >> n >> p;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].second;
    for(int i = 0; i < n; i++) cin >> a[i].first;
    ll ans = 0;
    sort(a.begin(), a.end());
    queue<pair<ll, ll>> mq;
    int i = 0;
    while(i < n)
    {
        ans += p;
        mq.push(a[i]);
        i++;
        while(i < n)
        {
            pair<ll, ll> tmp = mq.front(); mq.pop();
            if(tmp.first >= p) break;
            int tmp_n = i + tmp.second;
            if(tmp_n > n) tmp_n = n;
            for(int j = i; j < tmp_n; j++) mq.push(a[j]);
            ans += tmp.first * (tmp_n - i);
            i += tmp_n - i;
        }
    }

    cout << ans << '\n';
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