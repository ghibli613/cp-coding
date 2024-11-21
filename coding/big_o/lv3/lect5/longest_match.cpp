#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1005][1005] = {};

int lcs(vector<string>& a, vector<string>& b)
{
    int n = a.size();
    int m = b.size();

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; int t = 0;
    while(getline(cin, s))
    {
        string s1;
        getline(cin, s1);

        cout << ++t << ". ";

        vector<string> a, b;
        string tmp = "";

        for(int i = 0; i < (int)s.size(); i++)
        {
            if((s[i] >='a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                tmp += s[i];
            }
            else if(tmp != "")
            {
                a.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp != "")
        {
            a.push_back(tmp);
            tmp = "";
        }

        for(int i = 0; i < (int)s1.size(); i++)
        {
            if((s1[i] >='a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
            {
                tmp += s1[i];
            }
            else if(tmp != "")
            {
                b.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp != "")
        {
            b.push_back(tmp);
            tmp = "";
        }

        if(a.empty() || b.empty()) 
        {
            cout << "Blank!\n";
            continue;
        }

        cout << "Length of longest match: " << lcs(a, b) << '\n';
    }

    return 0;
}