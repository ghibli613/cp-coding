#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	int min = 0, post = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		min += a[i] * i;
		if(i != 0) post += a[i];
	}	
	int tmp = min;
	for(int i = 1; i < n; i++)
	{
		tmp += a[i - 1] * (n - 1) - post;
		post += a[i - 1] - a[i];
		ckmin(min, tmp);
	}
	cout << min;
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
