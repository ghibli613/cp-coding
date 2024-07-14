#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(401, vector<int>(401));
    vector<vector<int>> c(4, vector<int>(4));

    for(int i = 0; i< n; i++)
    {
        int x, y, color;
        cin >> x >> y >> color;
        a[x + 200][y + 200] = color;
    }

    int res = 0;
    for (int x1 = 0; x1 <= 400; x1++) 
    {
		for (int x2 = x1 + 1; x2 <= 400; x2++) 
        {
			for (int c1 = 0; c1 < 4; c1++) 
            {
				for (int c2 = 0; c2 < 4; c2++) 
                {
					c[c1][c2] = 0;
				}
			}

            for (int y = 0; y <= 400; y++) 
            {
				if (a[x1][y] != 0 && a[x2][y] != 0) 
                {
					c[a[x1][y] - 1][a[x2][y] - 1]++;
					c[a[x2][y] - 1][a[x1][y] - 1]++;
				}
			}

            for (int c1 = 0; c1 < 4; c1++) 
            {
				for (int c2 = c1 + 1; c2 < 4; c2++) 
                {
					int c3 = -1;
					int c4 = -1; 
					for (int i = 0; i < 4; i++) 
                    {
						if (i != c1 && i != c2) 
                        {
							if (c3 == -1) {
								c3 = i;
							}
							else {
								c4 = i; 
							}
						}
					}
					res += c[c1][c2] * c[c3][c4]; 
				}
			}
        }
    }

    cout << res / 2;
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