#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> s(n), p(n);

    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        cin >> p[i];

    int result = 0;
    for(int i = 0; i < m; i++)
    {
        bool A = false, C = false, G = false, T = false;
        for(int j = 0; j < n; j++)
            if(s[j][i] == 'A') A = true;
            else if(s[j][i] == 'C') C = true;
            else if(s[j][i] == 'G') G = true;
            else T = true;
        bool valid = false;
        for(int j = 0; j < n; j++)
            if((p[j][i] == 'A' && A) || (p[j][i] == 'C' && C) || (p[j][i] == 'G' && G) || (p[j][i] == 'T' && T))
            {
                valid = true;
                break;
            }
        if(!valid) result++;
    }

    cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}