#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> outgoing(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        outgoing[a - 1]++;
    }
    vector<int> no_outs;
    for(int s = 0; s < n; s++)
    {
        if(outgoing[s] == 0)
            no_outs.push_back(s + 1);
    }
    int root = no_outs.size() == 1 ? no_outs[0] : -1;
    cout << root;
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