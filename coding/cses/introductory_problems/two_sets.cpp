#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; cin >> n;
    ll sum = (n + 1) * n / 2;
    if(sum % 2 != 0) 
    {
        cout << "NO";
        return;
    }
    else
    {
        cout << "YES\n";
        int set_size = n / 2;
        if(n % 2 == 0)
        {
            cout << set_size << '\n';
            for(int i = 1; i < set_size; i += 2)
                cout << i << ' ' << n - i + 1 << ' ';
            cout << '\n';
            cout << set_size << '\n';
            for(int i = 2; i <= set_size; i += 2)
                cout << i << ' ' << n - i + 1 << ' ';
        }
        else
        {
            cout << set_size + 1 << '\n' << set_size + 1 << ' ' << set_size / 2 + 1 << ' ';
            for(int i = 1; i < set_size / 2 + 1; i++)
                cout << i << ' ' << n - i + 1 << ' ';
            cout << '\n' << set_size << '\n' << set_size + set_size / 2 + 2 << ' ';
            for(int i = set_size / 2 + 2; i <= set_size; i++)
                cout << i << ' ' << n - i + 1 << ' ';
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