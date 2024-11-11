#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<ll> s(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        s[i + 1] = s[i] + tmp;
    }

    ll ans = s[n] * k;
    s.pop_back();
    sort(s.begin() + 1, s.end());

    for(int i = 1; i < k; i++)
    {
        ans -= s[i];
    }

    cout << ans;

    return 0;
}