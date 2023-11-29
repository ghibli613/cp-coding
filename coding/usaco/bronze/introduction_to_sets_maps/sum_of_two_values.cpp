#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, x; cin >> n >> x;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        if(m.count(x - tmp)) 
        {
            cout << m[x - tmp] + 1 << ' ' << i + 1;
            return;
        }
        else
            m[tmp] = i;
    }
    cout << "IMPOSSIBLE";
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