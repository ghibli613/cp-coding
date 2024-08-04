#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n, string s, int k, int mid, vector<int> prefix)
{
    for(int i = 1; i <= n; i++)
    {
        if(s[i - 1] == '0')
        {
            int val = prefix[min(n, i + mid)] - prefix[max(0, i - mid - 1)];
            if(val >= k + 1)
                return true;
        }
    }
    return false;
}

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> prefix(n + 1);

    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (s[i - 1] == '0');
    }

    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(n, s, k, mid, prefix)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1;
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