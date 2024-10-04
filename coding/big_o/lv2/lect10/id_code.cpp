#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while(true)
    {
        cin >> s;
        if(s == "#") break;
        if(next_permutation(s.begin(), s.end()))
            cout << s << '\n';
        else
            cout << "No Successor\n";
    }

    return 0;
}