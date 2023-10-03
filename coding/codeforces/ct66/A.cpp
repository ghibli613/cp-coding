#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
	vector<int> a(n);
    for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int tmp = 1, j = i;
		while(j > 0)
		{
			if(a[j] >= a[j-1]) tmp++;
			else break;
			j--;
		}
		j = i;
		while(j < n-1)
		{
			if(a[j] >= a[j+1]) tmp++;
			else break;
			j++;
		}
		if(tmp > ans) ans = tmp;
	}
	cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t--)
        solve();

    return 0;
}
