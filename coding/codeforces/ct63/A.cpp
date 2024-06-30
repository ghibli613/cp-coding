#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    vector<string> rat, woman_child, man, captain;
    for(int i = 0; i < n; i++)
    {
        string s1, s2; cin >> s1 >> s2;
        if(s2 == "rat") rat.push_back(s1);
        else if(s2 == "man") man.push_back(s1);
        else if(s2 == "captain") captain.push_back(s1);
        else woman_child.push_back(s1);
    }
    for(int i = 0; i < int(rat.size()); i++) cout << rat[i] << '\n';
    for(int i = 0; i < int(woman_child.size()); i++) cout << woman_child[i] << '\n';
    for(int i = 0; i < int(man.size()); i++) cout << man[i] << '\n';
    for(int i = 0; i < int(captain.size()); i++) cout << captain[i] << '\n';

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