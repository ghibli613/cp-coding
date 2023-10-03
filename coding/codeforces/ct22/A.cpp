#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	set<int> my_set;
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp; 
		my_set.insert(tmp);
	}
	if(my_set.size() == 1) cout << "NO";
	else 
	{
		set<int>::iterator it = my_set.begin();
		it++; 
		cout << *it;
	}
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
