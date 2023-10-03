#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	int N; cin >> N;
	vector<ll> A(N);
	int min = 0, max = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		if(A[i] > A[max]) max = i;
		else if(A[i] < A[min]) min = i;
	}
	cout << min + 1 << ' ' << max + 1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T = 1;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	return 0;	
}

