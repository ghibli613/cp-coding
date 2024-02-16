#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    pair<int, int> B, L, R;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            char tmp; cin >> tmp;
            if(tmp == 'R') R = {i, j};
            else if(tmp == 'B') B = {i, j};
            else if(tmp == 'L') L = {i, j};
        }
    int ans = 0;
    if(B.first == L.first && L.first == R.first)
    {
        if(R.second < B.second && R.second > L.second) ans += 2;
        else if(R.second < L.second && R.second > B.second) ans += 2;
    }
    else if(B.second == L.second && L.second == R.second)
    {
        if(R.first < B.first && R.first > L.first) ans += 2;
        else if(R.first < L.first && R.first > B.first) ans += 2;
    }
    ans += abs(B.first - L.first) + abs(B.second - L.second) - 1;
    cout << ans << '\n';
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

