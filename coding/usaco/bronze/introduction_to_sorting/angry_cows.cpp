#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> x(n);
    set<int> my_set;
    for(ll &i : x) 
    {
        cin >> i;
        my_set.insert(i);
    }
    sort(x.begin(), x.end());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp_ans = 1;
        int radius = 1;
        int prev = i;
        while(true)
        {
            int next = prev;
            while(next + 1 < n && x[next + 1] - x[prev] <= radius) next++;

            if(next == prev) break;

            prev = next;
            radius++;
        }
        tmp_ans += prev - i;

        radius = 1, prev = i;
        while(true)
        {
            int next = prev;
            while(next - 1 >= 0 && x[prev] - x[next - 1] <= radius) next--;

            if(next == prev) break;

            prev = next;
            radius++;
        }
        tmp_ans += i - prev;

        ans = max(tmp_ans, ans);
    }
    cout << ans;
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