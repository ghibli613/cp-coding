#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int ans = 0;
    cin >> a[0];
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        if(a[i-1] > a[i])
        {
            int cnt = (a[i-1] - a[i]) / d + 1;
            ans += cnt;
            a[i] += cnt * d;
        }
        else if(a[i-1] == a[i])
        {
            ans++;
            a[i] += d;
        }
    }
    cout << ans;
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