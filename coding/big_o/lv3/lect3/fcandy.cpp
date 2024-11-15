#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int S = 0;
    vector<int> f(n * 200 * 500, 0), f1(n * 200 * 500, 0), cnt(n * 200 * 500, 0);
    f[0] = f1[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int k, c; cin >> k >> c;
        S += k * c;
        for(int j = 0; j <= S; j++)
        {
            cnt[j] = f1[j];
            if(j >= c)
            {
                cnt[j] += cnt[j - c];
                if(j >= (k + 1) * c) cnt[j] -= f1[j - (k + 1) * c];
            }
            f[j] = (cnt[j] > 0);
        }
        f1 = f;
    }
    int x = S / 2;
    while(!f[x])
    {
        x--;
    }
    cout << S - x - x;

    return 0;
}