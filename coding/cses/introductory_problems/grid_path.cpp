#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int p[48];
bool onPath[9][9]{false};

int tryPath(int pathIdx, int curR, int curC)
{
	// Optimization 3
	if ((onPath[curR][curC - 1] && onPath[curR][curC + 1]) && (!onPath[curR - 1][curC] && !onPath[curR + 1][curC]))
		return 0;
	if ((onPath[curR - 1][curC] && onPath[curR + 1][curC]) && (!onPath[curR][curC - 1] && !onPath[curR][curC + 1]))
		return 0;

	if (curR == 7 && curC == 1) 
	{  // reached endpoint before visiting all
		if (pathIdx == 48) return 1;
		return 0;
	}

	if (pathIdx == 48) return 0;

	int ret = 0;
	onPath[curR][curC] = true;

	// turn already determined:
	if (p[pathIdx] < 4) {
		int nxtR = curR + dr[p[pathIdx]];
		int nxtC = curC + dc[p[pathIdx]];
		if (!onPath[nxtR][nxtC]) ret += tryPath(pathIdx + 1, nxtR, nxtC);
	}
	// see Java solution for optimization 4 implementation
	else {  // iterate through all four possible turns
		for (int i = 0; i < 4; i++) {
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (onPath[nxtR][nxtC]) continue;
			ret += tryPath(pathIdx + 1, nxtR, nxtC);
		}
	}
	// reset and return
	onPath[curR][curC] = false;
	return ret;
}

int main()
{
	string line; cin >> line;
	for (int i = 0; i < 48; i++) 
	{
		char cur = line[i];

		if (cur == 'U') p[i] = 0;
		else if (cur == 'R') p[i] = 1;
		else if (cur == 'D') p[i] = 2;
		else if (cur == 'L') p[i] = 3;
		else p[i] = 4;  // cur == '?'
	}

	for (int i = 0; i < 9; i++) 
	{
		onPath[0][i] = true;
		onPath[8][i] = true;
		onPath[i][0] = true;
		onPath[i][8] = true;
	}
	
	int startIdx = 0;
	int startR = 1;
	int startC = 1;  // always start path at (1, 1)
	int ans = tryPath(startIdx, startR, startC);
	cout << ans << endl;
	return 0;
}

// This code is suggested by Kartik Sapra
