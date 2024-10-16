#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    map<pii, int> mm;

    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        int GCD = __gcd(a, b);
        a /= GCD;
        b /= GCD;
        if(a > b) swap(a, b);
        if(mm[{a, b}] == 0) cnt++;
        mm[{a, b}]++;
        if(mm[{a, b}] > ans) ans = mm[{a, b}];
    }

    cout << cnt << ' ' << ans;

    return 0;
}