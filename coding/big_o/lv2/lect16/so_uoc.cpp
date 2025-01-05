#include <bits/stdc++.h>

using namespace std;

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

int maxPower(int p, int n)
{
    int ans = 0;
    int q = p;
    while (n / q > 0)
    {
        ans += n / q;
        q *= p;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    long long res = 1;
    for (auto &p : primes)
    {
        if (maxPower(p, n) != 0)
            res *= maxPower(p, n) + 1;
    }
    cout << res - 1 << endl;
    return 0;
}

// https://mathschallenge.net/library/number/number_of_divisors
// https://en.wikipedia.org/wiki/Legendre%27s_formula