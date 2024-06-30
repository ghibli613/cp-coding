#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    int cnt = 0;
    vector<pair<int, int>> ar;
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        ar.push_back({-tmp, cnt});
        if(tmp == 0)
        {
            sort(ar.begin(), ar.end());
            for(int j = 0; j < cnt; j++)
            {
                if(j == ar[0].second) cout << "pushStack\n";
                else if(j == ar[1].second) cout << "pushQueue\n";
                else if(j == ar[2].second) cout << "pushFront\n";
                else cout << "pushBack\n";
            }
            int take = 3;
            if(cnt < take) take = cnt;
            cout << take;
            if(take >= 1) cout << " popStack";
            if(take >= 2) cout << " popQueue";
            if(take >= 3) cout << " popFront";
            cout << "\n";
            cnt = 0;
            ar.clear();
        }
        else 
        {
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++) cout << "pushStack\n";
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