#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int convert(string zodiac)
{
    if(zodiac == "Ox") return 0;
    else if(zodiac == "Tiger") return 1;
    else if(zodiac == "Rabbit") return 2;
    else if(zodiac == "Dragon") return 3;
    else if(zodiac == "Snake") return 4;
    else if(zodiac == "Horse") return 5;
    else if(zodiac == "Goat") return 6;
    else if(zodiac == "Monkey") return 7;
    else if(zodiac == "Rooster") return 8;
    else if(zodiac == "Dog") return 9;
    else if(zodiac == "Pig") return 10;
    else return 11;
}

void solve()
{
    int n; cin >> n;
    unordered_map<string, pair<int, int>> m;
    m["Bessie"] = {0, 0};
    for(int i = 0; i < n; i++)
    {
        string s1, s2, s3, s4; cin >> s1;
        for(int j = 0; j < 3; j++) cin >> s2;
        cin >> s3;
        for(int j = 0; j < 3; j++) cin >> s4;
        
        m[s1].first = convert(s3);
        if(s2 == "previous") 
        {
            m[s1].second = m[s1].first - m[s4].first;
            if(m[s1].second >= 0) m[s1].second -= 12;
            m[s1].second += m[s4].second;
        }
        else 
        {
            m[s1].second = m[s1].first - m[s4].first;
            if(m[s1].second <= 0) m[s1].second += 12;
            m[s1].second += m[s4].second;
        }
        if(s1 == "Elsie")cout << abs(m[s1].second);
    }
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