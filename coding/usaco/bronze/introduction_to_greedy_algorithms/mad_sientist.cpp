#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;
    bool flag = true; int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i]) flag = true;
        else 
        {
            if(flag)
            {
                ans++;
                flag = false;
            }
        }
    }
    cout << ans << '\n';
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

