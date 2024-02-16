#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int convert_char(char ch)
{
    if(ch == 'A') return 0;
    else if(ch == 'C') return 1;
    else if(ch == 'G') return 2;
    else return 3;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> spot_cows(n), plain_cows(n);
    for(int i = 0; i < n; i++)
        cin >> spot_cows[i];
    for(int i = 0; i < n; i++)
        cin >> plain_cows[i];

    int ans = 0;
    for(int i = 0; i < m - 2; i++)
        for(int j = i + 1; j < m - 1; j++)
            for(int t = j + 1; t < m; t++)
            {
                vector<int> check(4*4*4);
                for(int x = 0; x < n; x++)
                {
                    int valid = convert_char(spot_cows[x][i]) * 16 + convert_char(spot_cows[x][j]) * 4 + convert_char(spot_cows[x][t]);
                    check[valid] = 1;
                }
                bool check1 = false;
                for(int x = 0; x < n; x++)
                {
                    int valid = convert_char(plain_cows[x][i]) * 16 + convert_char(plain_cows[x][j]) * 4 + convert_char(plain_cows[x][t]);
                    if(check[valid])
                    {
                        check1 = true;
                        break;
                    }
                }
                if(!check1) ans++;
            }
    cout << ans << '\n';
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
