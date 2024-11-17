#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int v[26];
ll sum[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 26; i++) cin >> v[i];
    string s; cin >> s;

    int n = s.size();

    ll ans = 0;
    map<pair<char, ll>, ll> count_pair;
    for(int i = 0; i < n; i++)
    {
        sum[i] = v[s[i] - 'a'];
        if(i > 0) sum[i] += sum[i - 1];
        ans += count_pair[{s[i], sum[i - 1]}];
        count_pair[{s[i], sum[i]}]++;
    }
    cout << ans;

    return 0;
}