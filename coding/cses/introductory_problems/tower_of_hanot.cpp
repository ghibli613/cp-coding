#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans = 0;
vector<pair<int, int>> step;

void hanoi_tower(int num_tower, int from, int to)
{
    if(num_tower == 1)
        step.push_back({from, to});
    else
    {
        int new_to = 0;
        for(int i = 1; i <= 3; i++) 
            if(i != from && i != to) new_to = i;
        hanoi_tower(num_tower - 1, from, new_to);
        step.push_back({from, to});
        hanoi_tower(num_tower - 1, new_to, to);
    }
}

void solve()
{
    int n; cin >> n;
    hanoi_tower(n, 1, 3);
    cout << (int)step.size() << '\n';
    for(int i = 0; i < (int)step.size(); i++)
        cout << step[i].first << ' ' << step[i].second << '\n';
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