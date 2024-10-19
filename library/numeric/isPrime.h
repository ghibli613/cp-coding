bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 0; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}