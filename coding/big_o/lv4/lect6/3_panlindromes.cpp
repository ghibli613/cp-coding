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
    for (int i = 0; i < (int)s.length(); i++)
        t[2 * i + 1] = s[i];

    vector<int> p = manacher(t);
    vector<vector<int>> ps((int)p.size(), vector<int>(3, 0));
    vector<int> prefixSum((int)p.size(), 0);

    for(int i = 1; i < (int)p.size(); i++)
    {
        ps[i] = ps[i - 1];
        if(t[i] != '#')
        {
            prefixSum[i] = (prefixSum[i - 1] + t[i] - '0') % 3;
            if(t[i] != '0')
            {
                ps[i][prefixSum[i]]++;
            }
        }
        else
            prefixSum[i] = prefixSum[i - 1];
        
        // cout << prefixSum[i] << ' ';
    }
    
    // for(int i = 0; i < t.size(); i++) cout << t[i] << ' ';
    // cout << endl;
    ll ans = 0;
    // cout << ans << ' ';
    for(int i = 1; i < (int)p.size(); i++)
    {
        int val = (t[i] - '0') % 3;
        if(val == 0)
            ans++;
        if(t[i] == '#') val = 0;

        int x = (prefixSum[i - 1] - val + 3) % 3;
        ans += ps[i + p[i]][x] - ps[i][x];
        // cout << ans << ' ';
    }
    cout << ans;

    return 0;
}