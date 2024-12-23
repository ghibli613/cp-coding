#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;

const int N = 1e7 + 7;
const int NP = 664579 + 10;
int minPrime[N + 1];

vector<int> f, p;
int n;

int factorize(int n)
{
    int res = 0;
    while (n != 1)
    {
        res++;
        n /= minPrime[n];
    }
    return res;
}

int getFactors(int n)
{
    int N = n;
    int m = 0;
    if (n % 10 != 0)
        return 0;
    while (n)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }
    if (minPrime[m] != m)
        return 0;
    int ans = factorize(N);
    return ans;
}

void sieveOfEratosthenes()
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

template <class T>
struct FenwickTree
{
    int n;
    vector<T> f;

    FenwickTree(int n_)
    {
        n = n_;
        f.assign(n + 7, 0);
    }

    void update(int u, int v)
    {
        int idx = u;
        while (idx <= n)
        {
            f[idx] += v;
            idx += (idx & (-idx));
        }
    }

    int getSum(int p)
    {
        int idx = p, ans = 0;
        while (idx > 0)
        {
            ans += f[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    int query(int id)
    {

        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieveOfEratosthenes();
    for (int i = 1e6; i < 1e7; i++)
    {
        int nFactors = getFactors(i);
        if (nFactors != 0)
        {
            p.push_back(i);
            f.push_back(nFactors);
        }
    }

    n = f.size();
    FenwickTree<int> ps(n), cnt(n);
    for (int i = 1; i <= (int)f.size(); i++)
    {
        ps.update(i, f[i - 1]);
        cnt.update(i, 1);
    }

    char cmd;
    int val;

    while (cin >> cmd >> val)
    {
        if (cmd == 'q')
        {
            val++;
            int left = 1, right = n;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int tmp = cnt.getSum(mid);
                if (tmp == val)
                {
                    cout << ps.getSum(mid) << '\n';
                    break;
                }
                if (tmp < val)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        else
        {
            int id = lower_bound(p.begin(), p.end(), val) - p.begin();
            id++;
            ps.update(id, -f[id - 1]);
            cnt.update(id, -1);
        }
    }
}