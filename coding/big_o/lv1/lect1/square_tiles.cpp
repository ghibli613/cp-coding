#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    int r, c; cin >> r >> c;
    vector<vector<char>> p(r, vector<char>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> p[i][j];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(p[i][j] == '#')
            {
                p[i][j] = '/';
                if(j < c - 1 && p[i][j + 1] == '#') p[i][j + 1] = '\\';
                else 
                {
                    cout << "Case #" << tc + 1 << ":\nImpossible\n";
                    return;
                }
                if(i < r - 1 && p[i + 1][j] == '#') p[i + 1][j] = '\\';
                else 
                {
                    cout << "Case #" << tc + 1 << ":\nImpossible\n";
                    return;
                }
                if(i < r - 1 && j < c - 1 && p[i + 1][j + 1] == '#') p[i + 1][j + 1] = '/';
                else 
                {
                    cout << "Case #" << tc + 1 << ":\nImpossible\n";
                    return;
                }
            }
        }
    }
    cout << "Case #" << tc + 1 << ":\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cout << p[i][j];
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc);

    return 0;
}