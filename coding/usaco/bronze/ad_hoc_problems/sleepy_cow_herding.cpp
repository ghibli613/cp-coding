#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<int> p(3);
    cin >> p[0] >> p[1] >> p[2];

    sort(p.begin(), p.end());

    int min_gap = min({p[1] - p[0] - 1, p[2] - p[1] - 1, 2});
    int max_gap = max({p[1] - p[0] - 1, p[2] - p[1] - 1});

    if(min_gap == 0 && max_gap != 0)
    {
        if(max_gap <= 2) min_gap = max_gap;
        else min_gap = 2;
    }

    cout << min_gap << '\n' << max_gap; 
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