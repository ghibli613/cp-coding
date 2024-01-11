#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    set<string> ss;
    sort(s.begin(), s.end());
    do
    {
        ss.insert(s);
    } while(next_permutation(s.begin(), s.end()));  
    cout << ss.size() << '\n';
    for(string i : ss)
        cout << i << '\n';
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