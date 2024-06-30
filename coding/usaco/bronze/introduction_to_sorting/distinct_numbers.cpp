#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    set<int> distinct;
    int n; cin >> n;
    for(int i = 0; i < n; i++) 
    {
        int tmp; cin >> tmp;
        distinct.insert(tmp);
    }
    cout << distinct.size();
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