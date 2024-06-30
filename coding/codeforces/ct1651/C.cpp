#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0; }

void solve()
{
	int N; cin >> N;
	vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
	vector<ll> B(N); for(int i = 0; i < N; i++) cin >> B[i];
	ll ans = min(abs(A[0] - B[0]) + abs(A[N-1] - B[N-1]), abs(A[0] - B[N-1]) + abs(A[N-1] - B[0]));

	ll cost[4]; for(int i = 0; i < 4; i++) cost[i] = 1e12;
	for(int i = 0; i < N; i++)
	{
		ckmin(cost[0], abs(A[0] - B[i]));
		ckmin(cost[1], abs(A[N-1] - B[i]));
		ckmin(cost[2], abs(A[i] - B[0]));
		ckmin(cost[3], abs(A[i] - B[N-1]));
	}
	ckmin(ans, abs(A[0] - B[0]) + cost[1] + cost[3]);
	ckmin(ans, abs(A[0] - B[N-1]) + cost[1] + cost[2]);
	ckmin(ans, abs(A[N-1] - B[0]) + cost[0] + cost[3]);
	ckmin(ans, abs(A[N-1] - B[N-1]) + cost[0] + cost[2]);

	ckmin(ans, cost[0] + cost[1] + cost[2] + cost[3]);
	cout << ans << '\n';

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
