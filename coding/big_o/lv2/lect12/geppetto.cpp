#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> restrict(m);
    for(int i = 0; i < m; i++)
        cin >> restrict[i].first >> restrict[i].second;

    int ans = 0;
    for(int i = 0; i < (1 << n); i++)
    {
        bool check = 0;
        for(int j = 0; j < m; j++)
        {
            if((i & (1 << (restrict[j].first - 1))) && (i & (1 << (restrict[j].second - 1))))
            {
                check = 1;
                break;
            }
        }
        if(!check) ans++;
    }
    cout << ans;

    return 0;
}