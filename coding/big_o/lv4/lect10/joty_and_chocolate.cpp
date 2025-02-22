#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    ll g = a * b / __gcd(a, b);
    cout << n / a * p + n / b * q - n / g * min(p, q);

    return 0;
}