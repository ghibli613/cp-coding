#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isMatch(string virus, string dna)
{
    for(int i = 0; i < (int)virus.size() - (int)dna.size() + 1; i++)
    {
        bool stillMatch = true;
        for(int j = 0; j < (int)dna.size(); j++)
        {
            if(virus[i + j] == dna[j] || dna[j] == '*')
            {
                continue;
            }
            else
            {
                stillMatch = false;
            }
        }
        if(stillMatch) return true;
    }
    return false;
}

void solve(int tc)
{
    int n; cin >> n;
    vector<string> prohibited_dna(n);
    for(int i = 0; i < n; i++) cin >> prohibited_dna[i];
    int m; cin >> m;
    vector<string> virus(m);
    for(int i = 0; i < m; i++) cin >> virus[i];
    cout << "Data set #" << tc + 1 << ":\n";
    for(int i = 0; i < m; i++)
    {
        cout << "Virus #" << i + 1 << ": ";
        bool isLegal = false;
        for(int j = 0; j < n; j++)
        {
            if(isMatch(virus[i], prohibited_dna[j]))
            {    
                isLegal = true;
                break;
            }
        }
        if(isLegal)
            cout << "Nuts. This virus is illegal in Hawaii!\n";
        else
            cout << "Cool! Victor can take it with him!\n";
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc);

    return 0;
}