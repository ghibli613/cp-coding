#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> kmpPreprocess(string p)
{
    int m = p.length();
    vector<int> pref(m, 0);

    int j = 0;
    for(int i = 1; i < m; i++)
    {
        while(j > 0 && p[j] != p[i])
            j = pref[j - 1];
        if(p[i] == p[j])
            j++;
        pref[i] = j;
    }

    return pref;
}

bool kmpSearch(string t, string p, vector<int>& pref)
{
    int n = t.length(), m = p.length();
    vector<int> found;

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j > 0 && t[i] != p[j])
            j = pref[j - 1];
        if(t[i] == p[j])
            j++;

        if(j == m)
        {
            return 1;
        }
    }

    return 0;
}

int common(string t1, string t2)
{
    if((int)t1.size() > (int)t2.size())
    {
        vector<int> pref = kmpPreprocess(t2);
        if(kmpSearch(t1, t2, pref)) return (int)t2.size();
    }
    else
    {
        vector<int> pref = kmpPreprocess(t1);
        if(kmpSearch(t2, t1, pref)) return (int)t1.size();
    }

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    vector<string> s(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> s[i];
        ans += s[i].size();
    }
    sort(s.begin(), s.end());

    int L = ans;
    // cout << L;
    do
    {
        int tmp = L;
        for(int i = 1; i < 3; i++)
        {
            tmp -= common(s[i - 1], s[i]);
        }
        ans = min(tmp, ans);
        // cout << tmp << '\n';
    } while (next_permutation(s.begin(), s.end()));
    
    cout << ans << '\n';

    return 0;
}