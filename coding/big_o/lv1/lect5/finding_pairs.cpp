#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    map<int, int> a;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a[tmp]++; 
    }
    int ans = 0;
    for (const auto& [key, value] : a)
        ans += (value + 1) * value / 2;
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