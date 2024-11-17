#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1000000000;
const int MAX = 1000005;
int a[MAX], tmp[MAX], le[MAX], ri[MAX];

long long solve(int l, int r)
{
    if (r - l < 2)
        return 0;
    int mid = (l + r) / 2;
    long long ret = solve(l, mid) + solve(mid, r);
    int p1 = l, p2 = mid;
    while (p1 != mid || p2 != r)
    {
        int val1 = (p1 < mid ? le[p1] : INF);
        int val2 = (p2 < r ? ri[p2] : INF);
        if (val1 <= val2)
        {
            p1++;
            ret += p2 - mid;
        }
        else
            p2++;
    }
    merge(le + l, le + mid, le + mid, le + r, tmp);
    for (int i = 0; i < r - l; i++)
        le[i + l] = tmp[i];
    merge(ri + l, ri + mid, ri + mid, ri + r, tmp);
    for (int i = 0; i < r - l; i++)
        ri[i + l] = tmp[i];
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        le[i] = cnt[a[i]];
    }
    cnt.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        cnt[a[i]]++;
        ri[i] = cnt[a[i]];
    }
    cout << solve(0, n);
    return 0;
}