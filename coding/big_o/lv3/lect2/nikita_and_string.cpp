#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = (int)s.size();
    vector<int> prefixa(n + 1, 0), prefixb(n + 1, 0);

    for(int i = 0; i < n; i++)
    {
        prefixa[i + 1] = prefixa[i] + (s[i] == 'a');
        prefixb[i + 1] = prefixb[i] + (s[i] == 'b');
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            ans = max(ans, prefixa[n] - prefixa[j] + prefixb[j] - prefixb[i] + prefixa[i]);
        }
    }
    cout << ans;

    return 0;
}