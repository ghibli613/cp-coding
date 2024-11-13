#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    vector<ll> ways(251, 0);
    vector<int> changeTypes;
    ways[0] = 1;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int type; cin >> type;
        changeTypes.push_back(type);
    }

    for (int c = 0; c < (int)changeTypes.size(); ++c)
    {
        for (int i = changeTypes[c]; i < 251; ++i)
        {
            ways[i] += ways[i - changeTypes[c]];
        }
    }

    cout << ways[n];
}