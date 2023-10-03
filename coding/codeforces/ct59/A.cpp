#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s; cin>>s;
    int n = int(s.size());
    int low = 0, up = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') up++;
        else low++;
    }
    if(low >= up) 
    {
        for(int i = 0; i < n; i++)
            if(s[i] >= 'A' && s[i] <= 'Z')  s[i] += 32;
    }
    else
    {
        for(int i = 0; i < n; i++)
            if(s[i] >= 'a' && s[i] <= 'z')  s[i] -= 32;
    }

    cout << s;
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