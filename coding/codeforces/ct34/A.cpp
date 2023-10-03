#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sol_min = 10000;
    for(int i = 0; i < n-1; i++)
        ckmin(sol_min, abs(a[i] - a[i+1]));

    if(ckmin(sol_min, abs(a[0] - a[n-1])))
    {
        cout << 1 << " " << n;
        return;
    }

    for(int i = 0; i < n-1; i++)
        if(sol_min == abs(a[i] - a[i+1])) 
        {
            cout << i+1 << " " << i+2;
            return;
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