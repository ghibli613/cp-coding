#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

ll pow10[20], n, ans;
bool hasRes = 0;

int getDigit(int pos)
{
    if(pos == 19) return n / pow10[pos - 1];
    return (n / pow10[pos - 1]) % 10;
}

void backtracking(int pos, ll res, vector<int> cnt, bool isGreater)
{
    if(hasRes) return;
    if(pos == 0)
    {
        ans = res;
        hasRes = true;
        return;
    }
    int x = getDigit(pos);
    if(isGreater) x = 9;
    bool ok = isGreater;
    for(int i = x; i >= 0; i--)
    {
        if(cnt[i] < 2)
        {
            if(i < x) ok = true;
            if(res > 0 || i > 0) cnt[i] += 1;
            res += 1ll * i * pow10[pos - 1];
            backtracking(pos - 1, res, cnt, ok);
            res -= 1ll * i * pow10[pos - 1];
            if(res > 0 || i > 0) cnt[i] -= 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pow10[0] = 1;
    for(int i = 1; i <= 18; i++)
        pow10[i] = pow10[i - 1] * 10;

    while(cin >> n)
    {
        vector<int> cnt(10, 0);
        hasRes = 0;
        backtracking(19, 0, cnt, 0);
        cout << ans << '\n';
        
    }

    return 0;
}