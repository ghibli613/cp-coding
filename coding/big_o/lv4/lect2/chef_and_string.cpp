#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1e9 + 7;

int C[N][N];

vector<int> zFunction(string &s)
{
    vector<int> z(s.size());
    z[0] = s.size();
    int n = s.size();
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            r = i + z[i] - 1, l = i;
    }
    return z;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    C[0][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                C[i][j] = C[i - 1][j];
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }

    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<int> cntExact(n + 1, 0);
        vector<int> cntAtleast(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            string suffix = s.substr(i, n - i);
            vector<int> z = zFunction(suffix);
            vector<int> auxAdd(n + 2, 0);
            for (int x : z)
                auxAdd[1]++, auxAdd[x + 1]--;
            for (int j = 1; j <= n; j++)
                auxAdd[j] += auxAdd[j - 1];
            for (int j = 1; j <= n; j++)
                cntAtleast[auxAdd[j]]++;
        }
        cntExact[n] = cntAtleast[n];
        for (int j = n - 1; j >= 1; j--)
        {
            cntExact[j] = cntAtleast[j] - cntAtleast[j + 1];
        }

        vector<int> ans(n + 1, 0);
        for (int k = 1; k <= n; k++)
            for (int i = k; i <= n; i++)
                ans[k] = (ans[k] + 1LL * cntExact[i] * C[i][k]) % MOD;

        for (int i = 1; i <= q; i++)
        {
            int k;
            cin >> k;
            if (k > n)
                cout << 0 << '\n';
            else
                cout << ans[k] << '\n';
        }
    }

    return 0;
}