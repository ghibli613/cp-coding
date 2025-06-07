#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> remain;
    int ciel = 0, jiro = 0;
    for (int i = 0; i < n; i++)
    {
        int s, c;
        cin >> s;
        for (int i = 1; i <= s / 2; i++)
        {
            cin >> c;
            ciel += c;
        }
        if (s % 2)
        {
            cin >> c;
            remain.push_back(-c);
        }
        for (int i = 1; i <= s / 2; i++)
        {
            cin >> c;
            jiro += c;
        }
    }
    sort(remain.begin(), remain.end());
    for (int i = 0; i < remain.size(); i++)
    {
        if (i % 2 == 0)
        {
            ciel -= remain[i];
        }
        else
        {
            jiro -= remain[i];
        }
    }
    cout << ciel << ' ' << jiro << '\n';
}