#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll x1, x2; cin >> x1 >> x2;

    vector<pll> seg(n);
    for(int i = 0; i < n; i++)
    {
        ll k, b; cin >> k >> b;
        seg[i].first = k * x1 + b;
        seg[i].second = k * x2 + b;
    }
    sort(seg.begin(), seg.end());
    priority_queue<ll> my_pq;

    my_pq.push(seg[0].second);
    for(int i = 1; i < n; i++)
    {
        if(seg[i].second < my_pq.top())
        {
            cout << "YES";
            return 0;
        }
        my_pq.push(seg[i].second);
    }
    cout << "NO";

    return 0;
}