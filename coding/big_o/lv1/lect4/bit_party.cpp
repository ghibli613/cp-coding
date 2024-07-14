#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, int c, vector<ll> m, vector<ll> p, vector<ll> s, int r, ll b)
{
    vector<ll> capacity(c);
    for(int i = 0; i < c; i++) capacity[i] = max(0ll, min(m[i], (mid - p[i]) / s[i]));
    sort(capacity.begin(), capacity.end(), greater<int> ());
    ll sum = 0;
    for(int i = 0; i < r; i++){
        sum += capacity[i];
    }
    return (sum >= b);
}

void solve(int tc)
{
    int r, c; 
    ll b; 
    cin >> r >> b >> c;
    vector<ll> m(c), s(c), p(c);
    ll left = 0, right = 0, ans = 0;
    for(int i = 0; i < c; i++)
    { 
        cin >> m[i] >> s[i] >> p[i];
        if(right < s[i] * p[i]) right = s[i] * p[i];
    }
    
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(check(mid, c, m, p, s, r, b))
        {
            right = mid - 1;
            ans = mid;
        }
        else left = mid + 1;
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc + 1);

    return 0;
}