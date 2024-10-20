#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string sn; getline(cin, sn);
    vector<int> a;
    string s = "";
    for(int i = 0; i < (int)sn.size(); i++)
    {
        if(sn[i] != ' ')
        {
            s.push_back(sn[i]);
        }
        else
        {
            a.push_back(stoi(s));
            s = "";
        }
    }
    a.push_back(stoi(s));
    int ans = 0;
    for(int i = 0; i < (int)a.size() - 1; i++)
        for(int j = i + 1; j < (int)a.size(); j++)
        {
            int tmp = __gcd(a[i], a[j]);
            if(ans < tmp) ans = tmp;
        }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string st;
    getline(cin, st);
    int t = stoi(st);

    while(t--)
        solve();

    return 0;
}