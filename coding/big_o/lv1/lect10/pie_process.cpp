#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int t)
{
    int n, m; cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(int j = 0; j < m; j++)
        {
            int c;
            cin >> c;
            min_heap.push(c);
        }
        for(int j = 0; j < m; j++)
        {
            heap.push(min_heap.top() + (j + 1) * (j + 1) - j * j);
            min_heap.pop();
        }
        ans += heap.top();
        heap.pop();
    }
    cout << "Case #" << t << ": " << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int test = 0; test < t; test++)
        solve(test + 1);

    return 0;
}