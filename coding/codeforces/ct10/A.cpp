#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    int r, l;
    cin >> l >> r;
    int ans = (r - l) * p1;
    for(int i = 1; i < n; i++)
    {
        cin >> l;
        int tmp = l - r;
        if(tmp < t1)
            ans += tmp * p1;
        else
        {
            ans += t1 * p1;
            tmp = tmp - t1;
            if(tmp < t2)
                ans += tmp * p2;
            else
            {
                ans += t2 * p2;
                tmp = tmp - t2;
                ans += tmp * p3;
            }
        }
        cin >> r;
        ans += (r - l) * p1;
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
