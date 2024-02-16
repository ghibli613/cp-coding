#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
};

int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

void solve()
{
    vector<Rect> a(3);
    for(int i = 0; i < 3; i++)
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

    int ans = a[0].area() - intersect(a[0], a[2]);
    ans += a[1].area() - intersect(a[1], a[2]);
    cout << ans << '\n';
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
