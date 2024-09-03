#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> nex(n + 1), cot(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i == 1 && x != 1) 
        {
            ans++;
            continue;
        } 
        else 
        {
            nex[i] = x;
            cot[x]++;
        }
    }
    
    queue<int> Q;
    int t = 0, h = 0;
    for (int i = 2; i <= n; i++)
        if (!cot[i])
            Q.push(i);

    vector<int> dep(n + 1, 0);

    while (!Q.empty()) 
    {
        int u = Q.front();
        Q.pop();
        if (u == 1)
            break;

        if (nex[u] != 1 && dep[u] == (k - 1))
            ans++;
        else
            dep[nex[u]] = max(dep[nex[u]], dep[u] + 1);

        cot[nex[u]]--;

        if (!cot[nex[u]])
            Q.push(nex[u]);
    }
    cout << ans << endl;
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