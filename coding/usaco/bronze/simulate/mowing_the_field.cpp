#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    vector<pair<char, int>> steps(n);
    
    for(int i = 0; i < n; i++)
        cin >> steps[i].first >> steps[i].second;

    // FJ's starting position.
    pair<int, int> curr{0, 0};
    // Make a hashmap, and mark off steps.
    // We'll first mark off his starting position.
    map<pair<int, int>, int> visits{{curr, 0}};

    int time = 0;
    int max_regrow = INT32_MAX;
    for (int i = 0; i < n; i++) 
    {
        // Get the direction Farmer John is moving.
        pair<int, int> delta;
        switch (steps[i].first)
        {
            case 'N':
                delta = pair<int, int>{0, 1};
                break;
            case 'W':
                delta = pair<int, int>{-1, 0};
                break;
            case 'E':
                delta = pair<int, int>{1, 0};
                break;
            case 'S':
                delta = pair<int, int>{0, -1};
                break;
        }

        for (int j = 0; j < steps[i].second; j++) 
        {
            // Update our curent position.
            curr = pair<int, int>{curr.first + delta.first,
                                  curr.second + delta.second};
            time++;

            // Check if FJ's been to this patch of grass before.
            if (visits.count(curr)) 
                max_regrow = min(max_regrow, time - visits[curr]);

            // Update the last time FJ has come upon this patch of grass.
            visits[curr] = time;
        }
    }

    cout << (max_regrow == INT32_MAX ? -1 : max_regrow) << endl;
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