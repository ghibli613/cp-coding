#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

ll find_G(int N)
{
    ll G = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            G += __gcd(i, j);
        }
    }

    return G;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n)
    {
        cout << find_G(n) << '\n';
        cin >> n;
    }

    return 0;
}