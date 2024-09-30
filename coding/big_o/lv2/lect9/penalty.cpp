#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int res;
string cur;

int f(string s)
{
    int rem1 = 5, rem2 = 5, score1 = 0, score2 = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (i % 2 == 0)
        {
            score1 += s[i] - '0';
            rem1--;
        }
        else
        {
            score2 += s[i] - '0';
            rem2--;
        }
        if (score1 + rem1 < score2)
        {
            return i + 1;
        }
        if (score2 + rem2 < score1)
        {
            return i + 1;
        }
    }
    return 10;
}

void brute(int idx, string s)
{
    if (idx == (int)s.size())
    {
        res = min(res, f(cur));
        return;
    }
    if (s[idx] == '?')
    {
        cur.push_back('0');
        brute(idx + 1, s);
        cur.pop_back();

        cur.push_back('1');
        brute(idx + 1, s);
        cur.pop_back();
    }
    else
    {
        cur.push_back(s[idx]);
        brute(idx + 1, s);
        cur.pop_back();
    }
}

void solve()
{
    string s;
    cin >> s;
    res = MOD;
    brute(0, s);
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}