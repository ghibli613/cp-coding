#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int test_case)
{
    cout << "Case #" << test_case << ": "; 
    ll n, k; cin >> n >> k;
    ll check = k % (1 << n);
    if(check == (1 << n) - 1)
    {
        cout << "ON\n";
    }
    else cout << "OFF\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int i = 0; i < t; i++)
        solve(i + 1);

    return 0;
}