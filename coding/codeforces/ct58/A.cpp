#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s; cin >> s;
    int n = int(s.size());
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'h' && cnt == 0) {cnt++;}
        else if(s[i] == 'e' && cnt == 1) {cnt++;}
        else if(s[i] == 'l' && cnt == 2) {cnt++;}
        else if(s[i] == 'l' && cnt == 3) {cnt++;}
        else if(s[i] == 'o' && cnt == 4) {cnt++;}
    }
    if(cnt == 5) cout << "YES";
    else cout << "NO";
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