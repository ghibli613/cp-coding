#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int m, n; cin >> m >> n;
	int t_m = m, t_n = n;
	if(m >= n)
		m /= 2;
	else
		n /= 2;
	
	cout << m * n + (t_n * t_m - m * n * 2) / 2;
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
