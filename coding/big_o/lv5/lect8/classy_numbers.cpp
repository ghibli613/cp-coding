#include <bits/stdc++.h>
using namespace std;

long long C[20][20];
long long pw[4];

long long cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return C[n][k];
}

long long get(int n, int lft)
{
    long long tot = 0;
    for (int i = 0; i < lft + 1; i++)
        tot += cnk(n, i) * pw[i];
    return tot;
}

long long calc(long long x)
{
    string s = to_string(x);

    long long res = 0;
    int cur = 3;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            continue;
        res += get(n - i - 1, cur);
        --cur;
        if (cur == -1)
            break;
        res += get(n - i - 1, cur) * (s[i] - '1');
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 20; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    pw[0] = 1, pw[1] = 9, pw[2] = 81, pw[3] = 729;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        long long L, R;
        cin >> L >> R;
        cout << calc(R + 1) - calc(L) << '\n';
    }
    return 0;
}