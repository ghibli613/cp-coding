#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

const int MAX = 20 + 10;

int f[MAX][MAX];

int editDistance(const string& s, const string& t, int n, int m)
{
    for(int i = 0; i <= m; i++)
        f[0][i] = i;
    for(int i = 0; i <= n; i++)
        f[i][0] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i - 1] == t[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
    return f[n][m];
}

string convert(int index)
{
    if(index / 10)
        return to_string(index);
    else 
        return "0" + to_string(index);
}

void trace(const string& s, const string& t, int n, int m)
{
    while(n > 0 && m > 0)
    {
        if(s[n - 1] == t[m - 1])
        {
            n--; m--;
        }
        else if(f[n - 1][m - 1] == f[n][m] - 1)
        {
            cout << "C" << t[m - 1] << convert(n);
            n--; m--;
        }
        else if(f[n - 1][m] == f[n][m] - 1)
        {
            cout << "D" << s[n - 1] << convert(n);
            n--;
        }
        else
        {
            cout << "I" << t[m - 1] << convert(n + 1);
            m--;
        }
    }
    while(m > 0) cout << "I" << t[--m] << "01";
    while(n > 0) cout << "D" << s[n - 1] << convert(n--);
    cout << "E\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while(cin >> s, s != "#")
    {
        cin >> t;
        editDistance(s, t, s.size(), t.size());
        trace(s, t, s.size(), t.size());
    }

    return 0;
}