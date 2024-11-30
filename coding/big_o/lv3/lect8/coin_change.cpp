#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> ways(7490, 0);
int changeTypes[] = {1, 5, 10, 25, 50};

int main()
{
    ways[0] = 1;
    for (int c = 0; c < 5; ++c)
    {
        for (int i = changeTypes[c]; i <= 7489; ++i)
        {
            ways[i] += ways[i - changeTypes[c]];
        }
    }
    int cents;
    while (cin >> cents)
    {
        cout << ways[cents] << "\n";
    }
}