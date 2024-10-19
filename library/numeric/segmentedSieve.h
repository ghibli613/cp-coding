void segmentedSieve(int l, int r, const vector<int>& basePrimes)
{
    isPrime.assign(r - l + 1, true);
    for(int p : basePrimes)
    {
        int fr = ((l - 1) / p + 1) * p;
        for(int j = fr; j <= r; j += p) 
            isPrime[j - l] = false;
    }

    for(int i = l; i <= r; i++)
        if(isPrime[i - l]) primes.push_back(i);
}