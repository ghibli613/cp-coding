#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> b(n);
	vector<tuple<int, int, int>> l;
	for(int i = 0; i < n; i++)
   	{
		int s, t; cin >> s >> t;
		l.push_back(make_tuple(s, 0, i));
		l.push_back(make_tuple(t, 1, i));
		cin >> b[i];
	}
	int maximum = 0, tmp = 0;
	sort(l.begin(), l.end());
	
	for(int i = 0; i < 2 * n; i++)
	{
		if(!get<1>(l[i]))
		{
			tmp += b[get<2>(l[i])];
			ckmax(maximum, tmp);
		}
		else
		{
			tmp -= b[get<2>(l[i])];
		}
	}
	cout << maximum;
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
