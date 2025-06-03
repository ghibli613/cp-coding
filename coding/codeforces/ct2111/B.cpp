#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int f[11];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int w, l, h; cin >> w >> l >> h;
        bool flag = 1;
        if(w < f[n] || l < f[n] || h < f[n])
        {
            flag = 0;
        }
        else
        {
            for(int i = n - 1; i >= 1; i--)
            {
                h -= f[i + 1];
                if(w - f[i + 1] >= f[i] || l - f[i + 1] >= f[i])
                {
                    flag = 1;
                    break;
                }
                else if(h < f[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        cout << flag;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    f[1] = 1; f[2] = 2;
    for(int i = 3; i <= 10; i++)
        f[i] = f[i - 1] + f[i - 2];

    while(t--)
        solve();

    return 0;
}