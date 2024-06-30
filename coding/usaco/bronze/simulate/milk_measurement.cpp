#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    int max = 7; string cham = "";
    map<int, pair<string, int>> measure;
    for(int i = 0; i < n; i++)
    {
        int day; cin >> day;
        string name; cin >> name;
        int gallons; cin >> gallons;

        measure[day] = {name, gallons};
    }
    int ans = 0;
    map<string, int> cow;
    for(auto it = measure.begin(); it != measure.end(); it++)
    {
        if(!cow.count(it->second.first))
            cow[it->second.first] = 7 + it->second.second;
        else
            cow[it->second.first] += it->second.second;
        
        if(cow[it->second.first] > max && it->second.first != cham)
        {
            max = it->second.second;
            cham = it->second.first;
            ans++;
        }
    }
    cout << ans;
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