#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    int t = stoi(s);
    getline(cin, s);
    while(t--)
    {
        getline(cin, s);
        double sum = 0;
        while(true)
        {
            getline(cin, s);
            if(s == "") break;
            // cout << s;
            vector<int> v;
            string tmp = "";
            s += " ";
            for(int i = 0; i < (int)s.size(); i++)
            {
                if(s[i] == ' ')
                {
                    v.push_back(stoi(tmp));
                    tmp = "";
                }
                else tmp.push_back(s[i]);
            }
            sum += sqrt(1ll * (v[0] - v[2]) * (v[0] - v[2]) + 1ll * (v[1] - v[3]) * (v[1] - v[3]) * 1ll);
        }
        sum = sum * 6 / 1000;

        if (sum - (int)sum >= 0.5) sum++;
        int h = (int)sum / 60;
        int m = (int)sum % 60;
        cout << h << ':';
        if(m < 10) cout << 0;
        cout << m << endl;
        if(t > 0)cout << endl;
    }

    return 0;
}