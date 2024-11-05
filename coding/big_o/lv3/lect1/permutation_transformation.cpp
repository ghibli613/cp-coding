#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a;
vector<int> ans;
int d;

void find_max(int l, int r)
{
    d++;
    if(l >= r)
    {
        ans[l] = d;
    }
    else
    {
        int max_i = l;
        for(int i = l + 1; i <= r; i++)
        {
            if(a[i] > a[max_i]) max_i = i;
        }
        ans[max_i] = d;
        if(max_i == l) find_max(max_i + 1, r);
        else if(max_i == r) find_max(l, max_i - 1);
        else 
        {
            find_max(max_i + 1, r);
            find_max(l, max_i - 1);
        }
    }
    d--;
}

void solve()
{
    int n; cin >> n;
    a.assign(n, 0); ans.assign(n, 0);
    d = -1;
    for(int i = 0; i < n; i++) cin >> a[i];
    find_max(0, n - 1);
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
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