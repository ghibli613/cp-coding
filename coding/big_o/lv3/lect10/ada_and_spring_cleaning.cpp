#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MOD1 = 1e9 + 9;
const ll MOD2 = 1e9 + 7;
const int N = 1e6 + 7;
const int BASE1 = 31;
const int BASE2 = 51;

ll hashS[N], POW[N];
ll hashS2[N], POW2[N];

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int getHash(ll hashS[], ll POW[], ll MOD, int i, int j)
{
    return (hashS[j] - hashS[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int solve(int n, int k, string &s)
{
    s = " " + s;
    POW[0] = 1;
    POW2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        hashS[i] = ((hashS[i - 1] * BASE1) + s[i] - 'a' + 1) % MOD1;
        hashS2[i] = ((hashS2[i - 1] * BASE2) + s[i] - 'a' + 1) % MOD2;
        POW[i] = (1LL * POW[i - 1] * BASE1) % MOD1;
        POW2[i] = (1LL * POW2[i - 1] * BASE2) % MOD2;
    }
    unordered_map<ii, bool, hash_pair> m;
    for (int i = 1; i <= n - k + 1; i++)
    {
        int x = getHash(hashS, POW, MOD1, i, i + k - 1);
        int y = getHash(hashS2, POW2, MOD2, i, i + k - 1);
        m.insert(make_pair(make_pair(x, y), true));
    }
    return int(m.size());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int sum = 0;
    while (T--)
    {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        sum += n;
        cout << solve(n, k, s) << '\n';
    }
}