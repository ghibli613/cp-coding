#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    int result = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            int cnt = j - i + 1;
            int sum = 0;
            for(int t = i; t < j+1; t++) sum += p[t];
            if(sum % cnt != 0) continue;
            int aver = sum / cnt;
            for(int t = i; t < j+1; t++)
                if(p[t] == aver)
                {
                    result++;
                    break;
                }
        }

    cout << result;
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