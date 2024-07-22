#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m, y0, y1;
    cin >> n >> m >> y0 >> y1;
    vector<int> mice(n), cheeses(m);
    for (int i = 0; i < n; i++)
        cin >> mice[i];
    for (int i = 0; i < m; i++)
        cin >> cheeses[i];
    int k = 0, j = 0, last = -1;
    for (int i = 0; i < n; i++)
    {
        while (j < m - 1 && abs(mice[i] - cheeses[j + 1]) < abs(mice[i] - cheeses[j]))
            ++j;
        if (last < j || (i > 0 && abs(mice[i - 1] - cheeses[j]) == abs(mice[i] - cheeses[j])))
        {
            last = j;
            k++;
        }
        else if (j < m && (abs(mice[i] - cheeses[j + 1]) == abs(mice[i] - cheeses[j])))
        {
            k++;
            last = ++j;
        }
    }
    cout << n - k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}