#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int common(string t1, string t2)
{
    string t = t2 + t1;
    int n = t.size();
    vector<int> pref(n, 0);

    int j = 0;
    for(int i = 1; i < n; i++)
    {
        while(j > 0 && t[j] != t[i])
            j = pref[j - 1];

        if(t[i] == t[j])
            j++;
        pref[i] = j;
    }
    return min((int)t1.size(), pref.back());
}

void solve()
{
    int k, w; cin >> k >> w;
    string prev = "";
    int ans = k * w;

    for(int i = 1; i <= w; i++)
    {
        string s;
        cin >> s;

        if(prev != "")
            ans -= common(prev, s);
        
        prev = s;
    }
    cout << ans << "\n";
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