#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    string r1 = "";
    string r2 = "";
    for(int i = 0; i < n; i++)
    {
        char tmp; cin >> tmp;
        if(tmp == 'B') tmp = 'G';
        r1.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
        char tmp; cin >> tmp;
        if(tmp == 'B') tmp = 'G';
        r2.push_back(tmp);
    }
    if(r1 == r2) cout << "YES\n";
    else cout << "NO\n";
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