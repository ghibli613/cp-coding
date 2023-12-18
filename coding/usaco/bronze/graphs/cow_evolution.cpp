#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<set<string>> cows;
	set<string> all_char_set;
	for (int c = 0; c < n; c++) {
		int char_num;
		cin >> char_num;
		set<string> curr_cow;
		for (int i = 0; i < char_num; i++) {
			string characteristic;
			cin >> characteristic;
			curr_cow.insert(characteristic);
		}
		all_char_set.insert(curr_cow.begin(), curr_cow.end());
		cows.push_back(curr_cow);
	}

	vector<string> all_chars(all_char_set.begin(), all_char_set.end());

	for (int a = 0; a < (int)all_chars.size() - 1; a++) {
		for (int b = a + 1; b < (int)all_chars.size(); b++) {
			bool both = false, only_a = false, only_b = false;
			for (const set<string> &c : cows) {
				bool has_a = c.count(all_chars[a]);
				bool has_b = c.count(all_chars[b]);

				if (has_a && has_b) {
					both = true;
				} else if (has_a && !has_b) {
					only_a = true;
				} else if (!has_a && has_b) {
					only_b = true;
				}
			}

			if (only_a && only_b && both) {
				cout << "no" << endl;
				return;
			}
		}
	}

	cout << "yes" << endl;
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