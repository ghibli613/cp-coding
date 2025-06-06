#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    bool flag = false;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (n - x < 5 || m - y < 5 || x <= 5 || y <= 5)
            flag = true;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}