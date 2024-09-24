#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

vector<string> grid(2);
int guards, n;

int isSingle(int i, int j)
{
    if (grid[i][j] != '.')
        return false;
    if (j == 0)
        return grid[i][j + 1] == 'X';
    if (j == n - 1)
        return grid[i][j - 1] == 'X';
    return grid[i][j + 1] == 'X' && grid[i][j - 1] == 'X';
}

bool putGuard(int i, int j)
{
    if (grid[i][j] != '.')
        return false;

    guards++;
    if (grid[1 - i][j] != 'X')
        grid[1 - i][j] = 'G';

    for (int j2 = j; j2 >= 0 && grid[i][j2] != 'X'; j2--)
        grid[i][j2] = 'G';
    for (int j2 = j; j2 < n && grid[i][j2] != 'X'; j2++)
        grid[i][j2] = 'G';
    return true;
}

void solve()
{
    cin >> n;

    cin >> grid[0] >> grid[1];

    guards = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isSingle(i, j))
            {
                putGuard(1 - i, j) || putGuard(i, j);
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
                putGuard(i, j);
        }
    }

    cout << guards << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}