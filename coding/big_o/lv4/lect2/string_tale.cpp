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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    string S = t + (char)32 + s + s;

    vector<int> z = z_function(S);
    for(int i = n + 1; i < (int)z.size(); i++)
    {
        if(z[i] == n)
        {
            cout << (int)z.size() - n - i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}