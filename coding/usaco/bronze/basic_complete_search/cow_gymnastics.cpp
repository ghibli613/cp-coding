#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int k, n; cin >> k >> n;
    vector<vector<int>> a(k, vector<int>(n));
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
        {
            int tmp; cin >> tmp;
            a[i][tmp - 1] = j;
        }
    
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool check = true;
            for(int t = 0; t < k; t++)
                if(a[t][i] >= a[t][j])
                {
                    check = false;
                    break;
                }
            if(check) 
            {
                result++;
            }
        }
    }
    cout << result << '\n';
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
