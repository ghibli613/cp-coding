#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int G[MAXN], N, res = MAXN;

int divide(int n, int minn);

bool canDivide(int n, int minn)
{
    int cnt = 0;
    while (n >= minn)
    {
        n -= minn;
        minn++;
        cnt++;
    }
    if (n != 0 || cnt < 2)
        return false;
    return true;
}

int Grundy(int n)
{
    if (G[n] != -1)
        return G[n];
    unordered_set<int> mex;
    for (int i = 1; i <= n / 2; i++)
        if (canDivide(n, i))
            mex.insert(divide(n, i));
    int g = 0;
    while (mex.count(g))
        g++;
    return G[n] = g;
}

int divide(int n, int minn)
{
    int ans = 0, cnt = 0, tmp = n;
    while (n >= minn)
    {
        n -= minn;
        ans ^= Grundy(minn);
        cnt++;
        minn++;
    }
    if (ans == 0 && tmp == N)
        res = min(res, cnt);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    N = n;
    memset(G, -1, sizeof(G));
    G[1] = 0;
    G[2] = 0;
    res = Grundy(n) ? res : -1;
    cout << res << endl;
}