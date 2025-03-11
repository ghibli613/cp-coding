#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int f[5][5][5][5][5][5];

int &getDp(vector<int> &v)
{
    return f[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]];
}

int getSum(vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
        sum += (i + 1) * v[i];
    return sum;
}

int cal(vector<int> v)
{
    if (getDp(v) != -1)
        return getDp(v);

    int sum = getSum(v);
    vector<int> newV = v;
    for (int i = 0; i < 6; i++)
        if (v[i] < 4)
        {
            if (sum + (i + 1) > 31)
                break;
            newV[i]++;
            if (cal(newV) == 0)
                return getDp(v) = 1;
            newV[i]--;
        }

    return getDp(v) = 0;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(f, -1, sizeof f);

    string s;
    while (getline(cin, s))
    {
        vector<int> v(6, 0);
        for (char c : s)
            v[c - '1']++;
        int nextPlayer = s.size() % 2;
        char winner = 'A';
        if (cal(v) == 1)
            winner += nextPlayer;
        else
            winner += 1 - nextPlayer;
        cout << s << ' ' << winner << '\n';
    }

    return 0;
}