#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n, n != 0)
    {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0, temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += a[i];
            if (temp > ans)
                ans = temp;
            if (temp < 0)
                temp = 0;
        }

        if (ans > 0)
            cout << "The maximum winning streak is " << ans << ".\n";
        else
            cout << "Losing streak.\n";
    }

    return 0;
}