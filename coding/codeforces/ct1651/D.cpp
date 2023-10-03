#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) M(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep4(_, x, n, s) for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define rep1(n) rep2(i, n)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const char nl = '\n';
const double PI = 3.14159265358979323846;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve()
{
	int n; cin >> n;
	vpi data_array_point(n);
	set<pi> data_set_point;
	queue<pi> my_queue;
	map<pi, pi> ans;
	rep(i, n)
	{
		pi tmp; cin >> tmp.f >> tmp.s;
		data_array_point[i] = tmp;
		data_set_point.insert(tmp);
	}

	rep(i,n)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(data_set_point.find({data_array_point[i].f + dx[j], data_array_point[i].s + dy[j]}) == data_set_point.end())
			{
				my_queue.push({data_array_point[i].f, data_array_point[i].s});
				ans[data_array_point[i]] = {data_array_point[i].f + dx[j], data_array_point[i].s + dy[j]};
				break;
			}
		}
	}

	while(!my_queue.empty())
	{
		pi tmp = my_queue.front();
		my_queue.pop();
		rep(i, 4)
		{
			if(data_set_point.find({tmp.f + dx[i], tmp.s + dy[i]}) != data_set_point.end() && ans.find({tmp.f + dx[i], tmp.s + dy[i]}) == ans.end())
			{
				ans[{tmp.f + dx[i], tmp.s + dy[i]}] = ans[tmp];
				my_queue.push({tmp.f + dx[i], tmp.s + dy[i]});
			}
		}
	}

	rep(i, n)
	{
		cout << ans[data_array_point[i]].f << " " << ans[data_array_point[i]].s << nl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;

	rep(t)	
		solve();
	
	return 0;	
}