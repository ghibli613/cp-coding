#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    while (n--)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (pair<int, int> it : cnt)
    {
        if (it.second % 2 == 1)
        {
            cout << "Conan";
            return 0;
        }
    }
    cout << "Agasa";

    return 0;
}