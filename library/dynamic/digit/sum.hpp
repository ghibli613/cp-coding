ll f[20][2][200];

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

ll dp(vector<int> digits, int sum)
{
    for(int i = 0; i <= digits[0] && i <= sum; i++)
        f[0][i == digits[0]][sum - i] = 1;

    int n = digits.size();
    for(int id = 0; id < n; id++)
        for(int tight = 0; tight < 2; tight++)
            for(int remain = 0; remain <= sum; remain++)
            {
                if(f[id][tight][remain] == 0) continue;
                int limit = tight ? digits[id + 1] : 9;
                for(int d = 0; d <= limit; d++)
                {
                    if(d > remain) break;
                    f[id + 1][tight && d == limit][remain - d] += f[id][tight][remain];
                }
            }
    return f[n - 1][0][0] + f[n - 1][1][0];
}

ll sumRange(ll a, ll b, int k)
{
    vector<int> digits;
    toList(b, digits);
    reverse(digits.begin(), digits.end());
    memset(f, 0, sizeof(f));
    ll res = dp(digits, k);
    
    if(a > 0)
    {
        toList(a - 1, digits);
        reverse(digits.begin(), digits.end());
        memset(f, 0, sizeof(f));
        res -= dp(digits, k);
    }

    return res;
}

void test()
{
    ll a, b, k;
    cin >> a >> b >> k;
    cout << sumRange(a, b, k) << "\n";
}

