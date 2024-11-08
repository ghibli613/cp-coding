#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> f(n + 2);
    f[0] = 0; f[1] = 1;
    for(int i = 2; i <= n + 1; i++)
        f[i] = f[i - 1] + f[i - 2];
    
    cout << f[n - 1] * f[n + 1] - f[n] * f[n];

    return 0;
}