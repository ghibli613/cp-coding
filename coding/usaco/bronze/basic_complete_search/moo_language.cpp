#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, c, p; cin >> n >> c >> p;
    vector<string> noun, tverb, iverb, conj;
    for(int i = 0; i < n; i++)
    {
    	string s, t;
    	cin >> s >> t;
    	if(t == "noun") noun.push_back(s);
    	else if(t == "transitive-verb") tverb.push_back(s);
    	else if(t == "intransitive-verb") iverb.push_back(s);
    	else conj.push_back(s);
    }

    int ans = 0;
    int t1, t2, combine, tack_end;
    for(int type_1 = 0; type_1 <= (int)iverb.size(); type_1++)
    {
    	int noun_cnt = (int)noun.size(), conj_cnt = (int)conj.size(), period = p, comma = c, cur_words = 0;

    	cur_words += 2 * type_1;
    	noun_cnt -= type_1;
    	if (noun_cnt < 0) break;

    	int type_2 = min({(int)tverb.size(), noun_cnt / 2, min(conj_cnt, period) * 2 + max(0, period - conj_cnt)});

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}