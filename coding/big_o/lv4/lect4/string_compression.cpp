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

int count_digit(int x)
{
    int res = 0;
    while(x > 0)
    {
        x /= 10;
        res++;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.length();

    vector<vector<int>> kmps;
    for(int i = 0; i < n; i++)
        kmps.push_back(kmpPreprocess(s.substr(i, n - i)));
    
    vector<int> f(n, 0);
    for(int i = 0; i < n; i++)
    {
        f[i] = i + 2;
        for(int j = 0; j <= i; j++)
        {
            int k = kmps[j][i - j];
            int len = i - j + 1;
            int s1 = len - k;
            int compress = len + 1;
            if(len % s1 == 0)
            {
                int c1 = len / s1;
                compress = count_digit(c1) + s1;
            }
            if(j == 0)
                f[i] = min(f[i], compress);
            else
                f[i] = min(f[i], f[j - 1] + compress);
        }
    }
    cout << f[n - 1] << '\n';

    return 0;
}