#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int min = 4000; 
    for(int i = 0; i < 4; i++) 
    {
        int tmp; cin >> tmp;
        if(tmp < min) min = tmp;
    }
    int a, b; cin >> a >> b;
    if(a <= min && min <= b) cout << min - a;
    else if(a > min) cout << 0;
    else if(min > b) cout << b - a + 1;
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