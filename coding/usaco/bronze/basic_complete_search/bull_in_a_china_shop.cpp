#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_piece(vector<vector<bool>> a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cout << a[i][j];
        cout << '\n';
    }
}

bool check_merge_pieces(vector<vector<bool>> a, vector<vector<bool>> b, vector<vector<bool>> figurine, int n)
{
    vector<vector<bool>> tmp_figurine(n, vector(n, false));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == b[i][j] && a[i][j] == true)
                return false;
            tmp_figurine[i][j] = a[i][j] ^ b[i][j];
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(tmp_figurine[i][j] != figurine[i][j]) return false;



    return true;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<bool>> figurine(n, vector<bool>(n));
    vector<vector<vector<bool>>> pieces(k, vector<vector<bool>> (n, vector<bool>(n)));
    vector<vector<int>> sides(k, vector<int>(k));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            char tmp; cin >> tmp;
            if(tmp == '.') figurine[i][j] = false;
            else figurine[i][j] = true;
        }

    for(int i = 0; i < k; i++)
    {
        sides[i][0] = n - 1;
        sides[i][1] = 0;
        sides[i][2] = n - 1;
        sides[i][3] = 0;
        for(int j = 0; j < n; j++)
            for(int t = 0; t < n; t++)
            {
                char tmp; cin >> tmp;
                if(tmp == '.') pieces[i][j][t] = false;
                else 
                {
                    pieces[i][j][t] = true;
                    sides[i][0] = min(sides[i][0], t);
                    sides[i][1] = max(sides[i][1], t);
                    sides[i][2] = min(sides[i][2], j);
                    sides[i][3] = max(sides[i][3], j);
                }
            }
    }

    for(int i = 0; i < k - 1; i++)
        for(int j = i + 1; j < k; j++)
            for(int idy = sides[i][3] - n + 1; idy <= sides[i][2]; idy++)
                for(int idx = sides[i][1] - n + 1; idx <= sides[i][0]; idx++)
                {
                    vector<vector<bool>> tmp_piece_i(n, vector<bool>(n, false));
                    for(int v = 0; v < n; v++)
                    {
                        if(v + idy < 0) continue;
                        if(v + idy > n - 1) break;
                        for(int h = 0; h < n; h++)
                        {
                            if(h + idx < 0) continue;
                            if(h + idx > n - 1) break;
                            tmp_piece_i[v][h] = pieces[i][v+idy][h+idx];
                        }
                    }
                    for(int jdy = sides[j][3] - n + 1; jdy <= sides[j][2]; jdy++)
                        for(int jdx = sides[j][1] - n + 1; jdx <= sides[j][0]; jdx++)
                        {
                            vector<vector<bool>> tmp_piece_j(n, vector<bool>(n, false));
                            for(int v = 0; v < n; v++)
                            {
                                if(v + jdy < 0) continue;
                                if(v + jdy > n - 1) break;
                                for(int h = 0; h < n; h++)
                                {
                                    if(h + jdx < 0) continue;
                                    if(h + jdx > n - 1) break;
                                    tmp_piece_j[v][h] = pieces[j][v+jdy][h+jdx];
                                }
                            }

                            bool valid = check_merge_pieces(tmp_piece_i, tmp_piece_j, figurine, n);
                            if(valid)
                            {
                                cout << i + 1 << " " << j + 1;
                                return;
                            }
                        }
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