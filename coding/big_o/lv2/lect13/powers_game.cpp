#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    vector<int> ans(10, 0);

    ll tmp = 1;
    for (int i = 1; i <= n; i++)
    {
        tmp *= (1LL * x);

        ll tmp2 = tmp;
        while (tmp2 > 0)
        {
            ans[tmp2 % 10]++;
            tmp2 /= 10;
        }
    }
    for (int a: ans) {
        cout << a << " ";
    }

    return 0;
}