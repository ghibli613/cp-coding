#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a;

vector<int> lis()
{
    // dbg(a.size())
    vector<int> lis, L(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (lis.empty() || x > lis.back())
        {
            lis.push_back(x);
            L[i] = lis.size();
        }
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[pos] = x;
            L[i] = pos + 1;
        }
    }
    return L;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        a.clear(); a.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> L = lis();
        reverse(a.begin(), a.end());

        vector<int> R = lis();
        reverse(R.begin(), R.end());
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, min(L[i], R[i]) * 2 - 1);
        cout << ans << '\n';
    }

    return 0;
}