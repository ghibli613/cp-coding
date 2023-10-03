#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{ 
    int a, b, c; cin >> a >> b >> c;
    if(a - 1 > (abs(b-c) + c - 1)) cout << 2 << '\n';
    else if(a - 1 < abs(b-c) + c-1) cout << 1 << '\n';
    else cout << 3 << '\n';
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}