#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> degre(n, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        degre[a - 1]++; degre[b - 1]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, degre[i]);

    cout << ans +1;
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