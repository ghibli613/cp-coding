#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

bool isDivisible(string s, int digit)
{
    int ans = 0;
    for(char c : s)
        ans = (ans * 10 + (c - '0')) % digit;
    return (ans == 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;

    int ans = 0;

    bool divideEvenly[10]{0};
    for(int i = 1; i < 10; i++)
        divideEvenly[i] = isDivisible(n, i);
    for(int i = 0; i < (int)n.size(); i++)
        if(divideEvenly[n[i] - '0']) ans++;

    cout << ans;

    return 0;
}