#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const char nl = '\n';
const double PI = 3.14159265358979323846;

void solve()
{
	string s; cin >> s;
	int n = sz(s);
	set<int> char_set;
	queue<int> char_queue;
	bool flag = false;
	for(int i = 0; i < n; i++)
		if(char_set.find(s[i]) == char_set.end() && flag == false)
		{
			char_set.insert(s[i]);
			char_queue.push(s[i]);
		}
		else
		{
			flag = true;
			if(s[i] != char_queue.front())
			{
				cout << "NO" << nl;
				return;
			}
			else
			{
				char_queue.pop();
				char_queue.push(s[i]);
			}
		}
	cout << "YES" << nl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	while(t--)	
		solve();
	
	return 0;	
}
