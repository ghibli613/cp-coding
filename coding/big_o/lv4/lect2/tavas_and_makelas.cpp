#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

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

    int n, m; cin >> n >> m;
    string p; cin >> p;

    int size_p = (int)p.size();

    vector<int> y(m);
    for(int i = 0; i < m; i++)
    { 
        cin >> y[i];
        y[i]--;
    }

    vector<int> z = z_function(p);
    ll ans = 1;

    string s = "";
    for(int i = 0; i < n; i++)
    {
        s += "*";
    }

    if(m > 0)
        for(int i = 0; i < size_p; i++)
            s[y[0] + i] = p[i];
    
    for(int i = 1; i < m; i++)
    {
        if(y[i] > y[i - 1] + size_p - 1)
        {
            for(int j = y[i]; j < y[i] + size_p; j++)
                s[j] = p[j - y[i]];
        }
        else
        {
            if(z[y[i] - y[i - 1]] != size_p - y[i] + y[i - 1])
            {
                cout << 0;
                return 0;
            }
            for(int j = y[i - 1] + size_p; j < y[i] + size_p; j++)
            {
                s[j] = p[j - y[i]];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '*')
        {
            ans *= 'z' - 'a' + 1;
            ans %= MOD;
        }
    }
    cout << ans << '\n';

    // cout << s;
    return 0;
}