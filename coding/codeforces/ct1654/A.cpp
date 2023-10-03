#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0; }

void solve()
{
	int N; cin >> N;
	vector<ll> A(N+1,0);
	ll max1 = 0, max2 = 0, tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (A[i] > A[max1])
		{
			max1 = i;
			max2 = tmp;
			tmp = max1;
			continue;
		}
		if (A[i] > A[max2]) max2 = i;
	}
	ll res = A[max1] + A[max2];
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	return 0;	
}

