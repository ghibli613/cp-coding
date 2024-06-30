#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int> possible;

void get_possible(int day, int a_tank, vector<int> a_buckets, int b_tank, vector<int> b_buckets)
{
	if(day == 4)
	{
		possible.insert(a_tank);
		return;
	}

	for(int i = 0; i < (int)a_buckets.size(); i++)
	{
		int t = a_buckets[i];
		vector<int> new_a = a_buckets;
		new_a.erase(begin(new_a) + i);
		vector<int> new_b = b_buckets;
		new_b.push_back(t);
		get_possible(day + 1, b_tank + t, new_b, a_tank - t, new_a);
	}
}

void solve()
{
    vector<int> f(10), s(10);
    for(int i = 0; i < 10; i++) cin >> f[i];
    for(int i = 0; i < 10; i++) cin >> s[i];
    get_possible(0, 1000, f, 1000, s);
	cout << (int)possible.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}