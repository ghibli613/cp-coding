#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; cin >> n;
    vector<int> a(n), b(n);
    vector<ll> A(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        A[i] = a[i] * (i + 1) * (n - i);
    }
    for(int & i : b) cin >> i;

    sort(A.begin(), A.end(), greater<ll>());
    sort(b.begin(), b.end());

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += A[i] * b[i];

    cout << ans;
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