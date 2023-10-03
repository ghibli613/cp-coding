#include<iostream>
#include<string>
#include<cstdio>
#include<math.h>
using namespace std;

#define ll long long

void solve()
{
	int n;
	cin >> n;
	ll d = pow(2,n)-1;	
	cout << d << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	while(N--)
	{
		solve();
	}
	
	return 0;	
}

