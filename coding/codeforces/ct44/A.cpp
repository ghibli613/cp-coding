#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    set<pair<string, string>> a;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string species, color;
        cin >> species >> color;
        pair<string, string> tmp = {species, color};
        if(a.find(tmp) == a.end())
        {
            ans++;
            a.insert(tmp);
        }
    }
    cout << ans;
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