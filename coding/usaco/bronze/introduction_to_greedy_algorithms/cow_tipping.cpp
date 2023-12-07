#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n; 
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int totalflips = 0;
    for (int i = n - 1; i >= 0; i--) 
        for (int j = n - 1; j >= 0; j--) 
            // go from bottom right to top, check if it's a 1
            if (grid[i][j] == '1') 
            {
                totalflips++;

                // cow flip rectangle
                for (int a = 0; a <= i; a++) 
                    for (int b = 0; b <= j; b++) 
                        if (grid[a][b] == '0') 
                            grid[a][b] = '1';
                        else 
                            grid[a][b] = '0';
                        
                // end cow flip
            }
    

    cout << totalflips;
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