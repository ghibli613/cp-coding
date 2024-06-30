#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    map<int, int> a;
    int max = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        if(a.find(tmp) == a.end())
        {
            a[tmp] = 1;
            if(a[tmp] > max) max = a[tmp];
            cnt++;
        }
        else
        {
            a[tmp]++;
            if(a[tmp] > max) max = a[tmp];
        }
    }
    cout << max <<' ' << cnt;
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