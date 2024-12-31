#include <bits/stdc++.h>

using namespace std;

const int M = (int)(2 * 1e9);
const int SQRT_M = 44722; // = sqrt(M)
const int SQRT2_M = 212;  // = sqrt(sqrt(M))
bool isPrime[SQRT_M];
vector<int> primes; // store primes < SQRT_M

// max prime gap <= 2 * 1e9: 292 (following 1453168141)

void sieve()
{
    fill(isPrime, isPrime + SQRT_M, true);

    for (int i = 2; i < SQRT2_M; i++)
    {
        if (!isPrime[i])
            continue;
        int j = i * 2;
        while (j < SQRT_M)
        {
            isPrime[j] = false;
            j += i;
        }
    }

    for (int i = 2; i < SQRT_M; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

bool isAnswer(int x)
{
    if (x < SQRT_M && isPrime[x])
        return true;

    bool xIsPrime = true;

    int smallestPrimeFactorIndex = 0;

    for (int i = 0; i < (int)primes.size(); i++)
    {
        if (x % primes[i] == 0)
        {
            xIsPrime = false;
            smallestPrimeFactorIndex = i;
            break;
        }
    }

    if (xIsPrime)
        return true;

    for (int i = smallestPrimeFactorIndex; i < (int)primes.size(); i++)
    {
        if (x % primes[i] == 0)
        {
            x /= primes[i];
            if (x % primes[i] == 0)
            {
                return false;
            }
        }

        if (x < SQRT_M && isPrime[x])
            break;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    sieve(); // O( SQRT(M) * log(log(SQRT(M))) )

    int m;
    cin >> m;

    while (!isAnswer(m))
    { // O(G*P): G = max prime gap, P = number of prime numbers <= SQRT_M
        m--;
    }

    cout << m << '\n';

    return 0;
}