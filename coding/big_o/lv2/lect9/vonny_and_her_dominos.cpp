#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

vector<vector<int>> F(7, vector<int>(7)), box(7, vector<int>(8)), visited(7, vector<int>(8, 0));
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int result;

void backtracking(int x, int y)
{
    if (x == 7)
    {
        result++;
        return;
    }
    if (visited[x][y] == 0)
    {
        int one, two;
        one = box[x][y];
        for (int i = 0; i < 2; i++)
        {
            int tempx = x + dx[i];
            int tempy = y + dy[i];
            if (tempx >= 0 && tempx < 7 && tempy >= 0 && tempy < 8 && visited[tempx][tempy] == 0)
            {
                two = box[tempx][tempy];
                if (one <= two && F[one][two])
                {
                    F[one][two] = 0;
                    visited[x][y] = visited[tempx][tempy] = 1;
                    if (y < 7)
                        backtracking(x, y + 1);
                    else
                        backtracking(x + 1, 0);
                    visited[x][y] = visited[tempx][tempy] = 0;
                    F[one][two] = 1;
                }
                else if (F[two][one])
                {
                    F[two][one] = 0;
                    visited[x][y] = visited[tempx][tempy] = 1;
                    if (y < 7)
                        backtracking(x, y + 1);
                    else
                        backtracking(x + 1, 0);
                    visited[x][y] = visited[tempx][tempy] = 0;
                    F[two][one] = 1;
                }
            }
        }
    }
    else
    {
        if (y < 7)
            backtracking(x, y + 1);
        else
            backtracking(x + 1, 0);
    }
}

void solve()
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 8; j++)
            cin >> box[i][j];

    result = 0;
    backtracking(0, 0);
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 0; i < 7; i++)
        for (int j = i; j < 7; j++)
            F[i][j] = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}