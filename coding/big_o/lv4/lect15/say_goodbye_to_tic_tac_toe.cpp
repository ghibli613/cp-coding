#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int f[3][3][N];

int mex(set<int> &val)
{
    int cnt = 0;
    while (val.find(cnt) != val.end())
        cnt++;
    return cnt;
}

int grundy(int st, int ed, int n)
{
    if (n == 0)
        return 0;
    if (f[st][ed][n] != -1)
        return f[st][ed][n];
    set<int> val;
    for (int i = 1; i <= n; i++)
    {
        for (int mi = 1; mi <= 2; mi++)
        {
            if (i == 1 && mi == st)
                continue;
            if (i == n && mi == ed)
                continue;
            val.insert(grundy(st, mi, i - 1) ^ grundy(mi, ed, n - i));
        }
    }
    return f[st][ed][n] = mex(val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(f, -1, sizeof(f));
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int pre = 0, cnt = 0;
        int moved = 0, ans = 0;
        for (char c : s)
        {
            if (c == '.')
                cnt++;
            else
            {
                moved++;
                int cur = (c == 'X' ? 1 : 2);
                ans ^= grundy(pre, cur, cnt);
                cnt = 0;
                pre = cur;
            }
        }
        ans ^= grundy(pre, 0, cnt);
        if ((moved % 2 == 0 && ans) || (moved % 2 && !ans))
        {
            cout << "Possible.\n";
        }
        else
        {
            cout << "Impossible.\n";
        }
    }
    
    return 0;
}