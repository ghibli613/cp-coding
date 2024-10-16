#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int pow10(int k)
{
    int result = 1;
    while(k--)
    {
        result *= 10;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n, t;
    cin >> n >> t;

    int k = t.size();
    int N = stoi(n);
    int T = stoi(t);

    int v = pow10(k);
    int s = N * v + T;

    int tmp = __gcd(v, s);
    v = v / tmp;
    s = s / tmp;
    cout << s << ' ' << v;

    return 0;
}