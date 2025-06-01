#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while(cin >> n >> m)
    {
        vector<int> a(m);
        for(int i = 0; i < m; i++) cin >> a[i];
        vector<bool> f(n + 1, 0);
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < m; j++)
                if(a[j] <= i && f[i - a[j]] == 0)
                    f[i] = 1;

        if(f[n]) cout << "Stan";
        else cout << "Ollie";
        cout << " wins\n";
    }

    return 0;
}