#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> t(n), c(n);
    for(int i = 0; i < n; i++)
    { 
        cin >> t[i] >> c[i];
    }
    vector<int> res(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
    int p = 0;
    for(int i = 0; i < t[n - 1] + n; i++)
    {
        while(p < n && t[p] <= i + 1)
        {
            heap.push({c[p] - t[p], p});
            p++;
        }
        if(!heap.empty())
        {
            res[heap.top().second] = i + 1;
            heap.pop();
        }
    }
    for(int i = 0; i < n; i++) cout << res[i] << ' ';

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