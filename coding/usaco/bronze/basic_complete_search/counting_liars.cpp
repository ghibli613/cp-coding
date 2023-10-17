#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> L;
    vector<ll> G;
    for(int i = 0; i < n; i++)
    {
        ll tmp1;
        char tmp; cin >> tmp >> tmp1;
        if(tmp == 'L')
            L.push_back(tmp1);
        else
            G.push_back(tmp1);
    }
    ll max_l = 0, min_g = 1000000001;
    for(int i = 0; i < (int)L.size(); i++)
        if(L[i] > max_l) max_l = L[i];
    for(int i = 0; i < (int)G.size(); i++)
        if(G[i] < min_g) min_g = G[i];

    int cnt_l = 0, cnt_g = 0;
    for(int i = 0; i < (int)L.size(); i++)
        if(L[i] < min_g) cnt_l++;

    for(int i = 0; i < (int)G.size(); i++)
        if(G[i] > max_l) cnt_g++;
    
    if(cnt_l > cnt_g) cout << cnt_g;
    else cout << cnt_l;
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