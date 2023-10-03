#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s;
    int num = 0, ans = 0;
    while (getline(cin, s))
    {
        
        if(s[0] == '+') num++;
        else if(s[0] == '-') num--;
        else
        {
            int ind = s.find(":");
            string mess = s.substr(ind + 1, int(s.size()) - ind);
           
            ans += int(mess.size()) * num;
        }
        
    }
    cout << ans << '\n';
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