#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    int n; cin >> n;
    vector<int> c(n);
    int check = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        check ^= c[i];
        sum += c[i];
    }
    cout << "Case #" << tc << ": ";
    if(!check)
    {
        int min_ = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(c[i] < min_) 
                min_ = c[i];
        }
        cout << sum - min_ << '\n';
    } 
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc + 1);

    return 0;
}