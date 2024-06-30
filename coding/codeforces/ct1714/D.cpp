#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const double PI = 3.14159265358979323846;

void solve()
{
	string t;
	int n;
	cin >> t >> n;
	vector<string> s(n);
	
	for(int i = 0; i< n; i++) cin >> s[i];

	int l = int(t.size());
	vector<int> dp(l+1, 1e9);
	vector<int> previous(l+1, -1);
	vector<int> previous_which(l+1, -1);
	vector<int> previous_start(l+1, -1);
	dp[0] = 0;

	for(int len = 0; len < l; len++)
		for(int i = 0; i < n; i++)
		{
			int s_len = int(s[i].size());
			
			for(int start = max(len - s_len, 0); start <= min(l - s_len, len); start++)
				if(t.substr(start, s_len) == s[i])
					if(dp[len] + 1 < dp[start + s_len])
					{
						dp[start + s_len] = dp[len] + 1;
						previous[start + s_len] = len;
						previous_which[start + s_len] = i;
						previous_start[start + s_len] = start;
					}
		}

	if(dp[l] >= 1e9)
	{
		cout << -1 << '\n';
		return;
	}

	cout << dp[l] << '\n';
	int end = l;

	while(end > 0)
	{
		int which = previous_which[end];
		int start = previous_start[end];
		cout << which + 1 << ' ' << start + 1 << '\n';
		end = previous[end];
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

	while(t--)
		solve();

	return 0;
}