#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s, ans; cin >> s;
    ans = s;
    int n; cin >> n;
    int n_s = s.size();
    
    for(int i = 0; i < n; i++)
    {
        string tmp; cin >> tmp;
        if(tmp == s)
        {
            ans = s;
            break;
        }
        else if(int(tmp.size()) > n_s && tmp.substr(0, n_s) == s)
        {
            if(ans == s) ans = tmp;
            else if(ans[n_s] > tmp[n_s]) ans = tmp;
            else if(ans[n_s] == tmp[n_s])
            {
                
                int j = n_s;
                j++;
                while(j < int(min(ans.size(), tmp.size())))
                {
                    if(ans[j] > tmp[j])
                    {
                        ans = tmp;
                        break;
                    }
                    else if(ans[j] < tmp[j]) break;
                    j++;
                }
                if(j == int(min(ans.size(), tmp.size())) && int(ans.size()) > int(tmp.size()))
                    ans = tmp;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}