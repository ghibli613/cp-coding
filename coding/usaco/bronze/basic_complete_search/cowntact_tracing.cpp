#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compar_tuple(tuple<int, int, int> a, tuple<int, int ,int> b)
{
    return get<0>(a) < get<0>(b);
}

void solve()
{
    int N, T; cin >> N >> T;
    string s; cin >> s;
    vector<tuple<int, int, int>> a(T);
    for(int i = 0; i < T; i++)
    {
        int t, x, y; cin >> t >> x >> y;
        get<0>(a[i]) = t;
        get<1>(a[i]) = x;
        get<2>(a[i]) = y;
    }
    sort(a.begin(), a.end(), compar_tuple);

    auto is_consistent = [&](int patient_zero, int k) 
    {
        vector<bool> tmp_infected(N);
        vector<int> num_shakes(N);
        tmp_infected[patient_zero] = true;
        for (tuple<int, int, int> sh : a) 
        {
            if (tmp_infected[get<0>(sh)]) { num_shakes[get<0>(sh)]++; }
            if (tmp_infected[sh.y]) { num_shakes[sh.y]++; }
            if (num_shakes[sh.x] <= k && tmp_infected[sh.x]) {
                tmp_infected[sh.y] = true;
            }
            if (num_shakes[sh.y] <= k && tmp_infected[sh.y]) {
                tmp_infected[sh.x] = true;
            }
        }
    };

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