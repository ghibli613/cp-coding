#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ma;

vector<vector<int>> d(20);

void f(int ll, int rr, int now)
{
    if (ll == rr)
        return;
    int mm = (ll + rr) / 2;
    ma = max(ma, now);
    for (int i = ll; i <= mm; i++)
        d[now].push_back(i);
    f(ll, mm, now + 1);
    f(mm + 1, rr, now + 1);
}

int main()
{
    int n;
    cin >> n;
    f(1, n, 1);
    cout << ma << '\n';
    for (int i = 1; i <= ma; i++)
    {
        cout << (int)d[i].size() << ' ';
        for (int j = 0; j < (int)d[i].size(); j++)
            cout << d[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}