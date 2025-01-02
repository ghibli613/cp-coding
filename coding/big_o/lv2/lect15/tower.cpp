#include <bits/stdc++.h>
using namespace std;

int a, b;
bool sieve[1000010];
bool disk[1000010];
vector<int> weight;

void sieveErat(int n)
{
    memset(sieve, true, sizeof(bool) * (n + 1));
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (sieve[i])
            for (int j = i * 2; j <= n; j += i)
                sieve[j] = false;
}

int main()
{
    cin >> a >> b;
    if (a < 0 || b < 0)
    {
        cout << -1;
        exit(0);
    }
    if (b % a != 0)
    {
        cout << -1;
        exit(0);
    }

    memset(disk, false, sizeof(bool) * (b + 1));

    for (int i = a; i <= b; i++)
        if (i % a == 0 && b % i == 0)
            disk[i] = true;

    sieveErat(b / a);

    int sum = a;
    int count = 1;
    int x = a;
    while (x < b)
    {
        for (int i = 2; i <= b / a; i++)
            if (sieve[i] && disk[i * x])
            {
                x = x * i;
                sum += x;
                count++;
                break;
            }
    }
    cout << count << " " << sum;
    return 0;
}