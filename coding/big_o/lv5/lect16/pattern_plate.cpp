#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

int cmp(double x, double y)
{
    if(x < y - EPS)
        return -1;
    else if(x > y + EPS)
        return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, R, r;
    cin >> n >> R >> r;

    if(R < 2 * r)
    {
        if(r > R) cout << "NO\n";
        else if(n == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    else
    {
        double angle = PI / n;
        double distance = (R - r) * sin(angle);

        if(cmp(distance, (double)r) >= 0) 
            cout << "YES";
        else cout<< "NO";
    }

    return 0;
}