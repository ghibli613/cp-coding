#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<char>> figurine(n, vector<char>(n));
    vector<vector<vector<char>>> pieces(k, vector<vector<char>> (n, vector<char>(n)));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> figurine[i][j];

    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            for(int t = 0; t < n; t++)
                cin >> pieces[i][j][t];

    for(int i = 0; i < k - 1; i++)
        for(int j = i + 1; j < k; j++)
        {
            
        }
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