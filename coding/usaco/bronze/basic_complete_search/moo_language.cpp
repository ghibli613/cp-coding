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
    int t1 = 0, t2 = 0, combine = 0, tack_end = 0;
    for(int type_1 = 0; type_1 <= (int)iverb.size(); type_1++)
    {
    	int noun_cnt = (int)noun.size(), conj_cnt = (int)conj.size(), period = p, comma = c, cur_words = 0;

    	cur_words += 2 * type_1;
    	noun_cnt -= type_1;
    	if (noun_cnt < 0) break;

    	int type_2 = min({(int)tverb.size(), noun_cnt / 2, min(conj_cnt, period) * 2 + max(0, period - conj_cnt)});
    	cur_words += 3 * type_2;
    	noun_cnt -= 2 * type_2;

    	int total = type_1 + type_2;
    	int connections = type_1 + type_2 - 1;
    	int can_combine = min((connections + 1) / 2, conj_cnt);
    	cur_words += can_combine;

    	period -= total - can_combine;
    	if(period < 0) continue;

    	int tack = 0;
    	if (type_2 > 0)
    	{
    	 	tack = min(noun_cnt, comma);
    	 	cur_words += tack;
    	} 
    	if(cur_words > ans)
    	{
    		ans = cur_words;
    		combine = can_combine;
    		t1 = type_1;
    		t2 = type_2;
    		tack_end = tack;
    	}
    }

    cout << ans << '\n';

    if(ans == 0)
    {
    	cout << '\n';
    	return;
    }

    vector<vector<string>> sentences;
    for(int i = 0; i < t1; i++)
    {
    	sentences.push_back({noun.back(), iverb.back()});
    	noun.pop_back();
    	iverb.pop_back();
    }
    for(int i = 0; i < t2; i++)
    {
    	sentences.push_back({noun.back(), tverb.back()});
    	noun.pop_back();
    	tverb.pop_back();
    	sentences.back().push_back(noun.back());
    	noun.pop_back();
    }
   	
   	string output;
   	for(int i = 0; i < (int)sentences.size(); i++)
   	{
   		for(string j : sentences[i]) output += j + " ";
   		if(i % 1 == 0 && combine)
   		{
   			combine--;
   			output += conj.back() + " ";
   			conj.pop_back();
   		}
   		else
   		{
   			output.pop_back();
   			output += ". ";
   		}
   	}

   	output.pop_back();
	if(tack_end > 0)
	{
		output.pop_back();
		for(int i = 0; i < tack_end; i++)
		{
			output += ", " + noun.back();
			noun.pop_back();
		}
		output += ".";
	}
	cout << output << '\n';
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