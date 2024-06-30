#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

string ans1(int num)
{
	if(num == 0) return "S";
	else if(num == 1) return "M";
	else if(num == 2) return "L";
	else if(num == 3) return "XL";
	else if(num == 4) return "XXL";
	else return "";
}

int ans2(string size)
{
	if(size == "S") return 0;
	else if(size == "M") return 1;
	else if(size == "L") return 2;
	else if(size == "XL") return 3;
	else if(size == "XXL") return 4;
	else return -1;
}

void solve()
{
	vector<int> a(5);
	for(int i = 0; i < 5; i++) cin >> a[i];
	int k; cin >> k;
	for(int i = 0; i < k; i++)
	{
		string size; cin >> size;
		int j = ans2(size), t = 0;
		bool valid = true;
		while(valid)
		{
			if(j+t < 5 && a[j+t] > 0)
			{
				valid = false;
				cout << ans1(j+t) << "\n";
				a[j+t]--;
			}
			else if(j-t > -1 && a[j-t] > 0)
			{
				valid = false;
				cout << ans1(j-t) << "\n";
				a[j-t]--;
			}
			t++;
		}
	}
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
