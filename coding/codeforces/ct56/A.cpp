#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, ans = 0; cin >> n;
    set<string> alco;
    alco.insert("ABSINTH"); 
    alco.insert("BEER");
    alco.insert("BRANDY");
    alco.insert("CHAMPAGNE");
    alco.insert("GIN");
    alco.insert("RUM");
    alco.insert("SAKE");
    alco.insert("TEQUILA");
    alco.insert("VODKA");
    alco.insert("WHISKEY");
    alco.insert("WINE");
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if(s[0] >= 'A' && s[0] <= 'Z') 
        {
            if(alco.find(s) != alco.end())
                ans++;
        }
        else
        {
            int d = stoi(s);
            if(d < 18) ans++;
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