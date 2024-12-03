#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    deque<int> dq;
    int minLength = INT_MAX;

    for (int i = 0; i <= n; ++i)
    {
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k)
        {
            minLength = min(minLength, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    if(minLength == INT_MAX) cout << -1;
    else cout << minLength;

    return 0;
}