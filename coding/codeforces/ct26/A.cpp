#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> prime(n+1, true);
	for (int p = 2; p * p <= n; p++) 
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
	
	set<int> check;	
    for (int p = 2; p <= n; p++)
	{
		if (prime[p])
            check.insert(p);
	}

	int ans = 0;
	for(int i = 0; i <= n; i++)
	{
		int cnt = 0;
		for(int j = 2; j <= sqrt(i); j++)
		{
			if(i % j == 0)
			{
				if(check.find(j) != check.end()) cnt++;
				if(j != i/j && check.find(i/j) != check.end()) cnt++;
			}
		}
		if(cnt == 2) ans++;
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;

	while(t--)	
		solve();
	
	return 0;	
}
