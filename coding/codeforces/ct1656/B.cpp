#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	int N; ll k; cin >> N >> k;
	vector<ll> A(N);
	unordered_set<int> s;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i]; s.insert(A[i]);
	}
	bool check = false;;
	
    for (int i = 0; i < N; i++)
    {
        ll temp = k + A[i];
 		if(s.find(temp) != s.end())
		{
			check = true;
			break;
		}
    }	
	if(check == true) cout << "YES\n";
	else cout << "NO\n";
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

