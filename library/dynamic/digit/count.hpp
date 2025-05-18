ll f[20][10][2][2];

void toList(ll n, vector<int> &digits)
{
    digits.clear();
    while(n)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    if((int)digits.size() == 0) digits.push_back(0);
}

ll dp(vector<int> digits)
{
    int n = digits.size();
    for(int i = 0; i <= digits[0]; i++)
        f[0][i][i == digits[0]][i == 0] = 1;

    for(int id = 0; id < n - 1; id++)
        for(int prev = 0; prev < 10; prev++)
            for(int tight = 0; tight < 2; tight++)
                for(int zero = 0; zero < 2; zero++)
                {
                    if(f[id][prev][tight][zero] == 0) continue;
                    for(int next = 0; next < 10; next++)
                    {
                        if(tight && next > digit[i + 1]) continue;
                        if(next == prev && zero) continue;
                        int newTight = tight && next == digits[i + 1];
                        int newZero = zero && next == 0;
                        f[id + 1][next][newTight][newZero] += f[id][prev][tight][remain];
                    }
                }
    
    ll res = 0;
    for(int prev = 0; prev < 10; prev++)
        for(int tight = 0; tight < 2; tight++)
            for(int zero = 0; zero < 2; zero++)
                res += f[n - 1][prev][tight][zero];

    return res;
}

ll sumRange(ll a, ll b)
{
    if(b == 0) return 1;

    vector<int> digits;
    toList(b, digits);
    reverse(digits.begin(), digits.end());
    memset(f, 0, sizeof(f));
    ll res = dp(digits);
    
    if(a > 0)
    {
        toList(a - 1, digits);
        reverse(digits.begin(), digits.end());
        memset(f, 0, sizeof(f));
        res -= dp(digits);
    }

    return res;
}

void test()
{
    ll a, b;
    cin >> a >> b;
    cout << sumRange(a, b) << "\n";
}
