#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

    for(int i = 0; i < 4; i++) 
    {
        int x, y;
        cin >> x >> y;
        if(x < min_x) min_x = x;
        if(y < min_y) min_y = y;
        if(x > max_x) max_x = x;
        if(y > max_y) max_y = y;
    }

    int side = max(max_x - min_x, max_y - min_y);
    cout << side * side;    
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

