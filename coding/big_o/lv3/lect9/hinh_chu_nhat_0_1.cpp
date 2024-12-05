#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int find_max(vector<int> &a)
{
    int n = (int)a.size();
    vector<int> l(n), r(n);
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        l[i] = (st.empty() ? 0 : st.top() + 1);
        st.push(i);
    }
    while(!st.empty()) st.pop(); // clear
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        r[i] = (st.empty() ? n - 1 : st.top() - 1);
        st.push(i);
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, a[i] * (r[i] - l[i] + 1));
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            for(int j = 0; j < m; j++)
                a[i][j] = (a[i - 1][j] + 1) * a[i][j];
        }
        
        ans = max(ans, find_max(a[i]));
        // cout << ans << '\n';
    }
    cout << ans;
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