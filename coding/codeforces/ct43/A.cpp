#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    int a = 1, b= 0;
    string s, s1 = ""; cin >> s;
    for(int i = 1; i < n; i++)
    {
        string tmp; cin >> tmp;
        if(tmp == s) a++;
        else
        {
            s1 = tmp;
            b++;
        }
    }
    if(a > b) cout << s;
    else cout << s1;
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