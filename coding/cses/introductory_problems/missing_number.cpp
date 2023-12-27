#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<bool> a(n, true);
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a[tmp - 1] = false;
    }
    for(int i = 0; i < n; i++)
        if(a[i])
        {
            cout << i + 1;
            return;
        }
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