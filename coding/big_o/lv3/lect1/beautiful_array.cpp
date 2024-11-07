#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> beautifulArray(int n)
{
    if (n == 1)
        return vector<int>{1};

    int evens = n / 2;
    int odds = n - evens;
    vector<int> oddarr = beautifulArray(odds);
    vector<int> evenarr = beautifulArray(evens);
    vector<int> ans(n);
    int i = 0;
    for (int j : oddarr)
        ans[i++] = 2 * (j - 1) + 1;
    for (int j : evenarr)
        ans[i++] = 2 * j;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> res = beautifulArray(n);

    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}