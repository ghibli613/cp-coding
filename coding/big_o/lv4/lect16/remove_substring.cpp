#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAXN = 1e5 + 5;
const int MAXVAL = 6;

int R[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> vi(10);
    int state = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = s[i] - 'a';
        if (vi[x] == 0)
        {
            state += (1 << x);
            vi[x] = 1;
        }
        R[i] = state;
    }

    ll res = 0;
    state = 0;
    fill(vi.begin(), vi.end(), 0);
    vector<int> cnt(70);
    cnt[state] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int prestate = 0; prestate < (1 << MAXVAL); prestate++)
            if (cnt[prestate] > 0 && __builtin_popcount((prestate | R[i])) <= k)
            {
                res += cnt[prestate];
                res %= MOD;
            }
        if (i - 1 >= 0)
        {
            int x = s[i - 1] - 'a';
            if (vi[x] == 0)
            {
                state += (1 << x);
                vi[x] = 1;
            }
            cnt[state]++;
        }
    }
    cout << res << '\n';
}