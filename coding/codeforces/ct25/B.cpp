#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	if(n % 2 == 1)
	{
		char a, b, c; cin >> a >> b >> c;
		cout << a << b << c;
		for(int i = 1; i < n/2; i++)
		{
			cin >> a >> b;
			cout << '-' << a << b;
		}
	}
	else
	{
		char a, b; cin >> a >> b;
		cout << a << b;
		for(int i = 1; i < n/2; i++)
		{
			char a, b;
			cin >> a >> b;
			cout << '-' << a << b;
		}
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
