#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	int N; cin >> N;
	string s; cin >> s;
	char front = s[0];
	int count = 0;
	int i = 0;
	while(true)
	{
		if(N < 2) break;
		else if(front == ')')
		{
			int j;
			for(j = 1; j < N; j++)
			{
				if(s[j+i] == ')')
					break;
			}
			if(s[i+j] != ')') break;
			i = i + j + 1;
			count++;
			N = N - j -1;
			front = s[i];			
		}
		else
		{
			count++;
			N = N - 2;
			i = i + 2;
			front = s[i];
		}
	}
	cout << count << " " << N << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	return 0;	
}
