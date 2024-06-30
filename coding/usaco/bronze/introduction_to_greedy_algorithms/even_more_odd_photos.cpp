#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    int evens = 0, odds = 0;
    for(int i = 0; i < n; i++)
    { 
        int tmp; cin >> tmp;
        if(tmp % 2 == 0) evens++;
        else odds++;
    }
    if(evens == odds) cout << evens * 2;
    else if(evens > odds) cout << odds * 2 + 1;
    else 
    {
        int ans = evens * 2;
        int excess = odds - evens;
        ans += (excess / 3) * 2;
        if(excess % 3 == 1) ans -= 1;
        else if(excess % 3 == 2) ans += 1;

        cout << ans;
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