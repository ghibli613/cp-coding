#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int numCoins = 11;
vector<int> coins = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

const int SIZE = 30005;
long long possible[SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    possible[0] = 1;
    
    for (int c = 0; c < numCoins; ++c)
    {
        for (int i = coins[c]; i <= SIZE; ++i)
        {
            possible[i] += possible[i - coins[c]];      
        }
    }
    
    double num;
    
    while (cin >> num)
    {
        if(num < 0.0000001) break;
        printf("%6.2f%17lld\n", num, possible[static_cast<int>(num * 100 + 0.5)]);
    }

    return 0;
}