#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, x; cin >> n >> x;
    int m, M; cin >> m >> M;
    int tmp = m;
    if(ckmin(m, M)) M = tmp;
    for(int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        tmp = a;
        if(ckmin(a, b)) b = tmp;
        if(a <= m)
        {
            if(b < M && b >= m) M = b;
            else if(b < m)
            {
                cout << -1; 
                return;
            }
        }
        else if(a > m && a <= M)
        {
            if(b < M) 
            {
                m = a; 
                M = b;
            }
            else m = a;
        } 
        else 
        {
            cout << -1;
            return;
        } 
    }
    if(x <= M && x >= m) cout << 0;
    else cout << min(abs(x-m), abs(M-x));
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