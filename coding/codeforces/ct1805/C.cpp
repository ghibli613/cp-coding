#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, m; cin >> n >> m;
    set<ll> k;
    for(int i = 0; i < n; i++)
    {
        ll tmp; cin >> tmp;
        k.insert(tmp);
    }
    vector<vector<ll>> para(m, vector<ll>(3));
    for(int i = 0; i < m; i++) cin >> para[i][0] >> para[i][1] >> para[i][2];
    
    for(int j = 0; j < m; j++)
    {
        if(para[j][2] < 0) 
        {
            cout << "NO\n";
            continue;
        }
        else
        {    
            set<ll>::iterator itlow = k.lower_bound(para[j][1]);
            
            int ans = 0;

            if(itlow == k.end())
            {
                itlow--;
                ans = *itlow;
            }
            else ans = *itlow;
            if(itlow != k.begin())
            {
                itlow--;
                if(abs(ans - para[j][1]) > abs(*itlow - para[j][1]))
                    ans = *itlow;
            }
            if((ans - para[j][1]) * (ans - para[j][1]) - 4 * para[j][0] *para[j][2] < 0)
            {
                cout << "YES\n" << ans << '\n';
                continue;
            }
    
        }
        cout << "NO\n";
        
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