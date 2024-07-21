#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int q; cin >> q;
    
    stack<ll> shelf;
    for(int i = 0; i < q; i++)
    {
        int t; cin >> t;
        if(t == 1) 
        {
            ll n; cin >> n;
            shelf.push(n);
        }
        else
        {
            if(shelf.empty()) cout << "kuchbhi?\n";
            else
            {
                cout << shelf.top() << '\n';
                shelf.pop();
            }
        }
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