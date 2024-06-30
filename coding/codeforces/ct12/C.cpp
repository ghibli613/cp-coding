#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	map<string, int> my_map;
	for(int i = 0; i < m; i++)
	{
		string tmp; cin >> tmp;
		if(my_map.find(tmp) == my_map.end())
			my_map[tmp] = 1;
		else my_map[tmp]++;
	}
	vector<int> cnt;
	for(map<string, int>::iterator i = my_map.begin(); i != my_map.end(); i++)
		cnt.push_back(i->second);
	sort(a.begin(), a.end());
	sort(cnt.begin(), cnt.end());
	int ans_min = 0, ans_max = 0;
	for(int i = 0; i < int(cnt.size()); i++)
		ans_min += cnt[int(cnt.size())-1-i] * a[i];
	for(int i = 0; i < int(cnt.size()); i++)
		ans_max += cnt[i] * a[int(a.size()) - int(cnt.size()) + i];

	cout << ans_min << "\n" << ans_max;
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
