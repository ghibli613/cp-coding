#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int cnt = 0; 
    for(int msk = 0; msk < (1 << n); msk++)
    {
        int mi = MOD, ma = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if((msk >> i) & 1)
            {
                mi = min(mi, c[i]);
                ma = max(ma, c[i]);
                sum += c[i];
            }
        }
        if(ma - mi >= x && l <= sum && sum <= r) cnt++;
    }

    cout << cnt;

    return 0;
}