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
	if(n > 19)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;	
		for(int i = 1; i <= n; ++i)
		{
			ll tmp = pow(3,i-1);
			cout << tmp << " ";
		}	
		cout << endl;
	}

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

