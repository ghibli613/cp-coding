#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	vector<int> c(3), m(3);
	for(int i = 0; i < 3; i++) cin >> c[i] >> m[i];

	for(int i = 0; i < 100; i++)
	{
		if(m[i % 3] + m[(i + 1) % 3] <= c[(i + 1) % 3])
		{
			m[(i + 1) % 3] += m[i % 3];
			m[i % 3] = 0;
		}
		else
		{
			m[i % 3] += m[(i + 1) % 3] - c[(i + 1) % 3];
			m[(i + 1) % 3] = c[(i + 1) % 3];
		}
	}
	
	cout << m[0] << '\n' << m[1] << '\n' << m[2];
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
