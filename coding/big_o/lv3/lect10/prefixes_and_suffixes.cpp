#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int base = 26;
const int MOD = 1e9 + 7;

string s;
int n, Pow[N], Hash[N], cnt[N];

int getHash(int i, int j)
{
    return (Hash[j] - 1LL * Hash[i - 1] * Pow[j - i + 1] + 1LL * MOD * MOD) % MOD;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    Pow[0] = 1;
    for (int i = 1; i <= n; i++)
        Pow[i] = 1LL * Pow[i - 1] * base % MOD;

    for (int i = 1; i <= n; i++)
        Hash[i] = (1LL * Hash[i - 1] * base + s[i] - 'A' + 1) % MOD;

    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        int matchPrefix = 0;
        for (int low = 1, high = n - i + 1; low <= high;)
        {
            int mid = (low + high) >> 1;
            if (getHash(1, mid) == getHash(i, i + mid - 1))
                matchPrefix = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        cnt[1]++, cnt[matchPrefix + 1]--;
        if (matchPrefix == n - i + 1)
        {
            ans.push_back(matchPrefix);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 2; i <= n; i++)
        cnt[i] += cnt[i - 1];

    cout << ans.size() + 1 << '\n';
    for (int x : ans)
        cout << x << ' ' << cnt[x] + 1 << '\n';
    cout << n << ' ' << 1;

    return 0;
}