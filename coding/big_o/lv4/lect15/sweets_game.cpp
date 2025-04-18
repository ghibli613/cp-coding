#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int L[5] = {0, 0, 0, 1, 2};
int R[5] = {2, 3, 4, 4, 4};

int id[5][5];

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

bool valid(int x, int y)
{
    return 0 <= x && x < 5 && L[x] <= y && y <= R[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(id, -1, sizeof(id));

    int mask = 0;

    int n = 0;
    for (int x = 0; x < 5; x++)
    {
        for (int y = L[x]; y <= R[x]; y++)
        {
            id[x][y] = n;
            char c;
            cin >> c;
            if (c == 'O')
            {
                mask |= 1 << n;
            }
            n += 1;
        }
    }

    vector<bool> win(1 << n, 0);

    for (int s = 0; s < (1 << n); s++)
    {
        for (int x = 0; x < 5; x++)
        {
            for (int y = L[x]; y <= R[x]; y++)
            {
                if (s >> id[x][y] & 1)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        int t = 0;
                        int i = x, j = y;
                        while (valid(i, j) && (s >> id[i][j] & 1))
                        {
                            t |= 1 << id[i][j];
                            win[s] = win[s] || !win[s ^ t];
                            i += dx[k];
                            j += dy[k];
                        }
                    }
                }
            }
        }
    }

    cout << (win[mask] ? "Karlsson" : "Lillebror") << "\n";

    return 0;
}