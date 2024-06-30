#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<pair<int, int>> divs(4);
    int participants_before = 0, participants_after = 0;
    for(int i = 0; i < 4; i++)
    {
        cin >> divs[i].first >> divs[i].second;
        participants_before += divs[i].first;
        participants_after += divs[i].second;
    }
    divs[0].first += participants_after - participants_before;
    for(int i = 0; i < 3; i++)
    {
        cout << divs[i].first - divs[i].second << '\n';
        divs[i + 1].first += divs[i].first - divs[i].second;
    }
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
