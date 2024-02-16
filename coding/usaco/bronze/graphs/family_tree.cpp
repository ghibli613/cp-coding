#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
	vector<string> cows(2);
	cin >> n >> cows[0] >> cows[1];

	map<string, string> edge;
	for (int i = 0; i < n; ++i) 
    {
		string u, v;
		cin >> v >> u;
		edge[u] = v;
	}

	vector<map<string, int>> ancestors(2);
	for (int c = 0; c < 2; c++) 
    {
		string at = cows[c];
		ancestors[c][cows[c]] = 0;
		while (edge.count(at) != 0) 
        {
			auto n = edge.find(at);
			ancestors[c][n->second] = ancestors[c][at] + 1;
			at = n->second;
		}
	}

    string common = "";
    int dist0 = INT32_MAX, dist1 = INT32_MAX;

    for(const pair<const string, int> &d0: ancestors[0])
    {
        auto d1 = ancestors[1].find(d0.first);
        if(d1 != ancestors[1].end() && (dist0 > d0.second || dist1 > d1->second))
        {
            common = d0.first;
            dist0 = d0.second;
            dist1 = d1->second;
        }
    }

    if(common.empty())
    {
        cout << "NOT RELATED";
    }
    else if(common == cows[1] || common == cows[0])
    {
        if(common == cows[0])
        {
            swap(cows[0], cows[1]);
            swap(dist0, dist1);
        }
        cout << cows[1] << " is the ";
        if(dist0 >= 2)
        {
            for(int i = 0; i < dist0 - 2; i++) cout << "great-";
            cout << "grand-";
        }
        cout << "mother of " << cows[0];
    }
    else
    {
        if(dist1 < dist0)
        {
            swap(dist1, dist0);
            swap(cows[1], cows[0]);
        }
        if(dist0 == 1)
        {
            if(dist1 == 1)
            {
                cout << "SIBLINGS";
            }
            else
            {
                cout << cows[0] << " is the ";
                for(int i = 0; i < dist1 - 2; i++)
                    cout << "great-";
                cout << "aunt of " << cows[1];
            } 
        }
        else 
        {
            cout << "COUSINS";
        }
    }
    cout << endl;
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
