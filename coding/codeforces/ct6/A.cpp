#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < b) swap(a, b);
    if(c > a) 
    {
        swap(c, a);
        swap(c, b);
    }
    else if(c > b) swap(c, b);
    if(d > a)
    {
        swap(d, a);
        swap(d, b);
        swap(d, c);
    }
    else if(d > b)
    {
        swap(d, b);
        swap(d, c);
    }
    else if(d > c) swap(d, c);
    
    if(a < b + c || b < c + d) cout << "TRIANGLE";
    else if(a == b + c || b == c + d) cout << "SEGMENT";
    else cout << "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}