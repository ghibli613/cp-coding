#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int a = 0, b = 0;
    for(int i = 0; i < 3; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 5) a++;
        else if(tmp == 7) b++;
    }
    if(a == 2 && b == 1) cout << "YES";
    else cout << "NO";
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