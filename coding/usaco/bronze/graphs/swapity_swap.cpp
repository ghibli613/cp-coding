#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a1, a2, b1, b2; 

int next(int x)
{
    if(a1 <= x && x <= a2)
        x = a1 + a2 - x;
    if(b1 <= x && x <= b2)
        x = b1 + b2 - x;
    return x;
}

void solve()
{
    int n, k; cin >> n >> k;
    cin >> a1 >> a2 >> b1 >> b2;
    vector<int> res(n);

    for(int i = 1; i <= n; i++)
    {
        int p = 1, cur =  next(i);
        while(cur != i)
        {
            p++;
            cur = next(cur);
        }
        int new_k = k % p;
        for(int j = 0; j < new_k; j++)
            cur = next(cur);
        res[cur - 1] = i;
    }
    for(int i = 1; i <= n; i++) cout << res[i - 1] << "\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}