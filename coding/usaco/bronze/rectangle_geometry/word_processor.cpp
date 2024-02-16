#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int tmp = (int)a[0].size();
    cout << a[0];
    for(int i = 1; i < n; i++)
    {
        tmp += (int)a[i].size();
        if(tmp <= k)
        {
            cout << ' ' << a[i];
        }
        else 
        {
            cout << '\n' << a[i];
            tmp = (int)a[i].size();
        }
    }
    cout << '\n';
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

