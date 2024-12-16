#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> minKSubarray(const vector<int> &a, int n, int k)
{
    vector<int> res(n, 0);
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);
        res[dq.front()]++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n)
    {
        int k, b, e;
        cin >> k >> b >> e;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> res = minKSubarray(a, n, k);
        for(int i = b - 1; i < e; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}