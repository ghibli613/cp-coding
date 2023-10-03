#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    ll n; cin >> n;
    vector<char> line(n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> line[i];
        if(line[i] == 'L') ans += i;
        else ans += n-1 - i;
    }
    ll cnt = 0;
    for(int i = 0; i < n/2; i++)
    {
        if(line[i] == 'L')
        {
            cnt++;
            ans += 0 - i + n-1 - i;
            cout << ans << " ";
        }
        if(line[n-1-i] == 'R')
        {
            cnt++;
            ans += (n-1-i) - (n-1) + (n-1-i);
            cout << ans << " ";
        }
    }
    while(cnt < n)
    {
        cout << ans << " ";
        cnt++;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}