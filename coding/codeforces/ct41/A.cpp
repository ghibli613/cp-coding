#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s, s1; cin >> s >> s1;
    if(int(s.size()) != int(s1.size()))
    {
        cout << "NO";;
        return;
    }
    else 
    {
        int n = int(s.size());
        for(int i = 0; i < n; i++)
        {
            if(s[i] != s1[n - 1 - i])
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
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