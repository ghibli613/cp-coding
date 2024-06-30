#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, m; cin >> n >> m;
    char check = 'a';
    for(int i = 0; i < n; i++)
    {
        char val; cin >> val;
        if(check == val)
        {
            cout << "NO";
            return;
        }
        char tmp;
        for(int j = 1; j < m; j++)
        {
            cin >> tmp;
            if(tmp != val)
            {
                cout << "NO";
                return;
            }
        }
        check = val;
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
