#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ways(201, INF);
    int n; cin >> n;
    int tmp = 0;
    ways[0] = n;
    for(int i = 1; i <= n; i++)
    {
        int tmp_w; cin >> tmp_w;
        tmp += tmp_w;
        ways[tmp] = n - i;
    }

    vector<int> types = {1, 2, 5, 10, 15, 20};
    int w; cin >> w;
    for (int c = 0; c < 6; ++c)
    {
        for (int i = types[c]; i <= w; ++i)
        {
            ways[i] = min(ways[i], ways[i - types[c]] + 1);
        }
    }

    cout << ways[w];

    return 0;
}