#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s; cin >> s;
    for(int i = 0; i < int(s.size()); i++)
    {
        if(s[i] == '.') cout << 0;
        else if(s[i] == '-')
        {
            i++;
            if(s[i] == '.') cout << 1;
            else cout << 2;
        }
    }
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
