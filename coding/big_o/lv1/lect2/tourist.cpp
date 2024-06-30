#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    ll n, k, v; cin >> n >> k >> v;
    vector<string> attractions(n);
    for(int i = 0; i < n; i++) cin >> attractions[i];

    vector<int> visited_list;
    ll redundun = (v - 1) * k % n;

    for(int i = redundun; i < n && k > 0; i++)
    {
        visited_list.push_back(i);
        k--;
    }
    for(int i = 0; i < redundun && k > 0; i++)
    {
        visited_list.push_back(i);
        k--;
    }
    sort(visited_list.begin(), visited_list.end());
    cout << "Case #" << tc + 1 << ": ";
    for(int i = 0; i < (int)visited_list.size(); i++) cout << attractions[visited_list[i]] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc);

    return 0;
}