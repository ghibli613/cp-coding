#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;

    vector<pair<string, string>> pairs(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> pairs[i].first >> pairs[i].second;
        pairs[i].first = pairs[i].first.substr(0, 2);
    }

    map<string, int> seen;
    long long total = 0;
    for (const pair<string, string> &i : pairs) {
        if (i.first != i.second) { total += seen[i.first + i.second]; }
        seen[i.first + i.second]++;
    }
    cout << total;
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