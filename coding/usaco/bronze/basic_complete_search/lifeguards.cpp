#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<int,int>> lifeguards(n);
	int max_time = 0;  // Max time we'll have to process up to
	for (int i = 0; i < n; i++) {
		cin >> lifeguards[i].first >> lifeguards[i].second;
		max_time = max(max_time, lifeguards[i].second);
	}

	/*
	 * Simulate firing each lifeguard and compute the total
	 * time covered by the remaining lifeguards
	 */
	int max_cover = 0;
	for (int i = 0; i < n; i++) {
		int time_covered = 0;
		// Try to find a cow that can cover this interval
		for (int t = 1; t <= max_time; t++) 
			for (int j = 0; j < n; j++) 
				// Check that it's not the fired cow
				if (j != i) 
					if (lifeguards[j].first <= t && t < lifeguards[j].second) 
                    {
						// One more time slot covered- no need to search further
						time_covered++;
						break;
					}
				
			
		
		max_cover = max(max_cover, time_covered);
	}
    cout << max_cover << endl;
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