#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n; 
    vector<vector<char>> canvas(n, vector<char>(n));
    set<char> colors;    vector<bool> works(9, false);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> canvas[i][j];
            colors.insert(canvas[i][j]);
        }

    colors.erase('0');
    for(char i : colors) works[i - '1'] = true;

    for(char color : colors)
    {
        set<char> inside;
        int l = 9, r = 0, t = 9, b = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(canvas[i][j] == color) 
                    l = min(j, l), r = max(r, j), t = min(t, i), b = max(b, i);
                
        for(int i = t; i <= b; i++)
            for(int j = l; j <= r; j++)
                inside.insert(canvas[i][j]);

        inside.erase(color);
        for(char i : inside) works[i - '1'] = false;
    }
    
    int ans = 0;
    for(int i = 0; i < 9; i++)
        if(works[i]) ans++;

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
