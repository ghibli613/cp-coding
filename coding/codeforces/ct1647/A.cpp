#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#define ll long long
#define ull unsigned long long

void solve()
{
	int N;
	cin >> N;
	
	int num_1 = 0, num_2 = 0;
	int n = 1, m = 0;

	while (true)
	{
		if(n*2 + m*1 == N)
		{
			num_2 = n; num_1 = m;
			break;
		}
		if(n*1 + m*2 == N)
		{
			num_1 = n; num_2 = m;
			break;
		}

		m++;
		if(n*1 + m*2 == N)
		{
			num_1 = n; num_2 = m;
			break;
		}
		n++;
	}

	ull res = 0;
	int num = num_1 + num_2;
	ull k;
	if(num_1 > num_2)
		while(true)
		{
			cout << 1; num--;
			if(num == 0) break;
			cout << 2; num--;
		}
	else if (num_1 < num_2)
		while(true)
		{
			cout << 2; num--;
			if(num == 0) break;
			cout << 1; num--;
		}
	else
		while(true)
		{
			cout << 2; num--;
			cout << 1; num--;
			if(num == 0) break;
		}
	cout << endl;
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