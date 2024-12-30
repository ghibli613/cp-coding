#include <bits/stdc++.h>

using namespace std;

vector<string> M[6];
string cur;

void back_tracking(int i)
{
    if (i > 5)
        return;
    if (i > 0)
        M[cur.size()].push_back(cur);
    char start = i == 0 ? 'a' : cur[i - 1] + 1;
    for (char c = start; c <= 'z'; c++)
    {
        cur.push_back(c);
        back_tracking(i + 1);
        cur.pop_back();
    }
}
int main()
{
    back_tracking(0);
    map<string, int> word;
    int counter = 0;
    for (int i = 1; i <= 5; i++)
    {
        sort(M[i].begin(), M[i].end());
        for (string x : M[i])
            word[x] = ++counter;
    }
    string s;
    while (cin >> s)
        cout << word[s] << endl;
}