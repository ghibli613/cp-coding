#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int base = 31;
ll MOD = 1e9 + 7;

int manacher(vector<int> &a, vector<int> &oddNum)
{
    vector<int> s(2 * a.size() + 1, -1);
    vector<int> c(2 * oddNum.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
        s[2 * i + 1] = a[i];
    for (int i = 0; i < oddNum.size(); i++)
        c[2 * i + 1] = oddNum[i];
    int n = s.size();
    vector<int> p(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        int k = i > r ? 0 : min(p[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k] && c[i - k] <= 1)
            k++;
        p[i] = --k;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    ll res = 0;
    for (auto x : p)
    {
        res += (x + 1) / 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }

    vector<int> h(n), Pow(26), oddNum(n);
    vector<vector<int>> cnt(n);
    Pow[0] = 1;
    for (int i = 1; i < 26; i++)
        Pow[i] = (1LL * Pow[i - 1] * base) % MOD;

    int res = 0;
    for (int left = 0; left < m; left++)
    {
        for (int i = 0; i < n; i++)
        {
            h[i] = 0;
            oddNum[i] = 0;
            cnt[i].assign(26, 0);
        }
        for (int right = left; right < m; right++)
        {
            for (int i = 0; i < n; i++)
            {
                int c = matrix[i][right] - 'a';
                cnt[i][c]++;
                if (cnt[i][c] % 2)
                    oddNum[i]++;
                else
                    oddNum[i]--;
                h[i] = (h[i] + Pow[c]) % MOD;
            }
            res += manacher(h, oddNum);
        }
    }
    cout << res << endl;
}