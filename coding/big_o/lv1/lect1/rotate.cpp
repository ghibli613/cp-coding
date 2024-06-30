#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    int n, k; cin >> n >> k;
    vector<vector<char>> p(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[j][n - i - 1];

    for(int j = 0; j < n; j++)
    {
        int des_index = n - 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(p[i][j] != '.')
            {
                char tmp = p[des_index][j];
                p[des_index][j] = p[i][j];
                p[i][j] = tmp;
                des_index--;
            }
        }
    }

    bool is_r_win = false, is_b_win = false;

    for(int i = 0; i < n; i++)
    {
        int cnt_r = 0, cnt_b = 0;
        for(int j = 0; j < n; j++)
        {
            if(p[i][j] == 'R')
            {
                cnt_b = 0;
                cnt_r++;
            }
            else if(p[i][j] == 'B')
            {
                cnt_r = 0;
                cnt_b++;
            }
            if(cnt_b == k) is_b_win = true;
            if(cnt_r == k) is_r_win = true;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int cnt_r = 0, cnt_b = 0;
        for(int j = 0; j < n; j++)
        {
            if(p[j][i] == 'R')
            {
                cnt_b = 0;
                cnt_r++;
            }
            else if(p[j][i] == 'B')
            {
                cnt_r = 0;
                cnt_b++;
            }
            if(cnt_b == k) is_b_win = true;
            if(cnt_r == k) is_r_win = true;
        }
    }

    for(int i = 0; i < 2 * n - 1; i++)
    {
        int y = 0;
        if(i > n - 1) y = i - (n - 1);
        int cnt_r = 0, cnt_b = 0;
        for(int j = y; j <= i - y; j++)
        {
            if(p[j][i - j] == 'R')
            {
                cnt_b = 0;
                cnt_r++;
            }
            else if(p[j][i - j] == 'B')
            {
                cnt_r = 0;
                cnt_b++;
            }
            if(cnt_b == k) is_b_win = true;
            if(cnt_r == k) is_r_win = true;
        }
    }

    for(int i = 0; i < 2 * n - 1; i++)
    {
        int y = 0, x = 0;
        if(i > n - 1) y = i - (n - 1);
        else x = n - 1 - i;

        int cnt_r = 0, cnt_b = 0;
        int t_y = y;
        for(int j = t_y; j <= i - t_y; j++)
        {
            // cout << y << " " << x << '\n';
            if(p[y][x] == 'R')
            {
                cnt_b = 0;
                cnt_r++;
            }
            else if(p[y][x] == 'B')
            {
                cnt_r = 0;
                cnt_b++;
            }
            if(cnt_b == k) is_b_win = true;
            if(cnt_r == k) is_r_win = true;
            y++;
            x++;
        }
    }

    cout << "Case #" << tc + 1 << ": ";
    if(is_r_win && is_b_win) cout << "Both\n";
    else if(is_r_win) cout << "Red\n";
    else if(is_b_win) cout << "Blue\n";
    else cout << "Neither\n";
    
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