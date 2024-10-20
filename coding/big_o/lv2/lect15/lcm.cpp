#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

vector<bool> isPrime;
vector<int> primes;

void sieveOfEratosthenes(int n)
{
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; i++)
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }

    for(int i = 2; i<= n; i++)
        if(isPrime[i]) primes.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    sieveOfEratosthenes(n);

    ll res = 1;
    for(int i = 0; i < (int)primes.size(); i++)
    {
        ll x = n;
        while(x >= primes[i])
        {
            x /= primes[i];
            res = (res * primes[i]) % MOD;
            // cout << res << ' ';
        }
        // cout << '\n';
        // cout << primes[i] << ' ';
    }
    cout << res;

    return 0;
}