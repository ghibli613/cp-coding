#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> ways(30001, 0);
int changeTypes[] = {1, 5, 10, 25, 50};

int main()
{
    ways[0] = 1;
    for (int c = 0; c < 5; ++c)
    {
        for (int i = changeTypes[c]; i < 30001; ++i)
        {
            ways[i] += ways[i - changeTypes[c]];
        }
    }
    int cents;
    while (cin >> cents)
    {
        if (ways[cents] == 1)
            cout << "There is only 1 way to produce " << cents << " cents change.\n";
        else
            cout << "There are " << ways[cents] << " ways to produce " << cents << " cents change.\n";
    }
}