#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    int log = 30;
    vector<int> cnt(log, 0);
    vector<int> ans;
    for(int j = 0; j < n; j++)
    {
        int t; ll v; cin >> t >> v;
        bool valid = true;
        if(t == 1) cnt[v]++;
        else
        {
            int nw = 0;
            for(int i = 0; i < log; i++)
            {
                int r = (v % (2 << i)) / (1 << i); 
                if(r > nw + cnt[i])
                {
                    ans.push_back(0);
                    valid = false;
                    break;
                }
                v -= r;
                nw = (nw + cnt[i] - r) / 2;
            }
            if(valid) ans.push_back(nw >= (v >> 30));
        }
    }
    for(int i = 0; i < (int)ans.size(); i++)
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
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