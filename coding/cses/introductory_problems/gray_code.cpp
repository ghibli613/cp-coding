#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s = "";

int n;

void gray_code(int tmp_n)
{
    if(tmp_n == 0) cout << s << '\n';
    else
    {
        gray_code(tmp_n - 1);
        if(s[n - tmp_n] == '0') s[n - tmp_n] = '1';
        else s[n - tmp_n] = '0';
        gray_code(tmp_n - 1);
    }
}

void solve()
{
    int tmp_n; cin >> tmp_n; n = tmp_n;
    for(int i = 0; i < tmp_n; i++) s.push_back('0');

    gray_code(tmp_n);
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