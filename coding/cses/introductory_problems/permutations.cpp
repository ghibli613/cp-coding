#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    if(n == 2 || n == 3) cout << "NO SOLUTION";
    else 
    {
        for(int i = 2; i <= n; i += 2)
            cout << i << ' ';
        for(int i = 1; i <= n; i+= 2)
            cout << i << ' ';
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