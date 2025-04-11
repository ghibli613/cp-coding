const int MAX = 1e3 + 10;

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
            cout << "Relace " << n << " " << t[m - 1] << "\n";
            n--; m--;
        }
        else if(f[n - 1][m] == f[n][m] - 1)
        {
            cout << "Delete " << n << "\n";
            n--;
        }
        else
        {
            cout << "Insert " << n + 1 << " " << t[m - 1] << "\n";
            m--;
        }
    }
    while(m > 0) cout << "Insert 1 " << t[--m] << "\n";
    while(n > 0) cout << "Delete " << n-- << "\n";
}