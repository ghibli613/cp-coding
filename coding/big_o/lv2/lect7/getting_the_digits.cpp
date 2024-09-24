#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    vector<int> a(26, 0);
    string s; cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
    {
        a[s[i] - 'A']++;
    }
    
    vector<int> cnt(10, 0);

    cnt[0] = a['Z' - 'A'];
    a['Z' - 'A'] = 0;
    a['E' - 'A'] -= cnt[0];
    a['R' - 'A'] -= cnt[0];
    a['O' - 'A'] -= cnt[0];

    cnt[2] = a['W' - 'A'];
    a['W' - 'A'] = 0;
    a['T' - 'A'] -= cnt[2];
    a['O' - 'A'] -= cnt[2];

    cnt[4] = a['U' - 'A'];
    a['U' - 'A'] = 0;
    a['F' - 'A'] -= cnt[4];
    a['O' - 'A'] -= cnt[4];
    a['R' - 'A'] -= cnt[4];

    cnt[6] = a['X' - 'A'];
    a['X' - 'A'] = 0;
    a['S' - 'A'] -= cnt[6];
    a['I' - 'A'] -= cnt[6];

    cnt[8] = a['G' - 'A'];
    a['G' - 'A'] = 0;
    a['E' - 'A'] -= cnt[8];
    a['I' - 'A'] -= cnt[8];
    a['H' - 'A'] -= cnt[8];
    a['T' - 'A'] -= cnt[8];

    cnt[1] = a['O' - 'A'];
    a['O' - 'A'] = 0;
    a['E' - 'A'] -= cnt[1];
    a['N' - 'A'] -= cnt[1];

    cnt[3] = a['R' - 'A'];
    a['R' - 'A'] = 0;
    a['T' - 'A'] -= cnt[3];
    a['H' - 'A'] -= cnt[1];
    a['E' - 'A'] -= cnt[3] * 2;

    cnt[5] = a['F' - 'A'];
    a['F' - 'A'] = 0;
    a['I' - 'A'] -= cnt[5];
    a['V' - 'A'] -= cnt[5];
    a['E' - 'A'] -= cnt[5];

    cnt[7] = a['S' - 'A'];
    a['S' - 'A'] = 0;
    a['E' - 'A'] -= cnt[7];
    a['V' - 'A'] -= cnt[7];
    a['E' - 'A'] -= cnt[7];
    a['N' - 'A'] -= cnt[7];

    cnt[9] = a['I' - 'A'];
    a['I' - 'A'] = 0;
    a['E' - 'A'] -= cnt[9];
    a['N' - 'A'] -= cnt[9] * 2;

    for(int i = 0; i < 10; i++)
    {
        while(cnt[i]--)
        {
            cout << i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}