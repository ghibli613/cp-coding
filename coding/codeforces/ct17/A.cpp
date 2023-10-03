#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, k; cin >> n >> k;
	vector<bool> prime(n+1, true);
	set<int> my_set;
	for(int p = 2; p * p < n; p++)
		if(prime[p] == true)
			for(int i = p * p; i <= n; i += p)
				prime[i] = false;
	for(int p = 2; p <= n; p++)
		if(prime[p])
			my_set.insert(p);
	
	set<int>::iterator it = my_set.begin();
	int a = *it, ans = 0;
	it++;
	int b = a;
	for(; it != my_set.end(); it++)
	{
		b = *it;
		int check = a + b +1;
		if(my_set.find(check) != my_set.end())
			ans++;
		a = b;
	}
	if(ans >= k) cout << "YES";
	else cout << "NO";
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
