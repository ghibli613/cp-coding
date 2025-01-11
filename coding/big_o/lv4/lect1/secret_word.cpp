#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> kmpPreprocess(string p)
{
    int m = p.length();
    vector<int> pref(m, 0);

    int j = 0;
    for(int i = 1; i < m; i++)
    {
        while(j > 0 && p[j] != p[i])
            j = pref[j - 1];
        if(p[i] == p[j])
            j++;
        pref[i] = j;
    }

    return pref;
}

void solve()
{
    string s; cin >> s;
    int n = (int)s.size();
    string s1 = s;
    reverse(s1.begin(), s1.end());
    string s2 = s + "#" + s1;

    vector<int> pref = kmpPreprocess(s2);
    int l = 0;
    for(int i = n + 1; i < (int)s2.size(); i++)
    {
        l = max(pref[i], l);
    }
    for(int i = l - 1; i >= 0; i--)
        cout << s[i];
    cout << '\n';
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