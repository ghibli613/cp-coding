#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    for(int i = 0; i < 3; i++)
    {
        vector<bool> a(3, false);
        for(int j = 0; j < 3; j++)
        {
            char tmp; cin >> tmp;
            if(tmp == 'A') a[0] = true;
            else if(tmp == 'B') a[1] = true;
            else if(tmp == 'C') a[2] = true;
        }
        for(int j = 0; j < 3; j++) if(a[j] == false)
        {
            char tmp = 'A';
            cout << char(tmp + j) << '\n';
        }
    }
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