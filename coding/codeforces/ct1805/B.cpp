#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int idx = 0; char a = s[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] <= a)
        {
            a = s[i];
            idx = i;
        }
    }
    cout << a;
    for(int i = 0; i < idx; i++) cout << s[i];
    for(int i = idx+1; i < n; i++) cout << s[i];
    cout << '\n';
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