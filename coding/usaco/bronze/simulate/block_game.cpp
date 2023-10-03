#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	int ans[26] {0};
	for(int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		int tmp[26] {0};
		for(int j = 0; j < int(a.size()); j++)
			tmp[a[j] - 97]++;
		int tmp_1[26] {0};
		for(int j = 0; j < int(b.size()); j++)
			tmp_1[b[j]-97]++;
		for(int j = 0; j < 26; j++) 
		{
			ckmax(tmp[j], tmp_1[j]);
			ans[j] += tmp[j];
		}
	}	
	for(int i = 0; i < 26; i++)
		cout << ans[i] << "\n";
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
