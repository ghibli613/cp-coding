#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while (cin >> s)
    {
        string ans = "";
        int bestValue = -1; /// lưu giá trị chênh lệch lớn nhất của các xâu
        int cnt = 0;
        do
        {
            cnt++;
            if (cnt == 11)
            {
                break;
            }
        } while (prev_permutation(s.begin(), s.end()));
        if (cnt < 11)
            next_permutation(s.begin(), s.end());
        cnt = 0;

        do
        {
            int minDiff = 30;
            for (int i = 0; i < (int)s.size() - 1; i++)
            {
                minDiff = min(minDiff, abs(s[i] - s[i + 1]));
            }
            if (bestValue < minDiff)
            {
                ans = s;
                bestValue = minDiff;
            }
            cnt++;
            if (cnt == 21)
            {
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << ans << bestValue << '\n';
    }

    return 0;
}