#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> manacher(string s)
{
    int n = s.length();
    vector<int> p(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        int k = i > r ? 0 : min(p[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            k++;
        p[i] = --k;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return p;
}

void solve()
{
    string s;
    cin >> s;
    string t(2 * s.length() + 1, '#');
    for (int i = 0; i < (int)s.length(); i++)
        t[2 * i + 1] = s[i];

    int ans_max = 0, ans_num = 0;
    vector<int> p = manacher(t);
    for (int i = 1; i < (int)p.size() - 1; i++)
    {
        ans_max = max(p[i], ans_max);
    }
    for (int i = 1; i < (int)p.size() - 1; i++)
    {
        if(p[i] == ans_max) ans_num++;
    }
    cout << ans_max << ' ' << ans_num << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}