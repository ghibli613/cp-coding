#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s, t, censored;
    cin >> s >> t;
    // Add each character to the censored string
    for (int i = 0; i < (int)s.size(); i++) 
    {
        censored += s[i];
        // If the end of the string is t, we remove t from the end
        if (censored.size() > t.size() && censored.substr(censored.size() - t.size()) == t) 
            censored.resize(censored.size() - t.size());
    }
    
    cout << censored << endl;
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