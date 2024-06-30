#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    string s;
    getline(cin, s);
    map<char, int> head;
    for(int i = 0; i < int(s.size()); i++)
        if(s[i] != ' ' && head.find(s[i]) == head.end()) head[s[i]] = 1;
        else if(s[i] != ' ') head[s[i]]++;

    getline(cin, s);
    map<char, int> letter;
    for(int i = 0; i < int(s.size()); i++)
        if(s[i] != ' ' && letter.find(s[i]) == letter.end()) letter[s[i]] = 1;
        else if(s[i] != ' ') letter[s[i]]++;

    for(map<char, int>::iterator it = letter.begin(); it != letter.end(); it++)
    {
        if(head.find(it->first) == head.end() || head[it->first] < it->second)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}