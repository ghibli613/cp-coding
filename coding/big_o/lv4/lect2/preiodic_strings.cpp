#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

void solve()
{
    string s; cin >> s;
    int n = (int)s.size();
    set<int> divisor;
    divisor.insert(1);
    for(int i = 2; i <= sqrt(n); i++) 
        if(n % i == 0)
        {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    divisor.insert(n);
    int ans = 0;
    for(int i : divisor)
    {
        string tmp = s.substr(0, i) + " " + s;
        vector<int> z = z_function(tmp);
        bool check = 1;
        for(int j = i + 1; j < (int)z.size(); j += i)
        {
            if(z[j] != i)
            {
                check = 0;
                break;
            }
        }
        if(check)
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n\n";
    // for(int i : divisor) cout << i<< ' ';
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