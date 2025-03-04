void primeFactorization(int n)
{
    cout << n << " = ";
    for(int i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    if(n != 1) cout << n;
}