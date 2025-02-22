#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    while (cin >> n >> m)
    {
        vector<ll> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];

        // now find how many numbers are divisible by any number from array of m
        int set_sz = (1 << m);                                      // 2^m is the number of sets
        ll multiples_of_anyone_of_array = 0;
        for (int mask = 1; mask < set_sz; mask++)
        {
            ll Lcm = 1ll;
            int bits = 0;
            for (int i = 0; i < m; i++)
            {
                if (((1 << i) & mask))                              // ith element is here
                {
                    bits++;                                         // how many elements we choose
                    Lcm = Lcm * arr[i] / __gcd(Lcm, arr[i]);        // lcm of all elements of this set
                }
            }
            ll num_till_n = n / Lcm;                                // how many multiples of multiple within n ?
            if (bits & 1)                                           // inclusion, number of elements are odd
                multiples_of_anyone_of_array += num_till_n;
            else                                                    // exclusion ,number of elements are even
                multiples_of_anyone_of_array -= num_till_n;
        }
        ll ans = n - multiples_of_anyone_of_array;
        cout << ans << '\n';
    }

    return 0;
}