#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    vector<string> a(3);
    cin >> a[0] >> a[1] >> a[2];
    if((a[0] == a[1] && a[0] == "rock" && a[2] == "paper") || (a[0] == a[1] && a[0] == "paper" && a[2] == "scissors") || (a[0] == a[1] && a[0] == "scissors" && a[2] == "rock"))
    {
        cout << "S";
    }
    else if((a[0] == a[2] && a[2] == "rock" && a[1] == "paper") || (a[0] == a[2] && a[2] == "paper" && a[1] == "scissors") || (a[0] == a[2] && a[0] == "scissors" && a[1] == "rock"))
    {
        cout << "M";
    }
    else if((a[1] == a[2] && a[2] == "rock" && a[0] == "paper") || (a[1] == a[2] && a[2] == "paper" && a[0] == "scissors") || (a[1] == a[2] && a[1] == "scissors" && a[0] == "rock"))
    {
        cout << "F";
    }
    else cout << "?";
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