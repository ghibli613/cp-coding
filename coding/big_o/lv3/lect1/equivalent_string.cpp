#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string smallest(string s)
{
    if (s.length() % 2 == 1)
        return s;
    string s1 = smallest(s.substr(0, s.length() / 2));
    string s2 = smallest(s.substr(s.length() / 2, s.size()));
    if (s1 < s2)
        return s1 + s2;
    else
        return s2 + s1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    if(smallest(a) == smallest(b)) cout << "YES";
    else cout << "NO";

    return 0;
}