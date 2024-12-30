#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define MAXN 105

char a[MAXN][MAXN];
int n, m, reNum;

ii trace[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool backTracking(int i, int j, int num)
{
    if (i < 1 || j < 1 || i > n || j > m || a[i][j] == '#' || num > reNum)
        return false;
    if (a[i][j] == 'x' && num == reNum)
        return true;
    char s = a[i][j];
    a[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (backTracking(x, y, num + (a[x][y] == 's')))
        {
            trace[x][y] = {i, j};
            return true;
        }
    }
    a[i][j] = s;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> reNum;
    int start_i = 0, start_j = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
        }
    if (backTracking(start_i, start_j, 0))
        cout << "SUCCESS" << '\n';
    else
        cout << "IMPOSSIBLE" << '\n';
}