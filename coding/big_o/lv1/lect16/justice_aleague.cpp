#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int na, nb, nc, ta, tb, tc, k;
    cin >> na >> nb >> nc >> ta >> tb >> tc >> k;
    vector<int> a(na), b(nb), c(nc);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int &x : c)
        cin >> x;

    if (k >= min(na, nc))
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> nxtC(nb);
    for (int i = 0, j = 0; i < nb; i++)
    {
        while (j < nc && c[j] < b[i] + tb)
            j++;
        nxtC[i] = j;
    }

    int res = -1;
    for (int i = 0, j = 0; i < na; i++)
    {
        if (i > k)
            break;
        while (j < nb && b[j] < a[i] + ta)
            j++;
        if (j < nb && nxtC[j] + k - i < nc)
        {
            res = max(res, c[nxtC[j] + k - i] + tc);
        }
        else
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << res;
    return 0;
}