#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

pair<char, char> couple(char a, char b)
{
	if (a > b)
		return make_pair(b, a);
	else return make_pair(a, b);
}

void solve()
{
	vector<vector<char>> s(3, vector<char>(3));
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> s[i][j];

	set<char> single;
	set<pair<char, char>> team;
	
	for(int i = 0; i < 3; i++)
	{ 
		
		if(s[i][0] == s[i][1] && s[i][1] == s[i][2]) single.insert(s[i][0]);
		else if (s[i][0] == s[i][1]) team.insert(couple(s[i][0], s[i][2]));
		else if (s[i][0] == s[i][2]) team.insert(couple(s[i][0], s[i][1]));
		else if (s[i][1] == s[i][2]) team.insert(couple(s[i][0], s[i][1]));
	}
	for(int i = 0; i < 3; i++)
	{ 
		if(s[0][i] == s[1][i] && s[1][i] == s[2][i]) single.insert(s[0][i]);
		else if (s[0][i] == s[1][i]) team.insert(couple(s[0][i], s[2][i]));
		else if (s[0][i] == s[2][i]) team.insert(couple(s[0][i], s[1][i]));
		else if (s[1][i] == s[2][i]) team.insert(couple(s[0][i], s[1][i]));
	}
	if(s[0][0] == s[1][1] && s[1][1] == s[2][2]) single.insert(s[0][0]);
	else if (s[0][0] == s[1][1]) team.insert(couple(s[0][0], s[2][2]));
	else if (s[0][0] == s[2][2]) team.insert(couple(s[0][0], s[1][1]));
	else if (s[1][1] == s[2][2]) team.insert(couple(s[0][0], s[1][1]));

	if(s[0][2] == s[1][1] && s[1][1] == s[2][0]) single.insert(s[0][2]);
	else if (s[0][2] == s[1][1]) team.insert(couple(s[0][2], s[2][0]));
	else if (s[1][1] == s[2][0]) team.insert(couple(s[0][2], s[1][1]));
	else if (s[0][2] == s[2][0]) team.insert(couple(s[0][2], s[1][1]));

	cout << single.size() << "\n" << team.size();
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
