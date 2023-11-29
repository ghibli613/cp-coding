#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1; i <= n; i++)
    {
        unordered_set<string> se;
        bool check = true;
        for(int j = 0; j < n - i + 1; j++)
        {
            string tmp = "";
            for(int t = 0; t < i; t++)
                tmp += s[j + t];

            if(se.count(tmp))
            {
                check = false;
                break;
            }
            cout << tmp << " ";
            se.insert(tmp);
        }
        if(check) 
        {
            cout << i;
            return;
        }
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