#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0; }

void solve()
{
	string s; cin >> s;
	ll leng = s.length();
	bool valid = true;
	while (valid)
	{
		for (int i =1 ; i < leng; i++)
		{
			if(s[0] == s[i])
			{
				s.erase(0,1);
				break;
			}
		}
		ll tmp = s.length();
		if(tmp == leng)
			valid = false;
		else leng = tmp;
	}	
	cout << s << '\n';
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

