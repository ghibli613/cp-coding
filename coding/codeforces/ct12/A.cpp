#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    vector<vector<char>> a(3, vector<char>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) 
            cin >> a[i][j];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 1; j++)
            if(a[i][j] != a[3-1-i][3-1-j])
            { 
                cout << "NO";
                return;
            }

    for(int i = 0; i < 1; i++)
        if(a[i][1] != a[3-1-i][1]) 
        {
            cout << "NO";
            return;
        }
    cout << "YES";
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