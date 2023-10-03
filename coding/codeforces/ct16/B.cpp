#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, m; cin >> n >> m;
    map<int, int> my_map;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        if(my_map.find(b) == my_map.end())
            my_map[b] = a;
        else my_map[b] += a;
    }
    map<int, int>::iterator it = my_map.end();
    it--;
    int ans = 0;
    while(it != my_map.begin())
    {
        if(it->second >= n)
        {
            ans += n * it->first;
            n = 0;
            break;
        }
        else
        {
            ans += it->second * it->first;
            n -= it->second;
        }
        it--;
    }
    if(n != 0)
    {
        if(it->second >= n)
        {
            ans += n * it->first;
            n = 0;
        }
        else
        {
            ans += it->second * it->first;
            n -= it->second;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
