vector<ll> f;

void computeFactorials(int n, int mod)
{
    f.assign(n + 1, 0);
    f[0] = 1;
    for(int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * i) % mod;
}

ll fastPow(ll b, int p, int mod)
{
    if(!b) return 0;
    if(!p) return 1;
    ll res = fastPow(b, p / 2, mod);
    res = (res * res) % mod;
    if(p & 1)
        res = (res * b) % mod;
    return res;
}

ll nCkInverseModulo(int n, int k, int mod)
{
    ll res = f[n];
    res = (res * fastPow(f[k], mod - 2, mod)) % mod;
    res = (res * fastPow(f[n - k], mod - 2, mod)) % mod;
    return res;
}

vector<int> getPresentation(int num, int base)
{
    vector<int> p;
    while(num > 0)
    {
        p.push_back(num % base);
        num /= base;
    }
    return p;
}

ll nCkLucas(int n, int k, int mod)
{
    vector<int> pN = getPresentation(n, mod);
    vector<int> pK = getPresentation(k, mod);
    ll res = 1;

    for(int i = 0; i < (int)pK.size(); i++)
        res = (res * nCkInverseModulo(pN[i], pK[i], mod)) % mod;
    return res;
}

void test()
{
    int n = 18, k = 7, mod = 5;

    computeFactorials(n, mod);

    cout << "nCk using inverse modulo: " << nCkInverseModulo(n, k, mod) << "\n";
    cout << "nCk using Lucas's theorem: " << nCkInverseModulo(n, k, mod) << "\n";
}