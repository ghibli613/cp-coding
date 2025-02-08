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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    string t(2 * s.length() + 1, '#');
    for (int i = 0; i < s.length(); i++)
        t[2 * i + 1] = s[i];

    int ans = 0;
    vector<int> p = manacher(t);
    for (int i = 1; i < p.size() - 1; i++)
    {
        if(t[i] != '#')
            ans += 1;
        ans += p[i] / 2;
    }
    cout << ans;

    // for(int i = 0; i < p.size(); i++) cout << p[i] << ' ';

    return 0;
}