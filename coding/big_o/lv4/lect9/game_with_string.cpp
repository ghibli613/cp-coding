#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt[26][5011][26], n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = (int)s.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ++cnt[s[i] - 'a'][j][s[(i + j) % n] - 'a'];
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i)
    {
        int win = 0;
        for (int j = 0; j < n; ++j)
        {
            int tmp = 0;
            for (int k = 0; k < 26; ++k)
                tmp += (cnt[i][j][k] == 1);
            win = max(win, tmp);
        }
        ans += win;
    }

    printf("%.8lf\n", (double)ans / n);
    return 0;

    return 0;
}