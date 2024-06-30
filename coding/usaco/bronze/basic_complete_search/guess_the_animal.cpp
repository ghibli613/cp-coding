#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<set<string>> a;
    for(int i = 0; i < n; i++)
    {
        string name; cin >> name;
        int charac_num; cin >> charac_num;
        set<string> cows;
        for(int j = 0; j < charac_num; j++)
        {
            string charac; cin >> charac;
            cows.insert(charac);
        }
        a.push_back(cows);
    }

    int ans = 0;

    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n; j++)
        {
            int tmp_ans = 0;
            for(set<string>::iterator charac = a[i].begin(); charac != a[i].end(); charac++)
                if(a[j].find(*charac) != a[j].end()) tmp_ans++;
            if(tmp_ans > ans) ans = tmp_ans;
        }
    cout << ans+1;
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