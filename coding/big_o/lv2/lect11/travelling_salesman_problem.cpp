#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n;
vector<vector<ll>> c;
vector<int> a, b;
ll s = 1e15, S = 0;

void solve(int x)
{
    for (int i = 1; i < n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n - 1 && S + c[i][0] < s)
                s = S + c[i][0];
            else if (S < s && x < n - 1)
                solve(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    c.assign(n, vector<ll>(n));
    a.assign(n, 0);
    b.assign(n, 0);

    a[0] = 0;
    b[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    solve(1);
    cout << s;
    return 0;
}