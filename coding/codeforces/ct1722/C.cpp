#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    map<string, int> my_map;
    int n; cin >> n;
    vector<vector<string>> a(3, vector<string>(n));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if(my_map.find(a[i][j]) == my_map.end()) my_map[a[i][j]] = 1;
            else my_map[a[i][j]]++;
        }
    
    for(int i = 0; i < 3; i++)
    {
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            if(my_map.find(a[i][j]) != my_map.end())
            {
                if(my_map[a[i][j]] == 1) ans += 3;
                else if(my_map[a[i][j]] == 2) ans++;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
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