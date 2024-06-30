#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const char nl = '\n';

pair<int, int> count(ll a)
{
	pi res = {0, 0};
	while(a % 2 == 0)
	{
		a /= 2;
		res.first++;
	}
	while(a % 5 == 0)
	{
		a /= 5;
		res.second++;
	}
	return res;
}

void solve()
{
	int n; cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n));
	bool exist_zeros = false;
	int row = 0, col = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
	 	{
	 		cin >> a[i][j];	
	 		if(a[i][j] == 0 && !exist_zeros) 
	 		{
	 			exist_zeros = true;
	 			row = i; col = j;
	 		}
	 		if(a[i][j] == 0) a[i][j] = 10;
	 	}

	vector<vector<pair<pi, string>>> b(n, vector<pair<pi, string>>(n, {{0, 0}, ""}));
	b[0][0] = {count(a[0][0]), ""};

	for(int i = 1; i < n; i++) 
	{
		pi tmp = count(a[0][i]);
		b[0][i].first.first = b[0][i-1].first.first + tmp.first;
		b[0][i].first.second = b[0][i-1].first.second + tmp.second;
		b[0][i].second = b[0][i-1].second + "R";
	}
	for(int i = 1; i < n; i++) 
	{
		pi tmp = count(a[i][0]);
		b[i][0].first.first = b[i-1][0].first.first + tmp.first;
		b[i][0].first.second = b[i-1][0].first.second + tmp.second;
		b[i][0].second = b[i-1][0].second + "D";
	}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < n; j++)
		{

		}
	cout << 1;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;

	while(t--)	
		solve();
	
	return 0;	
}