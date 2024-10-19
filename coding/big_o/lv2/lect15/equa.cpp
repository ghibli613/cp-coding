#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

    for(int i = 2; i <= n; i++)
        if(isPrime[i])
        { 
            primes.push_back(i);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k; cin >> k;
    sieveOfEratosthenes(k);

    for(int i = 0; i < (int)primes.size(); i++)
    {
        int x = primes[i];
        for(int j = i; j < (int)primes.size(); j++)
        {
            int y = primes[j];
            int z = k - x - y;
            if(z >= y) 
            {
                if(isPrime[z])
                    cout << x << ' ' << y << ' ' << z << '\n';
            }
            else break;
        }
    }
    cout << "0 0 0";

    return 0;
}