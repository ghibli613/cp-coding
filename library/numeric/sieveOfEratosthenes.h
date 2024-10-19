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