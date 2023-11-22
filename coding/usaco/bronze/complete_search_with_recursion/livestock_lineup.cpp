#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<string, string>> constraint(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> constraint[i].first;
    	string tmp;
    	for(int i = 0; i < 4; i++) cin >> tmp;
    	cin >> constraint[i].second;
    }
    vector<string> cows{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    
    do
    {
    	bool valid = true;
    	for(int j = 0; j < n; j++)
    	{
    		for(int i = 0; i < 8; i++)
    			if(cows[i] == constraint[j].first)
    			{
    				if(cows[i-1] != constraint[j].second && cows[i+1] != constraint[j].second)
    					valid = false;
    				break;
    			}
    		if(!valid) break;
    	}

    	if(valid) 
    	{
    		for(int i = 0; i < 8; i++) cout << cows[i] << "\n";
    		break;
    	}

    		
    } while(next_permutation(cows.begin(), cows.end()));
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