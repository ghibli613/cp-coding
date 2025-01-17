#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

vector<int> z_function(string s)
{
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string a, l, r;

// compare a[index...index + s.size() - 1] to s
int compare(vector<int> &z, string &s, int index)
{
    if (index + s.size() - 1 >= a.size())
        return -1;

    int x = z[s.size() + 1 + index];
    if (x == (int)s.size())
        return 0;
    if (a[index + x] < s[x])
        return -1;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> l >> r;

    vector<int> zl = z_function(l + "#" + a);
    vector<int> zr = z_function(r + "#" + a);

    vector<int> f(a.size() + 1), suffix(a.size() + 2, 0);
    f[a.size()] = 1;
    suffix[a.size()] = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '0')
        {
            if (l == "0")
                f[i] = f[i + 1];
            else
                f[i] = 0;
        }
        else
        {
            int U = i + l.size() - 1;
            if (compare(zl, l, i) == -1)
                U++;

            int V = i + r.size() - 1;
            if (compare(zr, r, i) == 1)
                V--;

            // f[i] = sum(f[U + 1...V + 1])
            f[i] = suffix[min((int)a.size() + 1, U + 1)] - suffix[min((int)a.size() + 1, V + 2)];
            f[i] = (f[i] + MOD) % MOD;
        }

        suffix[i] = (suffix[i + 1] + f[i]) % MOD;
    }
    cout << f[0];
    return 0;
}