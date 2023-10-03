#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	map<int, int> my_map;
	my_map[1] = 0;
	my_map[2] = 0;
	my_map[3] = 0;
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		my_map[tmp]++;
	}
	int max = -1;
	if(max < my_map[1]) max = my_map[1];
	if(max < my_map[2]) max = my_map[2];
	if(max < my_map[3]) max = my_map[3];
	cout << n - max;
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
