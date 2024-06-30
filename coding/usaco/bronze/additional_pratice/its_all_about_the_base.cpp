#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int MAXB = 15000;

int evaluate(const string& num, int base) 
{
    return (num[0] - '0') * base * base + (num[1] - '0') * base + (num[2] - '0');
}

void solve()
{
    string num_in_x, num_in_y;
    cin >> num_in_x >> num_in_y;

    int X = 10;
    int Y = 10;

    while (X <= MAXB && Y <= MAXB) 
    {
        int num_x = evaluate(num_in_x, X);
        int num_y = evaluate(num_in_y, Y);
        if (num_x < num_y)
            X++;
        else if (num_y < num_x)
            Y++;
        else 
        {
            cout << X << ' ' << Y << '\n';
            break;
        }
    } 
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