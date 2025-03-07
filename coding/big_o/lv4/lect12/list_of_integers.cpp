#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 7;

int minPrime[N];
vector<int> a;
int x, p, k;

void Eratos()
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (minPrime[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (minPrime[j] == 0)
                {
                    minPrime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        if (minPrime[i] == 0)
        {
            minPrime[i] = i;
        }
    }
}

void factorize(int n)
{
    vector<int> P;
    while (n != 1)
    {
        if (P.empty() || minPrime[n] != P.back())
            P.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    n = P.size();
    a.clear();
    for (int i = 0; i < (1 << n); i++)
    {
        ll s = 1;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                s *= P[j];
                cnt++;
            }
        }
        cnt = pow(-1, cnt % 2);
        a.push_back(cnt * s);
    }
}

ll F(ll M)
{
    ll res = 0;
    for (auto e : a)
    {
        res += M / e;
    }
    return res;
}

ll binarySearch(ll left, ll right)
{
    ll res = right;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (F(mid) - F(x) >= k)
        {
            res = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Eratos();
    
    int T;
    cin >> T;
    while (T--)
    {
        cin >> x >> p >> k;
        factorize(p);
        cout << binarySearch(x + 1, 1e12) << endl;
    }
}