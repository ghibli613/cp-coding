#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    int a[26]{0};
    int n = (int)s.size();
    for(int i = 0; i < n; i++)
        a[s[i] - 'A']++;
    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(a[i] % 2 != 0) cnt++;
    
    if(cnt > 1)
    {
        cout << "NO SOLUTION";
        return;
    }
    else
    {
        int idx = -1;
        for(int i = 0; i < 26; i++)
        {
            if(a[i] % 2 != 0) idx = i;
            for(int j = 0; j < a[i] / 2; j++)
            {
                cout << char(i + 'A');
            }
        }
        if(idx != -1) 
        {
            cout << char(idx + 'A');
            a[idx]--;
        }
        for(int i = 25; i > -1; i--)
            for(int j = 0; j < a[i] / 2; j++)
                cout << char(i + 'A');
    }
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