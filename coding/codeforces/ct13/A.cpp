#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	int x = 0, y = 0;;
	for(int i = 2; i < n; i++)
	{
		y++;
		int tmp = n;
		while(tmp)
		{
			x += tmp % i;
			tmp /= i;
		}
	}
	int div = gcd(x, y);
	cout << x / div << "/" << y / div;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
