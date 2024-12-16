#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n;
int m[N][24];
int a[N], lg[N], mxL[N], mxR[N];

void RMQ_process()
{
    for (int i = 0; i < n; i++)
        m[i][0] = a[i];
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 0; i + (1 << k) - 1 < n; i++)
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
}

int rmq(int u, int v)
{
    int k = lg[v - u + 1];
    return min(m[u][k], m[v - (1 << k) + 1][k]);
}

bool check(int i, int j)
{
    if (j == n)
        return false;
    if (mxL[i] == mxR[j] && mxL[i] == rmq(i + 1, j - 1))
    {
        cout << "YES\n";
        cout << i + 1 << ' ' << j - i - 1 << ' ' << n - j << endl;
        return true;
    }
    return false;
}

void solve()
{
    mxL[0] = a[0];
    for (int i = 1; i < n; i++)
        mxL[i] = max(mxL[i - 1], a[i]);
    mxR[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        mxR[i] = max(mxR[i + 1], a[i]);
    RMQ_process();
    int j = n;
    for (int i = 0; i < n - 2; i++)
    {
        j = max(j, i + 2);
        while (j > i + 2 && mxR[j - 1] <= mxL[i])
        {
            j--;
        }
        if (mxL[i] != mxR[j])
            continue;

        if (check(i, j) || check(i, j + 1))
        {
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve();
    }
}
