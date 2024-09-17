#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int in[26], out[26], par[26];

void solve()
{
    int n; cin >> n;
    for(int i=0; i<26; i++)
    {
        in[i] = out[i] = 0;
        par[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}