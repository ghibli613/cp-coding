#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> p(n);
    int max_hours = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        max_hours += p[i];
    }

    for(int num_hours = 0; num_hours <= max_hours; num_hours++)
    {
        if(num_hours != 0 && max_hours % num_hours != 0)
            continue;

        int curr_hours = 0;
        bool valid = false;
        for(int i = 0; i < n; i++)
        {
            if()
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}