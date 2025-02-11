int extend_gcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extend_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int modInverse(int b, int m)
{
    int g, x, y;
    g = extend_gcd(b, m, x, y);
    if(g != 1)
        return -1;
    return x;
}

ll chineseRemainder(const vector<int>& a, const vector<int>& m, int mod)
{
    ll result = 0;
    for(int i = 0; i < (int)a.size(); i++)
    {
        int M_i = mod / m[i];
        int y_i = modInverse(M_i, m[i]);
        result = (result + 1LL * a[i] * M_i * y_i) % mod;
    }
    return result;
}