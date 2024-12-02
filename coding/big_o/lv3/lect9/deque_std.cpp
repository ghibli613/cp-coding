#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> maxKSubarray(const vector<int> &a, int n, int k)
{
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            res.push_back(a[dq.front()]);
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> res = maxKSubarray(a, n, k);
    for(int x : res)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}