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

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    int x = -1, y = -1;

    if((int)a.size() == (int)b.size())
    {
        string ra = a, rb = b;
        reverse(ra.begin(), ra.end());
        reverse(rb.begin(), rb.end());
        vector<int> z1 = z_function(rb + char(1) + a);
        vector<int> z2 = z_function(b + char(1) + a);
        vector<int> p = kmpPreprocess(ra + char(1) + b);
        int n = (int)a.size();
        for(int i = 0; i < n - 1; i++)
        {
            int j = n - p[2 * n - i - 1];
            if(z1[n + 1] < i + 1 || z2[n + i + 2] < j - i - 1)
                continue;
            x = i;
            y = j;
        }
    }
    cout << x << ' ' << y << '\n';

    return 0;
}