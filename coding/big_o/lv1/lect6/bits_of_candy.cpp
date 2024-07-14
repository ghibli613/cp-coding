#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string mm[16] = {"-", "Planters", "Reeses_Pieces", "-", "Sugar_Babies", "Pay_Day", "-", "-", "Hersheys", "Goobers", "Reeses_Cups", "Nutrageous", "Caramello", "Baby_Ruth", "Milky_Way", "Snickers"};

vector<string> split(string s, char c)
{
    vector<string> res;
    string tmp = "";
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == c)
        {
            res.push_back(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    res.push_back(tmp);
    return res;
}

int convert(string s)
{
    if(s[0] == '~')
    {
        return ~convert(s.substr(1, (int)s.size() - 1)) & 15;
    }
    else
    {
        for(int i = 0; i < 16; i++) 
        {
            if(mm[i] == s)
            {
                return i;
            }
        }
    }
    return 0;
}

void solve()
{
    string s; getline(cin, s);
    vector<string> vs = split(s, ' ');
    vector<int> ans;
    for(int i = 0; i < (int)vs.size(); i++)
    {
        if(vs[i] != "&" && vs[i] != "|")
        {
            ans.push_back(convert(vs[i]));
        }
        else if(vs[i] == "&")
        {
            i++;
            int num1 = ans.back(); ans.pop_back();
            ans.push_back(convert(vs[i]) & num1);
        }
    }

    int candy = 0;
    for(int i = 0; i < (int)ans.size(); i++) candy |= ans[i];
    
    for(int i = 0; i < 16; i++) 
        if(i == candy)
        {
            if(mm[i] == "-")
                cout << "Unknown candy bar!\n";
            else
                cout << mm[i] << '\n';
            return;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    
    cin.ignore();

    while(t--)
        solve();

    return 0;
}