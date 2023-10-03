#include<bits/stdc++.h>
using namespace std;
// #include "../debug.h"
typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{ 
    int n; cin >> n;
    string a; cin >> a;
    for(int i = 0; i < n; i++)
    {
        if(i+2 < n && a[i+2] == '0')
        {
            if((i+3 < n && a[i+3] != '0') || i + 3 >= n)
            {
                string tmp = "";
                tmp.push_back(a[i]);
                tmp.push_back(a[i+1]);
                i += 2;
                char k = atoi(tmp.c_str()) + 96;
                // dbg(k, i);
                cout << k;
            }
            else
            {
                string tmp = "";
                tmp.push_back(a[i]);
                char k = atoi(tmp.c_str()) + 96;
                // dbg(k, i);
                cout << k;
            }
        }
        else 
        {
            string tmp = "";
            tmp.push_back(a[i]);
            char k = atoi(tmp.c_str()) + 96;
            // dbg(k, i);
            cout << k;
        }
    }
    cout << '\n';
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