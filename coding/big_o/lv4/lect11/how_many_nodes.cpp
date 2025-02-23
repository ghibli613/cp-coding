#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int N = 100007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> cat(20, 0);
    cat[0] = 1;

    for(int i = 0; i < 19; i++) cat[i + 1] = cat[i] * (4 * i + 2) / (i + 2);

    ll n;
    while(cin >> n)
    {
        for(int i = 1; i < 20; i++)
        {
            if(cat[i] == n)
            {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}