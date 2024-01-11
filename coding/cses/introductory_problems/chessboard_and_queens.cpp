#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<bool>> blocked(8, vector<bool>(8));
vector<bool> row_taken(8, false);
vector<bool> diag1(15, false);
vector<bool> diag2(15, false);

int ans = 0;

void search_queens(int c)
{
    if(c == 8)
    {
        ans++;
        return;
    }
    for(int r = 0; r < 8; r++)
    {
        bool row_open = !row_taken[r];
        bool diag_open = !diag1[r + c] && !diag2[r - c + 7];
        if(!blocked[r][c] && row_open && diag_open) 
        {
			row_taken[r] = diag1[r + c] = diag2[r - c + 7] = true;
			search_queens(c + 1);
			row_taken[r] = diag1[r + c] = diag2[r - c + 7] = false;
		}
    }
}

void solve()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            char tmp; cin >> tmp;
            blocked[i][j] = tmp == '*';
        }
    search_queens(0);
    cout << ans;
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